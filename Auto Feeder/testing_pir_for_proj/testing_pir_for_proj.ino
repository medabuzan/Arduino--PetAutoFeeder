int pin = 12;

void setup() {
 
  Serial.begin(9600);
  
  pinMode(pin, INPUT);
}

void loop() {
 
  boolean isMotion = digitalRead(pin); 
 
  if (isMotion == 1)
    Serial.println("Motion is Detected");
  else
    Serial.println("No Motion is present");
  delay(1000);       
}
