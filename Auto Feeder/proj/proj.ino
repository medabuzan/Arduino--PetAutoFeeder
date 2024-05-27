#include <Servo.h>

Servo servo; 

const int sensor = 12; 
const int servo_mm = 9; 

int angle = 0;          
int sensor_state; 

void setup() {
  Serial.begin(9600);    
             
  pinMode(sensor, INPUT); 
  servo.attach(servo_mm);           
  servo.write(angle);
  sensor_state = digitalRead(sensor);
}

void loop() {
  //i added the code for testing the pir motion sensor so i can adapt the code and the delay accordingly
   boolean isMotion = digitalRead(sensor); 

  if (isMotion == 1)
    Serial.println("Motion is Detected");
  else{
    Serial.println("No Motion is present");
  delay(1000);       
  }
   
  // i saw it takes about 1minute and 20 seconds for the sensor to calibrate after seeing motion 
  // i set a bigger delay just to be sure
  delay(9000);
  sensor_state = digitalRead(sensor);
 
  if (sensor_state == HIGH && angle == 0) { 
    angle = 130;
    servo.write(angle);
    delay(5000);
    angle = 0;
    servo.write(angle);
    }
  else
  
  if (sensor_state == LOW && angle == 90) {
    angle = 0;
    servo.write(angle);
  }
}
