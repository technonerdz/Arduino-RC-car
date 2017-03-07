#include <IRremote.h>
#include <IRremoteInt.h>


IRsend irsend;

void setup()
{
 Serial.begin(9600);
}

void loop() 
{
irsend.sendSony(0xa90, 12); // Sony TV power code
delay(50);

irsend.sendSony(0xa91, 12); // Sony TV power code
delay(50);

irsend.sendSony(0xa92, 12); // Sony TV power code
delay(50);

irsend.sendSony(0xa93, 12); // Sony TV power code
delay(50);
  
//   for (int i = 0; i < 50; i++) { 
//     irsend.sendSony(0xa90, 12); // Sony TV power code
//     delay(40);
//   }
//   for (int i = 0; i < 50; i++) { 
//     irsend.sendSony(0xa92, 12); // Sony TV power code
//     delay(40);
//   }
}
