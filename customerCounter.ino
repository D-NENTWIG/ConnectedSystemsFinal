#include <ArduinoLowPower.h>
 
int led = 4;                // the pin that the LED is atteched to
int sensor = 1;              // the pin that the sensor is atteched to            // by default, no motion detected
volatile int val = 0;        // variable to store the sensor status (value)

const int buzzer = 2;

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(buzzer, OUTPUT); //Setup buzzer
  LowPower.attachInterruptWakeup(digitalPinToInterrupt(sensor), blink, CHANGE);
}

void loop(){
  if (val == 1) {   // check if the sensor is HIGH
  //Motion Deteted
    Serial.println("Motion Detected");        
    digitalWrite(led, HIGH);   // turn LED ON
    tone(buzzer, 250);
    delay(50); //Wait
   //Motion Detection Over
    noTone(buzzer);
    digitalWrite(led, LOW);
    Serial.println("Motion stopped");
    val = 0;
  }
  LowPower.sleep();
}

void blink() {
  val = 1;
}
