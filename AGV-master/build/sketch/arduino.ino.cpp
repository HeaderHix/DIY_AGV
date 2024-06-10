#include <Arduino.h>
#line 1 "/home/user/arduino/arduino.ino"
// //#include <Encoder.h>

// // Encoder 인스턴스
// // Encoder encoderA(18, 31);
// // Encoder encoderB(19, 38);
// // Encoder encoderC(3, 49);
// // Encoder encoderD(2, 23);

// // 전역 변수 선언
// volatile int pulseCounterA = 0;
// volatile int pulseCounterB = 0;
// volatile int pulseCounterC = 0;
// volatile int pulseCounterD = 0;

// unsigned long lastMeasurement;

// #define PWMA 12
// #define DIRA1 34
// #define DIRA2 35

// #define PWMB 8
// #define DIRB1 37
// #define DIRB2 36

// #define PWMC 6
// #define DIRC1 43
// #define DIRC2 42

// #define PWMD 5
// #define DIRD1 A4
// #define DIRD2 A5

// #define MAX_PWM 200
// #define MIN_PWM 10
// int Motor_PWM = 10;

// // 모터 제어 매크로
// #define MOTORA_FORWARD(pwm)    do{digitalWrite(DIRA1, LOW); digitalWrite(DIRA2, HIGH); analogWrite(PWMA, pwm); delay(1100);}while(0)
// #define MOTORA_STOP()          do{digitalWrite(DIRA1, LOW); digitalWrite(DIRA2, LOW); analogWrite(PWMA, 0);delay(1100);}while(0)
// #define MOTORA_BACKOFF(pwm)    do{digitalWrite(DIRA1, HIGH); digitalWrite(DIRA2, LOW); analogWrite(PWMA, pwm);delay(1100);}while(0)

// #define MOTORB_FORWARD(pwm)    do{digitalWrite(DIRB1, HIGH); digitalWrite(DIRB2, LOW); analogWrite(PWMB, pwm);delay(1100);}while(0)
// #define MOTORB_STOP()          do{digitalWrite(DIRB1, LOW); digitalWrite(DIRB2, LOW); analogWrite(PWMB, 0);delay(1100);}while(0)
// #define MOTORB_BACKOFF(pwm)    do{digitalWrite(DIRB1, LOW); digitalWrite(DIRB2, HIGH); analogWrite(PWMB, pwm);delay(1100);}while(0)

// #define MOTORC_FORWARD(pwm)    do{digitalWrite(DIRC1, LOW); digitalWrite(DIRC2, HIGH); analogWrite(PWMC, pwm);delay(1100);}while(0)
// #define MOTORC_STOP()          do{digitalWrite(DIRC1, LOW); digitalWrite(DIRC2, LOW); analogWrite(PWMC, 0);delay(1100);}while(0)
// #define MOTORC_BACKOFF(pwm)    do{digitalWrite(DIRC1, HIGH); digitalWrite(DIRC2, LOW); analogWrite(PWMC, pwm);delay(1100);}while(0)

// #define MOTORD_FORWARD(pwm)    do{digitalWrite(DIRD1, HIGH); digitalWrite(DIRD2, LOW); analogWrite(PWMD, pwm);delay(1100);}while(0)
// #define MOTORD_STOP()          do{digitalWrite(DIRD1, LOW); digitalWrite(DIRD2, LOW); analogWrite(PWMD, 0);delay(1100);}while(0)
// #define MOTORD_BACKOFF(pwm)    do{digitalWrite(DIRD1, LOW); digitalWrite(DIRD2, HIGH); analogWrite(PWMD, pwm);delay(1100);}while(0)

// #define SERIAL  Serial

// #define LOG_DEBUG

// #ifdef LOG_DEBUG
// #define M_LOG SERIAL.print
// #else
// #define M_LOG
// #endif

// void ADVANCE() {
//   MOTORA_FORWARD(Motor_PWM); MOTORB_FORWARD(Motor_PWM);
//   MOTORC_FORWARD(Motor_PWM); MOTORD_FORWARD(Motor_PWM);
// }

// void BACK() {
//   MOTORA_BACKOFF(Motor_PWM); MOTORB_BACKOFF(Motor_PWM);
//   MOTORC_BACKOFF(Motor_PWM); MOTORD_BACKOFF(Motor_PWM);
// }

// void LEFT_1() {
//   MOTORA_STOP(); MOTORB_FORWARD(Motor_PWM);
//   MOTORC_FORWARD(Motor_PWM); MOTORD_STOP();
// }

// void LEFT_2() {
//   MOTORA_BACKOFF(Motor_PWM); MOTORB_FORWARD(Motor_PWM);
//   MOTORC_FORWARD(Motor_PWM); MOTORD_BACKOFF(Motor_PWM);
// }

// void LEFT_3() {
//   MOTORA_BACKOFF(Motor_PWM); MOTORB_STOP();
//   MOTORC_STOP(); MOTORD_BACKOFF(Motor_PWM);
// }

// void RIGHT_1() {
//   MOTORA_FORWARD(Motor_PWM); MOTORB_STOP();
//   MOTORC_STOP(); MOTORD_FORWARD(Motor_PWM);
// }

// void RIGHT_2() {
//   MOTORA_FORWARD(Motor_PWM); MOTORB_BACKOFF(Motor_PWM);
//   MOTORC_BACKOFF(Motor_PWM); MOTORD_FORWARD(Motor_PWM);
// }

// void RIGHT_3() {
//   MOTORA_STOP(); MOTORB_BACKOFF(Motor_PWM);
//   MOTORC_BACKOFF(Motor_PWM); MOTORD_STOP();
// }

// void STOP() {
//   MOTORA_STOP(); MOTORB_STOP();
//   MOTORC_STOP(); MOTORD_STOP();
// }

// void UART_Control() {
//   if (Serial.available()) {
//     char Uart_Data = SERIAL.read();
//     switch (Uart_Data) {
//       case 'A':  ADVANCE(); M_LOG("Run!\r\n"); break;
//       case 'B':  RIGHT_1();  M_LOG("Right up!\r\n"); break;
//       case 'C':  RIGHT_2();  M_LOG("Right!\r\n"); break;
//       case 'D':  RIGHT_3();  M_LOG("Right down!\r\n"); break;
//       case 'E':  BACK(); M_LOG("Run!\r\n"); break;
//       case 'F':  LEFT_3(); M_LOG("Left down!\r\n"); break;
//       case 'G':  LEFT_2(); M_LOG("Left!\r\n"); break;
//       case 'H':  LEFT_1(); M_LOG("Left up!\r\n"); break;
//       case 'Z':  STOP(); M_LOG("Stop!\r\n"); break;
//       case 'L':  Motor_PWM = 50; break;
//       case 'M':  Motor_PWM = 1; break;
//       case '1':  Motor_PWM = 10; M_LOG("PWM set to 10\r\n"); break;
//       case '2':  Motor_PWM = 20; M_LOG("PWM set to 20\r\n"); break;
//       case '3':  Motor_PWM = 30; M_LOG("PWM set to 30\r\n"); break;
//       case '4':  Motor_PWM = 40; M_LOG("PWM set to 40\r\n"); break;
//       case '5':  Motor_PWM = 50; M_LOG("PWM set to 50\r\n"); break;
//       case '6':  Motor_PWM = 60; M_LOG("PWM set to 60\r\n"); break;
//       case '7':  Motor_PWM = 70; M_LOG("PWM set to 70\r\n"); break;
//       case '8':  Motor_PWM = 80; M_LOG("PWM set to 80\r\n"); break;
//       case '9':  Motor_PWM = 90; M_LOG("PWM set to 90\r\n"); break;
//       case '0':  Motor_PWM = 100; M_LOG("PWM set to 100\r\n"); break;
//     }
//   }
// }

// void IO_init() {
//   pinMode(PWMA, OUTPUT);
//   pinMode(DIRA1, OUTPUT); pinMode(DIRA2, OUTPUT);
//   pinMode(PWMB, OUTPUT);
//   pinMode(DIRB1, OUTPUT); pinMode(DIRB2, OUTPUT);
//   pinMode(PWMC, OUTPUT);
//   pinMode(DIRC1, OUTPUT); pinMode(DIRC2, OUTPUT);
//   pinMode(PWMD, OUTPUT);
//   pinMode(DIRD1, OUTPUT); pinMode(DIRD2, OUTPUT);

//   pinMode(18, INPUT); pinMode(31, INPUT); // MOTORA
//   pinMode(19, INPUT); pinMode(38, INPUT); // MOTORB
//   pinMode(3, INPUT); pinMode(49, INPUT); // MOTORC
//   pinMode(2, INPUT); pinMode(23, INPUT); // MOTORD

//   attachInterrupt(digitalPinToInterrupt(18), countPulseA, RISING);
//   attachInterrupt(digitalPinToInterrupt(19), countPulseB, RISING);
//   attachInterrupt(digitalPinToInterrupt(3), countPulseC, RISING);
//   attachInterrupt(digitalPinToInterrupt(2), countPulseD, RISING);

//   pulseCounterA = 0;
//   pulseCounterB = 0;
//   pulseCounterC = 0;
//   pulseCounterD = 0;

//   lastMeasurement = millis();
//   STOP();
// }

// void setup() {
//   Serial.begin(9600);
//   IO_init();
// }

// void loop() {
//   UART_Control();
//   unsigned long currentMillis = millis();
//   if (currentMillis - lastMeasurement >= 1100) {
//     noInterrupts();
//     int countA = pulseCounterA;
//     int countB = pulseCounterB;
//     int countC = pulseCounterC;
//     int countD = pulseCounterD;

//     pulseCounterA = 0;
//     pulseCounterB = 0;
//     pulseCounterC = 0;
//     pulseCounterD = 0;
//     interrupts();

//     float speedA = (float)countA / 20.0;
//     float speedB = (float)countB / 20.0;
//     float speedC = (float)countC / 20.0;
//     float speedD = (float)countD / 20.0;
//     Serial.print("Speed_A : ");
//     Serial.print(speedA, 2);
//     Serial.print(" Speed_B : ");
//     Serial.print(speedB, 2);
//     Serial.print(" Speed_C : ");
//     Serial.print(speedC, 2);
//     Serial.print(" Speed_D : ");
//     Serial.print(speedD, 2);
//     Serial.println(" ");
//     lastMeasurement = currentMillis;
//   }
// }

// void countPulseA() {
//   pulseCounterA += (digitalRead(enc_motorAB) == HIGH) ? 1 : -1;
// }

// void countPulseB() {
//   pulseCounterB += (digitalRead(enc_motorBB) == HIGH) ? 1 : -1;
// }

// void countPulseC() {
//   pulseCounterC += (digitalRead(enc_motorCB) == HIGH) ? 1 : -1;
// }

// void countPulseD() {
//   pulseCounterD += (digitalRead(enc_motorDB) == HIGH) ? 1 : -1;
// }



// #include <Encoder.h>

// Encoder encoderA(18, 31);
// Encoder encoderB(19, 38);
// Encoder encoderC(3, 49);
// Encoder encoderD(2, 23);

//电机引脚
//ENCODER_A 18
//ENCODER_B 31
// encoder variable

volatile int pulseCounterA;
volatile int pulseCounterB;
volatile int pulseCounterC;
volatile int pulseCounterD;

unsigned long lastMeasurement;

#define PWMA 12    //A电机转速 --> PB6
#define DIRA1 34  // --> PC3 
#define DIRA2 35  //A电机方向 --> PC2
const int enc_motorAA = 18;
const int enc_motorAB = 31;

//ENCODER_A 19
//ENCODER_B 38
#define PWMB 8    //B电机转速 
#define DIRB1 37 
#define DIRB2 36  //B电机方向
const int enc_motorBA = 19;
const int enc_motorBB = 36;


//ENCODER_A 3
//ENCODER_B 49
#define PWMC 6   //C电机转速  pin 9 change pin 6
#define DIRC1 43 
#define DIRC2 42  //C电机方向
const int enc_motorCA = 3;
const int enc_motorCB = 49;


//ENCODER_A 2
//ENCODER_B 23
#define PWMD 5    //D电机转速
#define DIRD1 A4  //26  
#define DIRD2 A5  //27  //D电机方向
const int enc_motorDA = 2;
const int enc_motorDB = 23;


// MOTORA --> 뾰족하게 나온 기준 11시로
// 7시방향 모터
#define MOTORA_FORWARD(pwm)    do{digitalWrite(DIRA1,LOW); digitalWrite(DIRA2,HIGH);analogWrite(PWMA,pwm);}while(0)
#define MOTORA_STOP(x)         do{digitalWrite(DIRA1,LOW); digitalWrite(DIRA2,LOW); analogWrite(PWMA,0);}while(0)
#define MOTORA_BACKOFF(pwm)    do{digitalWrite(DIRA1,HIGH);digitalWrite(DIRA2,LOW); analogWrite(PWMA,pwm);}while(0)

// 이부분은 모터 앞으로 가는 방향으로 맞추기 위해서 HIGH, LOW 순서를 바꿨음 MOTORB --> 뾰족하게 나온 기준 12시로
// 1시방향 모터
#define MOTORB_FORWARD(pwm)    do{digitalWrite(DIRB1,HIGH); digitalWrite(DIRB2,LOW);analogWrite(PWMB,pwm);}while(0)
#define MOTORB_STOP(x)         do{digitalWrite(DIRB1,LOW); digitalWrite(DIRB2,LOW); analogWrite(PWMB,0);}while(0)
#define MOTORB_BACKOFF(pwm)    do{digitalWrite(DIRB1,LOW);digitalWrite(DIRB2,HIGH); analogWrite(PWMB,pwm);}while(0)



// MOTORC --> 뾰족하게 나온 기준 12시로
// 7시방향 모터
#define MOTORC_FORWARD(pwm)    do{digitalWrite(DIRC1,LOW); digitalWrite(DIRC2,HIGH);analogWrite(PWMC,pwm);}while(0)
#define MOTORC_STOP(x)         do{digitalWrite(DIRC1,LOW); digitalWrite(DIRC2,LOW); analogWrite(PWMC,0);}while(0)
#define MOTORC_BACKOFF(pwm)    do{digitalWrite(DIRC1,HIGH);digitalWrite(DIRC2,LOW); analogWrite(PWMC,pwm);}while(0)

// 이부분은 모터 앞으로 가는 방향으로 맞추기 위해서 HIGH, LOW 순서를 바꿨음 MOTORD --> 뾰족하게 나온 기준 12시로
// 5시방향 모터
#define MOTORD_FORWARD(pwm)    do{digitalWrite(DIRD1,HIGH); digitalWrite(DIRD2,LOW);analogWrite(PWMD,pwm);}while(0)
#define MOTORD_STOP(x)         do{digitalWrite(DIRD1,LOW); digitalWrite(DIRD2,LOW); analogWrite(PWMD,0);}while(0)
#define MOTORD_BACKOFF(pwm)    do{digitalWrite(DIRD1,LOW);digitalWrite(DIRD2,HIGH); analogWrite(PWMD,pwm);}while(0)

#define SERIAL  Serial

#define LOG_DEBUG

#ifdef LOG_DEBUG
#define M_LOG SERIAL.print
#else
#define M_LOG 
#endif

#define MAX_PWM   200
#define MIN_PWM   100
int Motor_PWM = 50;


// Encoder encoderA(18, 31);
// Encoder encoderB(19, 38);
// Encoder encoderC(3, 49);
// Encoder encoderD(2, 23);

//控制电机运动    宏定义

//    ↑A-----B↑   
//     |  ↑  |
//     |  |  |
//    ↑C-----D↑
#line 327 "/home/user/arduino/arduino.ino"
void ADVANCE();
#line 338 "/home/user/arduino/arduino.ino"
void BACK();
#line 348 "/home/user/arduino/arduino.ino"
void LEFT_1();
#line 359 "/home/user/arduino/arduino.ino"
void LEFT_2();
#line 369 "/home/user/arduino/arduino.ino"
void LEFT_3();
#line 379 "/home/user/arduino/arduino.ino"
void RIGHT_1();
#line 389 "/home/user/arduino/arduino.ino"
void RIGHT_2();
#line 399 "/home/user/arduino/arduino.ino"
void RIGHT_3();
#line 409 "/home/user/arduino/arduino.ino"
void STOP();
#line 414 "/home/user/arduino/arduino.ino"
void UART_Control();
#line 437 "/home/user/arduino/arduino.ino"
void IO_init();
#line 470 "/home/user/arduino/arduino.ino"
void setup();
#line 479 "/home/user/arduino/arduino.ino"
void loop();
#line 520 "/home/user/arduino/arduino.ino"
void countPulseA();
#line 530 "/home/user/arduino/arduino.ino"
void countPulseB();
#line 541 "/home/user/arduino/arduino.ino"
void countPulseC();
#line 551 "/home/user/arduino/arduino.ino"
void countPulseD();
#line 327 "/home/user/arduino/arduino.ino"
void ADVANCE()
{
  MOTORA_FORWARD(Motor_PWM);MOTORB_FORWARD(Motor_PWM);    
  MOTORC_FORWARD(Motor_PWM);MOTORD_FORWARD(Motor_PWM);    
  _delay_ms(500);
}

//    ↓A-----B↓   
//     |  |  |
//     |  ↓  |
//    ↓C-----D↓
void BACK()
{
  MOTORA_BACKOFF(Motor_PWM);MOTORB_BACKOFF(Motor_PWM);
  MOTORC_BACKOFF(Motor_PWM);MOTORD_BACKOFF(Motor_PWM);

}
//    =A-----B↑   
//     |   ↖ |
//     | ↖   |
//    ↑C-----D=
void LEFT_1()
{
  MOTORA_STOP(Motor_PWM);MOTORB_FORWARD(Motor_PWM);
  MOTORC_FORWARD(Motor_PWM);MOTORD_STOP(Motor_PWM);

}

//    ↓A-----B↑   
//     |  ←  |
//     |  ←  |
//    ↑C-----D↓
void LEFT_2()
{
  MOTORA_BACKOFF(Motor_PWM);MOTORB_FORWARD(Motor_PWM);
  MOTORC_FORWARD(Motor_PWM);MOTORD_BACKOFF(Motor_PWM);

}
//    ↓A-----B=   
//     | ↙   |
//     |   ↙ |
//    =C-----D↓
void LEFT_3()
{
  MOTORA_BACKOFF(Motor_PWM);MOTORB_STOP(Motor_PWM);
  MOTORC_STOP(Motor_PWM);MOTORD_BACKOFF(Motor_PWM);

}
//    ↑A-----B=   
//     | ↗   |
//     |   ↗ |
//    =C-----D↑
void RIGHT_1()
{
  MOTORA_FORWARD(Motor_PWM);MOTORB_STOP(Motor_PWM);
  MOTORC_STOP(Motor_PWM);MOTORD_FORWARD(Motor_PWM);

}
//    ↑A-----B↓   
//     |  →  |
//     |  →  |
//    ↓C-----D↑
void RIGHT_2()
{
  MOTORA_FORWARD(Motor_PWM);MOTORB_BACKOFF(Motor_PWM);
  MOTORC_BACKOFF(Motor_PWM);MOTORD_FORWARD(Motor_PWM);

}
//    =A-----B↓   
//     |   ↘ |
//     | ↘   |
//    ↓C-----D=
void RIGHT_3()
{
  MOTORA_STOP(Motor_PWM);MOTORB_BACKOFF(Motor_PWM);
  MOTORC_BACKOFF(Motor_PWM);MOTORD_STOP(Motor_PWM);

}
//    =A-----B=  
//     |  =  |
//     |  =  |
//    =C-----D=
void STOP()
{
  MOTORA_STOP(Motor_PWM);MOTORB_STOP(Motor_PWM);
  MOTORC_STOP(Motor_PWM);MOTORD_STOP(Motor_PWM);
}
void UART_Control()
{
  char Uart_Date=0;
 if(Serial.available())
  {
   Uart_Date = SERIAL.read();

  }
  switch(Uart_Date)
  {
     case 'A':  ADVANCE(); M_LOG("Run!\r\n");        break;
     case 'B':  RIGHT_1();  M_LOG("Right up!\r\n");     break;
     case 'C':  RIGHT_2();  M_LOG("Right!\r\n");        break;
     case 'D':  RIGHT_3();  M_LOG("Right down!\r\n");   break;
     case 'E':  BACK();     M_LOG("Run!\r\n");        break;
     case 'F':  LEFT_3();   M_LOG("Left down!\r\n");    break;
     case 'G':  LEFT_2();   M_LOG("Left!\r\n");       break;
     case 'H':  LEFT_1();   M_LOG("Left up!\r\n");  break;
     case 'Z':  STOP();     M_LOG("Stop!\r\n");       break;
     case 'L':  Motor_PWM = 150;                      break;
     case 'M':  Motor_PWM = 100;                       break;
   }
}
void IO_init()
{
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA1, OUTPUT);pinMode(DIRA2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB1, OUTPUT);pinMode(DIRB2, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(DIRC1, OUTPUT);pinMode(DIRC2, OUTPUT);
  pinMode(PWMD, OUTPUT);
  pinMode(DIRD1, OUTPUT);pinMode(DIRD2, OUTPUT);
  // encoder pin setup
  pinMode(enc_motorAA, INPUT);pinMode(enc_motorAB, INPUT); // MOTORA
  pinMode(enc_motorBA, INPUT);pinMode(enc_motorBB, INPUT); // MOTORB
  pinMode(enc_motorCA, INPUT);pinMode(enc_motorCB, INPUT); // MOTORC
  pinMode(enc_motorDA, INPUT);pinMode(enc_motorDB, INPUT); // MOTORD
  attachInterrupt(digitalPinToInterrupt(enc_motorAA), countPulseA, RISING);
  attachInterrupt(digitalPinToInterrupt(enc_motorBA), countPulseB, RISING);
  attachInterrupt(digitalPinToInterrupt(enc_motorCA), countPulseC, RISING);
  attachInterrupt(digitalPinToInterrupt(enc_motorDA), countPulseD, RISING);

  pulseCounterA = 0;
  pulseCounterB = 0;
  pulseCounterC = 0;
  pulseCounterD = 0;

  lastMeasurement = millis();
  // pinMode(18, INPUT); pinMode(31, INPUT);//MOTORA 
  // pinMode(19, INPUT); pinMode(38, INPUT);//MOTORB
  // pinMode(3,  INPUT); pinMode(49, INPUT);//MOTORC
  // pinMode(2,  INPUT); pinMode(23, INPUT);//MOTORD

  STOP();
}
void setup()
{

  Serial.begin(9600);
  IO_init();
  
//  SERIAL.print("Start");
}

void loop()
{

  UART_Control();//串口接收处理 
  //CAR_Control();//小车控制
  unsigned long currentMillis = millis();
  if(currentMillis - lastMeasurement >= 300)
  {
    noInterrupts();
    int countA = pulseCounterA;
    int countB = pulseCounterB;
    int countC = pulseCounterC;
    int countD = pulseCounterD;

    pulseCounterA = 0;
    pulseCounterB = 0;
    pulseCounterC = 0;
    pulseCounterD = 0;

    interrupts();

    float speedA = (float)countA / 5.0;
    float speedB = (float)countB / 5.0;
    float speedC = (float)countC / 5.0;
    float speedD = (float)countD / 5.0;
    Serial.print("Speed_A : " );
    Serial.print(speedA, 2);
    Serial.print("Speed_B : " );
    Serial.print(speedB, 2);
    Serial.print("Speed_C : ");
    Serial.print(speedC, 2);
    Serial.print("Speed_D : ");
    Serial.print(speedD, 2);
    Serial.println(" ");
    lastMeasurement = currentMillis;
  }


}


void countPulseA()
{
  if(digitalRead(enc_motorAB) == HIGH)
  {
   pulseCounterA ++;
  }
  else {
    pulseCounterA --;
  }
}
void countPulseB()
{
  if(digitalRead(enc_motorBB) == HIGH)
  {
   pulseCounterB ++;
  }
  else {
    pulseCounterB --;
  }
}

void countPulseC()
{
  if(digitalRead(enc_motorCB) == HIGH)
  {
   pulseCounterC ++;
  }
  else {
    pulseCounterC --;
  }
}
void countPulseD()
{
  if(digitalRead(enc_motorDB) == HIGH)
  {
   pulseCounterD ++;
  }
  else {
    pulseCounterD --;
  }
}

