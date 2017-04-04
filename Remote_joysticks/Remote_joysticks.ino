
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  
 int leftJoystick = analogRead(A0);
 int leftJoystickMap = map(leftJoystick, 0, 900, -10, 10);

 int rightJoystick = analogRead(A1);
 int rightJoystickMap = map(rightJoystick, 385, 1023, -10, 10);

 if ((leftJoystickMap < 0) && (leftJoystickMap >= -5)){
leftJoystickMap = 0;
 }
 
 if (leftJoystickMap < 0){ //270 AND LESS
 leftJoystickMap = map(leftJoystick, 0, 270, -10, 0);

}

  Serial.println(leftJoystickMap);
  delay(100);

  Serial.println(rightJoystickMap);
  delay(100);
  
}
