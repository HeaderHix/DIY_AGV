KG 카이로스 부트캠프 마지막 프로젝트에 쓰일 간단한 AGV 를 만들어 보았다

사용된 부품 : Rasberry pi 4B+, Arduino MEGA, 엔코더 모터, 18650 3.3v 배터리, 저렴한 웹켐 image image

![image](https://github.com/HeaderHix/DIY_AGV/assets/166344986/b3bfec3f-e537-40b3-9c7b-42e88f5435ba)


여러가지 문제점들이 많았지만 어떻게 만들어 졌는지 하나씩 써보려고한다.

1 ~

여러가지 센서를 부착할 가능성이 있고, ROS 쓸 수 있다는 가정하에 rasbian 보다 Ubuntu 20.04를 설치하고자 했다.

라즈베리파이 OS를 설치할 때에, Ubuntu 20.04 Server 를 먼저 설치했다. ( desktop 버전이 없어서, 라즈비안 버전 bookworm 에서는 ROS가 설치되지 않은 문제도 있었다.)

https://blog.naver.com/roboholic84/221701573539 위의 사이트를 참고하여 우분투를 설치 하였다.

2 ~

파이썬 설치, 필요한 개발 환경 만들기에서 Arduino IDE 2.0 을 설치하고자 했으나 안타깝게도 ARM64 에서는 1.0 version 만 설치가 가능했다. ( Arduino 1.0 ver 은 글씨가 이상하게 보여서 눈이 아팠기 때문에 .. )

https://github.com/koendv/arduino-ide-raspberrypi
https://forum.arduino.cc/t/install-2-2-on-rasberry-pi-4-raspberry-pi-64bit-os/1034417
관련 링크이다. 설치가 가능은 하다고 나왔는데 나와있는 대로 따라해도 라즈베리파이 우분투에 설치가 제대로 되지 않았다. 해서,

VSCODE 에 arduino ide 를 설치하여 개발을 하고자 했다.

image

개발 과정에서 include path 문제가 생겨서

https://ttuk-ttak.tistory.com/31 2)https://conceptbug.tistory.com/entry/macOS-%EC%95%84%EB%91%90%EC%9D%B4%EB%85%B8-IDE%EB%A5%BC-VSCode%EB%A1%9C-%EB%8C%80%EC%B2%B4%ED%95%98%EA%B8%B0
위의 링크들을 참고해서 include path 문제를 해결 하였다.

3 ~ gnome-terminal 과 vscode가 사용하는 python version 이 달랐기 때문에 이를 맞춰 주었다.

https://inistory.tistory.com/180

위의 링크를 참고해서 python version 을 같게 만들어 줬다.

4 ~ 다행히도 아두이노 메가 쉴드와 모터가 한 세트였기 때문에 쉴드를 만든 회사에서 주는 예제 코드가 있었다. 하지만 엔코더값을 측정하는 코드는 없었고 직접 만들어야 했다.

image

image

image

변수타입을 volatile int 로 선언 해서 간단하게 인터럽트를 사용했고, 같은 방향이면 변수에 더해주고, 반대방향이면 빼주는것으로 하였다.

5 ~

처음 전원이 라즈베리파이에 들어가게 되면 바로 python - opencv 를 통해 바닥에 있는 길을 인식하고 Pyserial을 통해 실시간으로 라즈베리파이가 아두이노 메가에 명령을 주어 라인을 따라가게 하고자 하였다.
opencv 의 사용이 숙련되지 않았기 때문에 GPT 를 활용해서 코드를 짜보았다.

하지만 데이터 처리에 문제가 생긴것 같아 실시간 영상이 제대로 구현되지 않았고, 넘어가는 명령도 제대로 인식이 되지않아 엄청 끊기는 현상이 발견되었다. image

그래서 timeout = 0.1 을 넣어서 시리얼이 끊기는것에 어느정도 유예시간을 주었고 Python thread 모듈을 사용하여 실행되는 함수에 나름의 우선순위를 정하였다. ( 정확히는 우선순위가 아니라 " 전역변수 " centroid 에 대한 주도권을 thread lock, time sleep 을 써서 정하였다.)

image

하지만 이렇게 해도 문제는 해결되지 않았는데, 구글링을 해보고 GPT 한테도 물어본 결과 명령을 보내는 부분에서 버퍼가 쌓여서 끊기는 현상이 생기고 있다고 생각했다. 그래서 python 코드에 명령을 한번 보내면 버퍼 자체를 초기화 시키는 코드 한줄을 넣었더니 끊기지 않고 정상적으로 작동 되는 모습을 볼 수 있었다.

image

KakaoTalk_20240609_140755313_01 KakaoTalk_20240609_140755313
