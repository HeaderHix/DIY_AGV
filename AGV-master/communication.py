import cv2
import numpy as np
import serial
import time
from threading import Thread, Lock

cam_pri = 0.5
motor_pri = 1.0
centroid = None
centroid_lock = Lock()

pyserial = serial.Serial(
    port='/dev/ttyACM0',
    baudrate=9600,
    timeout=0.1
)

def find_centroid(image):
    global centroid
    contours, _ = cv2.findContours(image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    for contour in contours:
        area = cv2.contourArea(contour)
        if area > 100:
            x, y, w, h = cv2.boundingRect(contour)
            cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
            M = cv2.moments(contour)
            if M["m00"] != 0:
                cx = int(M["m10"] / M["m00"])
                cy = int(M["m01"] / M["m00"])
                with centroid_lock:
                    centroid = (cx, cy)
    return None

def webcam_stream():
    webcam = cv2.VideoCapture(0)
    global centroid

    if not webcam.isOpened():
        print("웹캠을 열 수 없습니다.")
        return

    while True:
        ret, frame = webcam.read()
        if not ret:
            print("프레임을 읽을 수 없습니다.")
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        _, binary = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY_INV)
        cv2.imshow('line', binary)
       
        find_centroid(binary)

        time.sleep(cam_pri*0.02)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    webcam.release()
    cv2.destroyAllWindows()

def motor_comm():
    global centroid
    screen_center = 320  # 예를 들어 화면 가로 길이가 640픽셀이라고 가정
    tolerance = 50       # 중심에서 얼마나 벗어났는지를 판단하는 허용치

    while True:
        with centroid_lock:
            if centroid is not None:
                print("무게 중심 위치:", centroid)
                cx, cy = centroid

                if cx < (screen_center - tolerance):
                    # 왼쪽으로 기울어짐
                    if cx < screen_center - 3 * tolerance:
                        pyserial.write('H'.encode())  # 왼쪽 크게 기울기
                    elif cx < screen_center - 2 * tolerance:
                        pyserial.write('G'.encode())  # 왼쪽 중간 기울기
                    else:
                        pyserial.write('F'.encode())  # 왼쪽 약간 기울기
                elif cx > (screen_center + tolerance):
                    # 오른쪽으로 기울어짐
                    if cx > screen_center + 3 * tolerance:
                        pyserial.write('B'.encode())  # 오른쪽 크게 기울기
                    elif cx > screen_center + 2 * tolerance:
                        pyserial.write('C'.encode())  # 오른쪽 중간 기울기
                    else:
                        pyserial.write('D'.encode())  # 오른쪽 약간 기울기
                else:
                    pyserial.write('A'.encode())  # 직진

                pyserial.flush()
        time.sleep(motor_pri* 0.8)

if __name__ == "__main__":
    w1 = Thread(target=webcam_stream)
    w2 = Thread(target=motor_comm)

    w1.start()
    w2.start()
   
    w1.join()
    w2.join()
