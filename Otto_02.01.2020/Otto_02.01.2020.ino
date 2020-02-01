#include <Ultrasonic.h>
#include <Servo.h>
#include "Sing.h"
Ultrasonic ultrasonic(6, 7);
Servo RL;
Servo RR;
Servo YL;
Servo YR;
#define PIN_YL 2 //servo[0]
#define PIN_YR 3 //servo[1]
#define PIN_RL 4 //servo[2]
#define PIN_RR 5 //servo[3]

/*
         --------------- 
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         --------------- 
            ||     ||
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/

void setup() {  
  Serial.begin(9600);
  RL.attach(PIN_RL);
  RR.attach(PIN_RR);
  YL.attach(PIN_YL);
  YR.attach(PIN_YR);
}

void loop() {
  
  
//  choise(1000);
  DistUpdate();
   dance_4(1000);
//   dance_2(1000);
//   dance_3(1000);
//   dance_4(1000);
//   dance_5(1000);
//   dance_6(1000);
//   dance_7(1000);
//   dance_8(1000);
//   toUp(1000);
//   toDefault(5000);
   
}
void DistUpdate(){
  float dist = ultrasonic.read(CM);
  Serial.println(dist);
  if(dist < 20){
    sing(9,4);
  }
}
void choise (int tempo) {
  int num = random(1, 9);
  switch(num) {
    case 1:
      dance_1(tempo);
      break;
    case 2:
      dance_2(tempo);
      break;
    case 3:
      dance_3(tempo);
      break;
    case 4:
      dance_4(tempo);
      break;
    case 5:
      dance_5(tempo);
      break;
    case 6:
      dance_6(tempo);
      break;
    case 7:
      dance_7(tempo);
      break;
    case 8:
      dance_8(tempo);
      break;
    case 9:
      toUp(tempo);
      break;
  }
}
void dance_8(int tempo) {
  RL.write(90);
  RR.write(150);
  YL.write(90);
  YR.write(90);
  delay(tempo);
}
void dance_7(int tempo) {
  RL.write(30);
  RR.write(90);
  YL.write(90);
  YR.write(90);
  delay(tempo);
}
void dance_6(int tempo){
  RL.write(130);
  RR.write(90);
  YL.write(90);
  YR.write(90);
  delay(tempo/2);
  RL.write(90);
  RR.write(30);
  delay(tempo/2);
}
void dance_5(int tempo){
  toDefault(1000);
  delay(tempo);
  RR.write(110); 
  RL.write(130);
  delay(tempo);
  RR.write(110);
  RL.write(100);
  delay(tempo/4);
  RR.write(110);
  RL.write(150);
  delay(tempo/4);
  DistUpdate();
  RR.write(110);
  RL.write(80);
  delay(tempo/4);
  RR.write(110);
  RL.write(150);
  delay(tempo/4);
  RR.write(110);
  RL.write(100);
  delay(tempo);
}
void dance_4(int tempo){
  toDefault(1000);
  delay(tempo);
  RR.write(50);
  RL.write(70);
  delay(tempo);
  RR.write(80);
  RL.write(70);
  delay(tempo/4);
  RR.write(30);
  RL.write(70);
  delay(tempo/4);
  DistUpdate();
  RR.write(80);
  RL.write(70);
  delay(tempo/4);
  RR.write(30);
  RL.write(70);
  delay(tempo/4);
  RR.write(80);
  RL.write(70);
  delay(tempo);
}
void dance_3(int tempo) {
  RL.write(90);
  RR.write(90);
  delay(tempo/2);
  RL.write(0);
  RR.write(180);
  YL.write(90);
  YR.write(90);
  DistUpdate();
  delay(tempo/2);
  RL.write(90);
  RR.write(90);
  delay(tempo/2);
  RL.write(150);
  RR.write(30);
  delay(tempo/2);
}
void dance_2(int tempo) {
  for(int i = 0; i < 3; i++) {
    toUp(tempo/2);
    toDefault(tempo/2);
  }

}
void dance_1(int tempo) {
  RL.write(90);
  RR.write(90);
  YL.write(120);
  YR.write(120);
  delay(tempo/4);
  RL.write(70);
  RR.write(110);
  YL.write(120);
  YR.write(120);
  DistUpdate();
  delay(tempo/4);
  RL.write(70);
  RR.write(110);
  YL.write(60);
  YR.write(60);
  delay(tempo);
}
void toDefault(int tempo) {
  RL.write(90);
  RR.write(90);
  YL.write(90);
  YR.write(90);
  delay(tempo);
}
void toUp(int tempo) {
  RL.write(150);
  RR.write(30);
  YL.write(90);
  YR.write(90);
  delay(tempo);
}
