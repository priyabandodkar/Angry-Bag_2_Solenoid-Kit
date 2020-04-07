
/*  01-04-2020
 *  Advanced Wearables Assignment 3 : Final Project
 *  Project Name: Angry Bag 2.0 | The Recipe
 *  Microcontroller: Arduino Nano 33 IoT 
 *  Motor: Solenoid
 *  by Priya Bandodkar
 */


const int ledPin =  10;     // LED Digital Output Pin
const int analogPin = 7;     // Analog Sensor Input Pin

const int solenoidPin = 6;      // Solenoid Output Pin

int analogValue = 0;            // Set initial Analog Value
int analogThreshold =1012;
int ledState = LOW;          // Set initial LED State
int solenoidState = LOW;   // Set initial solenoid state

int counterValue = 0;        // Declare variable to count blinks
int maxCount = 20;      // Declare variable for maximum blinks

void setup() {
  
  Serial.begin(9600);   // Initialize serial
  //CircuitPlayground.begin();  // Initialize Circuit Playground library
  pinMode(ledPin, OUTPUT);
  pinMode(solenoidPin, OUTPUT);
  //myservo.attach(servoPin);   // Attach the servo on servoPin
  
}

void loop() {
  analogValue = analogRead(analogPin);
  delay (100);
  
if (analogValue > analogThreshold) {
      if (ledState == LOW) {
      ledState = HIGH;
      counterValue++;
    } else {
      ledState = LOW;
    }
} else {
     ledState = LOW; 
     }
 digitalWrite(ledPin, ledState); 

if (counterValue > maxCount) {
      solenoidState = HIGH; 
     }
     else {
     solenoidState = LOW;
     }

 digitalWrite(solenoidPin, solenoidState);
     
  Serial.println (counterValue);
  Serial.println (analogValue);
}

/*
  Credits:
  1) Blink without Delay
  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi

  http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/
