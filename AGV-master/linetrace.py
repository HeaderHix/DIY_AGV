import cv2
import numpy as np
import serial
import time

def find_centroid(image):
    # 이미지를 그레이 스케일로 변환합니다.
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # 이미지를 이진화합니다.
    _, binary = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY_INV)  # THRESH_BINARY_INV를 사용하여 흑백 반전

    # 이진화된 이미지를 화면에 출력합니다.
    cv2.imshow('Binary', binary)
               

    # 이진화된 이미지에서 윤곽선을 찾습니다.
    contours, _ = cv2.findContours(binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # 윤곽선 중 검은색 선을 찾습니다.
    for contour in contours:
        # 윤곽선의 면적을 계산합니다.
        area = cv2.contourArea(contour)

        # 면적이 일정 크기 이상인 윤곽선만 고려합니다.
        if area > 100:
            # 윤곽선을 감싸는 사각형을 그립니다.
            x, y, w, h = cv2.boundingRect(contour)
            cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)

            # 윤곽선의 무게 중심을 계산합니다.
            M = cv2.moments(contour)
            if M["m00"] != 0:
                cx = int(M["m10"] / M["m00"])
                cy = int(M["m01"] / M["m00"])
                return (cx, cy)

    return None

def main():
    # 웹캠을 엽니다.
    webcam = cv2.VideoCapture(0)
    pyserial = serial.Serial(
        port='/dev/ttyACM0',
        baudrate=9600,
        timeout=1
    )

    # 웹캠이 정상적으로 열렸는지 확인합니다.
    if not webcam.isOpened():
        print("웹캠을 열 수 없습니다.")
        return

    # PWM 주기와 듀티 사이클 설정
    pwm_period = 1000  # PWM 주기
    slow_speed_duty_cycle = 200  # 느린 속도를 위한 듀티 사이클
    fast_speed_duty_cycle = 800  # 빠른 속도를 위한 듀티 사이클

    # 기본적으로 모터를 느린 속도로 설정합니다.
    pyserial.write(f'P{pwm_period}D{slow_speed_duty_cycle}\n'.encode())

    while True:
        # 웹캠에서 프레임을 읽어옵니다.
        ret, frame = webcam.read()

        # 프레임을 성공적으로 읽어왔는지 확인합니다.
        if not ret:
            print("프레임을 읽을 수 없습니다.")
            break

        # 무게 중심을 찾습니다.
        centroid = find_centroid(frame)

        # 무게 중심을 찾았으면 그 위치를 출력하고 특정 범위 내에 있을 때 모터를 앞으로 움직이게 합니다.
        if centroid is not None:
            print("무게 중심 위치:", centroid)
            # 무게 중심이 x 좌표 330부터 360 사이에 있을 때 전진 명령을 전송합니다.
            if 300 <= centroid[0] <= 400:
                # 빠른 속도로 전진
                pyserial.write(f'P{pwm_period}D{fast_speed_duty_cycle}\n'.encode())
            else:
                # 느린 속도로 후진
                pyserial.write(f'P{pwm_period}D{slow_speed_duty_cycle}\n'.encode())
            time.sleep(0.1)  # 모터가 동작할 시간을 줍니다.

        # 'q' 키를 누르면 루프를 종료합니다.
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # 사용이 끝난 후에는 웹캠과 시리얼 포트를 해제합니다.
    webcam.release()
    pyserial.close()
    cv2.destroyAllWindows() 

if __name__ == "__main__":
    main()
