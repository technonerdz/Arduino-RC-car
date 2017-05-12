//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//http://www.genotronex.com/
//..................................
#include <VirtualWire.h>

int receivednumber = 0;
boolean wichjoy = true; //dit au programme lequel des 2 joystick est utilisé //False = Joystick 1 // True = Joystick 2

int leftmotorpin = 7;
int rightmotorpin = 4;

int firstjoy = 0;
int secondjoy = 0;


int firstjoyspeed = 0;
int secondjoyspeed = 0;

void setup()
{
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(12);
    vw_setup(4000);  // Bits per sec
    pinMode(13, OUTPUT);
    pinMode(leftmotorpin, OUTPUT);
    pinMode(rightmotorpin, OUTPUT);

    vw_rx_start();       // Start the receiver PLL running
Serial.begin(9600); 
}
    void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
//Serial.println(buf[0]);
      // L'émetteur envoie la valeur de chaque joystick équivalent à un map de -10 à 10 en les convertissant en lettres de A à U avec 20ms de delay EX: A=-10, K=0, U=10
      // Il faut tout mettre dans la variable receivednumber

    receivednumber = map(buf[0], 65, 85, -10, 10);

      wichjoy = !wichjoy;
      
      if (!wichjoy){
        //Joystick 1
        firstjoy = receivednumber;
      }else{
        //Joystick 2
        secondjoy = receivednumber;
        
        // Si on a eu les valeurs des 2 joystick et qu'on est pret à controller le moteur
    //firstjoyspeed correspond au temps d'arrêt des moteurs par cycle de 500ms
    //Joy1
    if (firstjoy > 0){
      firstjoyspeed = map(firstjoy, 1, 10, 150, 0);
      //digitalWrite(leftmotorpin, LOW);
     // delay(firstjoyspeed);
      digitalWrite(leftmotorpin, HIGH);
      Serial.println("Left moving");
    }else{
      digitalWrite(leftmotorpin, LOW);
      Serial.println("Left idle");
    }

    if (secondjoy > 0){
      secondjoyspeed = map(firstjoy, 1, 10, 150, 0);
      //digitalWrite(rightmotorpin, LOW);
     // delay(secondjoyspeed);
      digitalWrite(rightmotorpin, HIGH);
      Serial.println("Right moving");
    }else{
      digitalWrite(rightmotorpin, LOW);
      Serial.println("Right idle");
    }
      }

    
}

}
 
