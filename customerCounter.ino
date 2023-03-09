/*  
    Currently Just Turns LED on when motion is detected, PIR sensor is VERY sensitive, 
    So I put a piece of paper over it to restrict where it is detecting.

    Better if we had two IR senors so we could create counters of people entering and leaving, which would result in a much more accurate number.
    
    But could just market it to shops that have a separate exit (as we had discussed before)
*/
 
int led = 4;                // the pin that the LED is atteched to
int sensor = 1;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(50);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion stopped!"); 
      state = HIGH;       // update variable state to HIGH makes it so that println doesn't spam serial montior
    }
  } 
  else {                  //If sensor is LOW
      digitalWrite(led, LOW); // turn LED OFF
      delay(50);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion detected!");
        state = LOW;       // update variable state to LOW makes it so that println doesn't spam serial montior
    }
  }
}