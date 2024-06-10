# 1 "/home/user/arduino/arduino.ino"
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




const int enc_motorAA = 18;
const int enc_motorAB = 31;

//ENCODER_A 19
//ENCODER_B 38



const int enc_motorBA = 19;
const int enc_motorBB = 36;


//ENCODER_A 3
//ENCODER_B 49



const int enc_motorCA = 3;
const int enc_motorCB = 49;


//ENCODER_A 2
//ENCODER_B 23



const int enc_motorDA = 2;
const int enc_motorDB = 23;


// MOTORA --> 뾰족하게 나온 기준 11시로
// 7시방향 모터




// 이부분은 모터 앞으로 가는 방향으로 맞추기 위해서 HIGH, LOW 순서를 바꿨음 MOTORB --> 뾰족하게 나온 기준 12시로
// 1시방향 모터






// MOTORC --> 뾰족하게 나온 기준 12시로
// 7시방향 모터




// 이부분은 모터 앞으로 가는 방향으로 맞추기 위해서 HIGH, LOW 순서를 바꿨음 MOTORD --> 뾰족하게 나온 기준 12시로
// 5시방향 모터
# 313 "/home/user/arduino/arduino.ino"
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
void ADVANCE()
{
  do{digitalWrite(34 /* --> PC3 */,0x0); digitalWrite(35 /*A电机方向 --> PC2*/,0x1);analogWrite(12 /*A电机转速 --> PB6*/,Motor_PWM);}while(0);do{digitalWrite(37,0x1); digitalWrite(36 /*B电机方向*/,0x0);analogWrite(8 /*B电机转速 */,Motor_PWM);}while(0);
  do{digitalWrite(43,0x0); digitalWrite(42 /*C电机方向*/,0x1);analogWrite(6 /*C电机转速  pin 9 change pin 6*/,Motor_PWM);}while(0);do{digitalWrite(A4 /*26  */,0x1); digitalWrite(A5 /*27  //D电机方向*/,0x0);analogWrite(5 /*D电机转速*/,Motor_PWM);}while(0);
  _delay_ms(500);
}

//    ↓A-----B↓   
//     |  |  |
//     |  ↓  |
//    ↓C-----D↓
void BACK()
{
  do{digitalWrite(34 /* --> PC3 */,0x1);digitalWrite(35 /*A电机方向 --> PC2*/,0x0); analogWrite(12 /*A电机转速 --> PB6*/,Motor_PWM);}while(0);do{digitalWrite(37,0x0);digitalWrite(36 /*B电机方向*/,0x1); analogWrite(8 /*B电机转速 */,Motor_PWM);}while(0);
  do{digitalWrite(43,0x1);digitalWrite(42 /*C电机方向*/,0x0); analogWrite(6 /*C电机转速  pin 9 change pin 6*/,Motor_PWM);}while(0);do{digitalWrite(A4 /*26  */,0x0);digitalWrite(A5 /*27  //D电机方向*/,0x1); analogWrite(5 /*D电机转速*/,Motor_PWM);}while(0);

}
//    =A-----B↑   
//     |   ↖ |
//     | ↖   |
//    ↑C-----D=
void LEFT_1()
{
  do{digitalWrite(34 /* --> PC3 */,0x0); digitalWrite(35 /*A电机方向 --> PC2*/,0x0); analogWrite(12 /*A电机转速 --> PB6*/,0);}while(0);do{digitalWrite(37,0x1); digitalWrite(36 /*B电机方向*/,0x0);analogWrite(8 /*B电机转速 */,Motor_PWM);}while(0);
  do{digitalWrite(43,0x0); digitalWrite(42 /*C电机方向*/,0x1);analogWrite(6 /*C电机转速  pin 9 change pin 6*/,Motor_PWM);}while(0);do{digitalWrite(A4 /*26  */,0x0); digitalWrite(A5 /*27  //D电机方向*/,0x0); analogWrite(5 /*D电机转速*/,0);}while(0);

}

//    ↓A-----B↑   
//     |  ←  |
//     |  ←  |
//    ↑C-----D↓
void LEFT_2()
{
  do{digitalWrite(34 /* --> PC3 */,0x1);digitalWrite(35 /*A电机方向 --> PC2*/,0x0); analogWrite(12 /*A电机转速 --> PB6*/,Motor_PWM);}while(0);do{digitalWrite(37,0x1); digitalWrite(36 /*B电机方向*/,0x0);analogWrite(8 /*B电机转速 */,Motor_PWM);}while(0);
  do{digitalWrite(43,0x0); digitalWrite(42 /*C电机方向*/,0x1);analogWrite(6 /*C电机转速  pin 9 change pin 6*/,Motor_PWM);}while(0);do{digitalWrite(A4 /*26  */,0x0);digitalWrite(A5 /*27  //D电机方向*/,0x1); analogWrite(5 /*D电机转速*/,Motor_PWM);}while(0);

}
//    ↓A-----B=   
//     | ↙   |
//     |   ↙ |
//    =C-----D↓
void LEFT_3()
{
  do{digitalWrite(34 /* --> PC3 */,0x1);digitalWrite(35 /*A电机方向 --> PC2*/,0x0); analogWrite(12 /*A电机转速 --> PB6*/,Motor_PWM);}while(0);do{digitalWrite(37,0x0); digitalWrite(36 /*B电机方向*/,0x0); analogWrite(8 /*B电机转速 */,0);}while(0);
  do{digitalWrite(43,0x0); digitalWrite(42 /*C电机方向*/,0x0); analogWrite(6 /*C电机转速  pin 9 change pin 6*/,0);}while(0);do{digitalWrite(A4 /*26  */,0x0);digitalWrite(A5 /*27  //D电机方向*/,0x1); analogWrite(5 /*D电机转速*/,Motor_PWM);}while(0);

}
//    ↑A-----B=   
//     | ↗   |
//     |   ↗ |
//    =C-----D↑
void RIGHT_1()
{
  do{digitalWrite(34 /* --> PC3 */,0x0); digitalWrite(35 /*A电机方向 --> PC2*/,0x1);analogWrite(12 /*A电机转速 --> PB6*/,Motor_PWM);}while(0);do{digitalWrite(37,0x0); digitalWrite(36 /*B电机方向*/,0x0); analogWrite(8 /*B电机转速 */,0);}while(0);
  do{digitalWrite(43,0x0); digitalWrite(42 /*C电机方向*/,0x0); analogWrite(6 /*C电机转速  pin 9 change pin 6*/,0);}while(0);do{digitalWrite(A4 /*26  */,0x1); digitalWrite(A5 /*27  //D电机方向*/,0x0);analogWrite(5 /*D电机转速*/,Motor_PWM);}while(0);

}
//    ↑A-----B↓   
//     |  →  |
//     |  →  |
//    ↓C-----D↑
void RIGHT_2()
{
  do{digitalWrite(34 /* --> PC3 */,0x0); digitalWrite(35 /*A电机方向 --> PC2*/,0x1);analogWrite(12 /*A电机转速 --> PB6*/,Motor_PWM);}while(0);do{digitalWrite(37,0x0);digitalWrite(36 /*B电机方向*/,0x1); analogWrite(8 /*B电机转速 */,Motor_PWM);}while(0);
  do{digitalWrite(43,0x1);digitalWrite(42 /*C电机方向*/,0x0); analogWrite(6 /*C电机转速  pin 9 change pin 6*/,Motor_PWM);}while(0);do{digitalWrite(A4 /*26  */,0x1); digitalWrite(A5 /*27  //D电机方向*/,0x0);analogWrite(5 /*D电机转速*/,Motor_PWM);}while(0);

}
//    =A-----B↓   
//     |   ↘ |
//     | ↘   |
//    ↓C-----D=
void RIGHT_3()
{
  do{digitalWrite(34 /* --> PC3 */,0x0); digitalWrite(35 /*A电机方向 --> PC2*/,0x0); analogWrite(12 /*A电机转速 --> PB6*/,0);}while(0);do{digitalWrite(37,0x0);digitalWrite(36 /*B电机方向*/,0x1); analogWrite(8 /*B电机转速 */,Motor_PWM);}while(0);
  do{digitalWrite(43,0x1);digitalWrite(42 /*C电机方向*/,0x0); analogWrite(6 /*C电机转速  pin 9 change pin 6*/,Motor_PWM);}while(0);do{digitalWrite(A4 /*26  */,0x0); digitalWrite(A5 /*27  //D电机方向*/,0x0); analogWrite(5 /*D电机转速*/,0);}while(0);

}
//    =A-----B=  
//     |  =  |
//     |  =  |
//    =C-----D=
void STOP()
{
  do{digitalWrite(34 /* --> PC3 */,0x0); digitalWrite(35 /*A电机方向 --> PC2*/,0x0); analogWrite(12 /*A电机转速 --> PB6*/,0);}while(0);do{digitalWrite(37,0x0); digitalWrite(36 /*B电机方向*/,0x0); analogWrite(8 /*B电机转速 */,0);}while(0);
  do{digitalWrite(43,0x0); digitalWrite(42 /*C电机方向*/,0x0); analogWrite(6 /*C电机转速  pin 9 change pin 6*/,0);}while(0);do{digitalWrite(A4 /*26  */,0x0); digitalWrite(A5 /*27  //D电机方向*/,0x0); analogWrite(5 /*D电机转速*/,0);}while(0);
}
void UART_Control()
{
  char Uart_Date=0;
 if(Serial.available())
  {
   Uart_Date = Serial.read();

  }
  switch(Uart_Date)
  {
     case 'A': ADVANCE(); Serial.print("Run!\r\n"); break;
     case 'B': RIGHT_1(); Serial.print("Right up!\r\n"); break;
     case 'C': RIGHT_2(); Serial.print("Right!\r\n"); break;
     case 'D': RIGHT_3(); Serial.print("Right down!\r\n"); break;
     case 'E': BACK(); Serial.print("Run!\r\n"); break;
     case 'F': LEFT_3(); Serial.print("Left down!\r\n"); break;
     case 'G': LEFT_2(); Serial.print("Left!\r\n"); break;
     case 'H': LEFT_1(); Serial.print("Left up!\r\n"); break;
     case 'Z': STOP(); Serial.print("Stop!\r\n"); break;
     case 'L': Motor_PWM = 150; break;
     case 'M': Motor_PWM = 100; break;
   }
}
void IO_init()
{
  pinMode(12 /*A电机转速 --> PB6*/, 0x1);
  pinMode(34 /* --> PC3 */, 0x1);pinMode(35 /*A电机方向 --> PC2*/, 0x1);
  pinMode(8 /*B电机转速 */, 0x1);
  pinMode(37, 0x1);pinMode(36 /*B电机方向*/, 0x1);
  pinMode(6 /*C电机转速  pin 9 change pin 6*/, 0x1);
  pinMode(43, 0x1);pinMode(42 /*C电机方向*/, 0x1);
  pinMode(5 /*D电机转速*/, 0x1);
  pinMode(A4 /*26  */, 0x1);pinMode(A5 /*27  //D电机方向*/, 0x1);
  // encoder pin setup
  pinMode(enc_motorAA, 0x0);pinMode(enc_motorAB, 0x0); // MOTORA
  pinMode(enc_motorBA, 0x0);pinMode(enc_motorBB, 0x0); // MOTORB
  pinMode(enc_motorCA, 0x0);pinMode(enc_motorCB, 0x0); // MOTORC
  pinMode(enc_motorDA, 0x0);pinMode(enc_motorDB, 0x0); // MOTORD
  attachInterrupt(((enc_motorAA) == 2 ? 0 : ((enc_motorAA) == 3 ? 1 : ((enc_motorAA) >= 18 && (enc_motorAA) <= 21 ? 23 - (enc_motorAA) : -1))), countPulseA, 3);
  attachInterrupt(((enc_motorBA) == 2 ? 0 : ((enc_motorBA) == 3 ? 1 : ((enc_motorBA) >= 18 && (enc_motorBA) <= 21 ? 23 - (enc_motorBA) : -1))), countPulseB, 3);
  attachInterrupt(((enc_motorCA) == 2 ? 0 : ((enc_motorCA) == 3 ? 1 : ((enc_motorCA) >= 18 && (enc_motorCA) <= 21 ? 23 - (enc_motorCA) : -1))), countPulseC, 3);
  attachInterrupt(((enc_motorDA) == 2 ? 0 : ((enc_motorDA) == 3 ? 1 : ((enc_motorDA) >= 18 && (enc_motorDA) <= 21 ? 23 - (enc_motorDA) : -1))), countPulseD, 3);

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
    
# 487 "/home/user/arduino/arduino.ino" 3
   __asm__ __volatile__ ("cli" ::: "memory")
# 487 "/home/user/arduino/arduino.ino"
                 ;
    int countA = pulseCounterA;
    int countB = pulseCounterB;
    int countC = pulseCounterC;
    int countD = pulseCounterD;

    pulseCounterA = 0;
    pulseCounterB = 0;
    pulseCounterC = 0;
    pulseCounterD = 0;

    
# 498 "/home/user/arduino/arduino.ino" 3
   __asm__ __volatile__ ("sei" ::: "memory")
# 498 "/home/user/arduino/arduino.ino"
               ;

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
  if(digitalRead(enc_motorAB) == 0x1)
  {
   pulseCounterA ++;
  }
  else {
    pulseCounterA --;
  }
}
void countPulseB()
{
  if(digitalRead(enc_motorBB) == 0x1)
  {
   pulseCounterB ++;
  }
  else {
    pulseCounterB --;
  }
}

void countPulseC()
{
  if(digitalRead(enc_motorCB) == 0x1)
  {
   pulseCounterC ++;
  }
  else {
    pulseCounterC --;
  }
}
void countPulseD()
{
  if(digitalRead(enc_motorDB) == 0x1)
  {
   pulseCounterD ++;
  }
  else {
    pulseCounterD --;
  }
}
