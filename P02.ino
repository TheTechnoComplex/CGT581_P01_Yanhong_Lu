#include <Stepper.h>

const int stepsPerRevolution = 2038;
const int trigPin = 5;
const int echoPin = 6;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myStepper.setSpeed(5);  // Set default motor speed
}

void loop() {
  // Send a short pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the echo to return
  duration = pulseIn(echoPin, HIGH, 30000);  // Timeout at 30ms
  if (duration == 0) {
    Serial.println("No Echo - Object Out of Range");
    return;  // Skip the rest of the loop if no valid reading
  }

  // Calculate the distance (in cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Control the stepper motor
  if (distance > 0 && distance <= 30) {
    myStepper.setSpeed(5);
    myStepper.step(100);  // Move stepper in small increments
  } else {
    // Stop the stepper properly by not calling step()
    Serial.println("Motor Stopped");
  }

  delay(10);  // Small delay to stabilize readings
}