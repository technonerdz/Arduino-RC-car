#include <IRremote.h>
#include <IRremoteInt.h>


IRsend irsend;

void setup()
{
 Serial.begin(9600);
}

void loop() 
{

   for (int i = 0; i < 10; i++) { 
    int tosend = 0xa0 + i;
     irsend.sendSony(tosend, 12); // Sony TV power code
     delay(40);
   }
   
   for (int i = 0; i < 10; i++) { 
    int tosend = 0xb0 + i;
     irsend.sendSony(tosend, 12); // Sony TV power code
     delay(40);
   }

   for (int i = 0; i < 10; i++) { 
    int tosend = 0xc0 + i;
     irsend.sendSony(tosend, 12); // Sony TV power code
     delay(40);
   }

   for (int i = 0; i < 10; i++) { 
    int tosend = 0xd0 + i;
     irsend.sendSony(tosend, 12); // Sony TV power code
     delay(40);
   }


}
