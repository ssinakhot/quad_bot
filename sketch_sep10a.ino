int motorPin = 3;
int motorPin2 = 5;
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
      int speed2 = 255 - speed;
      analogWrite(motorPin2, speed2);
      Serial.println(speed);
    }
  }
} 
