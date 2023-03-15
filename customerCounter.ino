#include <ArduinoLowPower.h>

const int ledPin = 4;                // the pin that the LED is attached to
const int motionSensorPin = 1;       // the pin that the infrared sensor is attached to
const int lightSensorPin = A0;       // the pin that the light sensor is attached to
const int buzzerPin = 2;             // the pin that the buzzer is attached to

int lightValue;                      // variable to store the light sensor reading
volatile bool motionDetected = false;// variable to store the motion sensor status

void setup() {
  pinMode(ledPin, OUTPUT);           // initialize LED as an output
  pinMode(buzzerPin, OUTPUT);        // initialize buzzer as an output
  pinMode(motionSensorPin, INPUT);   // initialize motion sensor as an input
  pinMode(lightSensorPin, INPUT);    // initialize light sensor as an input
  LowPower.attachInterruptWakeup(digitalPinToInterrupt(motionSensorPin), detectMotion, CHANGE);
}

void loop(){
  if (motionDetected) {             // check if motion is detected
    Serial.println("Motion Detected");        
    digitalWrite(ledPin, HIGH);     // turn LED ON
    tone(buzzerPin, 250);
    delay(50);                      // Wait
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);      // turn LED OFF
    Serial.println("Motion stopped");
    motionDetected = false;         // reset motion status
  }
  LowPower.sleep();
}

void detectMotion() {
  lightValue = analogRead(lightSensorPin);
  if (lightValue >= 500) {          // check light level to confirm motion
    motionDetected = true;
  }
}
