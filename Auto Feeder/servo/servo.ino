#include <Servo.h>
Servo servo; 

const int servo_mm = 9; 
int angle =0;   
void setup() {
  // put your setup code here, to run once:
  servo.attach(servo_mm);           
  servo.write(angle);

}

void loop() {
  // put your main code here, to run repeatedly:

}
