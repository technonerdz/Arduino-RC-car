int mspeed = 10;


int ontime = map(mspeed, 1, 10, 900, 1000);
int offtime = 1000 - ontime;

void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);


}

void loop() {

  
//  
  digitalWrite(8, HIGH);
  delay(ontime/3);  
  
  digitalWrite(8, LOW);
  delay(offtime/3);  
//

  digitalWrite(8, HIGH);
  delay(ontime/3);  
  
  digitalWrite(8, LOW);
  delay(offtime/3);  
//

  digitalWrite(8, HIGH);
  delay(ontime/3);  
  
  digitalWrite(8, LOW);
  delay(offtime/3);
}
