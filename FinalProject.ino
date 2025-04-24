#include <Stepper.h>
const int stepsPerRevolution = 2038;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);


const int trigPin = 5;
const int echoPin = 6;

int trigStat = 0;
int gdistance = 0;
int lightValue = 0;
int lightStat = 1;
int lightupper = 550;
int lightlower = 250;

long duration;
int distance;

void setup() {
  myStepper.setSpeed(5);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  int lightValue = analogRead(A0);


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH, 30000);  // Timeout at 30ms
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(gdistance);
  Serial.print("Analog reading (0-1023): ");
  Serial.print(lightValue);

  if (lightStat==1){
    if (distance>0 && distance <= 20){
      if (gdistance>=1){
        gdistance -= 1;
      } else{
        gdistance=0;
      }
      

      if (trigStat==0) {
        myStepper.step(1200);
        myStepper.step(-1200);
        gdistance=0;
        trigStat=1;
        }

    
    
    } else {
      gdistance += 1;
    }




    if (lightValue>=300){
      if (gdistance>=500){
        if(trigStat==1){
          myStepper.step(-1200);
          myStepper.step(1200);
          trigStat=0;
        } else{
        }
      }
    } else {
      lightStat=0;
    }

    delay(50);  // Small delay to stabilize readings
  }

  if (lightStat==0){
    Serial.print("Light off, manual mode on.");
    if (lightValue>=300){
      lightStat=1;
      Serial.print("Light on, manual mode off.");
      gdistance=0;
    }
    delay(50);
  }


}