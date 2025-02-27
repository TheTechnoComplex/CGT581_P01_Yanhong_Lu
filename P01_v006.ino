#include <Mouse.h>
//#include <Servo.h>
//Servo myservo;
const int trigpin= 9;
const int echopin= 10;
long duration;
int distance;
int check=0;
int pos = 0;
int gdistance[]={0,0,0,0,0,0,0,0,0,0};
int avedistance=0;
int index=0;

void setup()
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);  //initialize the motorIn1 pin as output 
  pinMode(6,OUTPUT);  //initialize the motorIn2 pin as output 
//  myservo.attach(6);
 
}
void loop()
{
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance = duration*0.034/2;

  if ((distance>=30)&&(check>0)){
    check=check-1;
    }
  if((distance>0)&&(distance<30)){
    check=check+1;
    }
  if((distance==0)&&(check>10)){
    check=check-10;
  }

  Serial.println(distance);
//  if(index<10){
//    gdistance[index]=distance;
//    index=index+1;
//  }
//  if(index=10){
//    index=0;
//    gdistance[index]=distance;
//  }

//  avedistance=(gdistance[0]+gdistance[1]+gdistance[2]+gdistance[3]+gdistance[4]+gdistance[5]+gdistance[6]+gdistance[7]+gdistance[8]+gdistance[9])/10;
//  Serial.print(avedistance);
  if ((distance<=40)&&(distance>0)){
    counterclockwise(200);  //rotate clockwise 
  }
  else{
  counterclockwise(0);  //rotate clockwise 
  }

//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }

}

void counterclockwise(int Speed){
  analogWrite(5,0);  //set the speed of motor
  analogWrite(6,Speed);  //stop the motorIn2 pin of motor
}