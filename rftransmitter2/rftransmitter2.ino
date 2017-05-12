
#include <VirtualWire.h>
// variables pour les valeurs des joystick
char *joy1char;

//variables des joystick qui seront Map de -10 à 10 et ensuite de 0 à 20 pour faciliter le transfer en lettre
int joy1Map = 0;
int joy2Map = 0;

//Array pour le protocole chiffres vers lettres
char* numbertoletter[] = {"A", "B", "C", "D"};


void setup() {
  pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); 
vw_set_tx_pin(12);
vw_setup(4000);// speed of data transfer Kbps
}

void loop(){

// Joystick map de -10 à 10
// si on l'envoie en char, on peut le transformer en lettre de A à U
//EX: -10 = A, 0 = K ert 10 = U
//on peut ensuite envoyer 2 lettres consécutivement pour les 2 joystick avec un delay de 20ms

joy1Map = 20;
joy2Map = 20;

//prtocole chiffres vers lettres. Copyright Félix Giffard ©

if ((joy1Map <= 0 && joy2Map <= 0)){
// si aucun joystick n'est touché
  joy1char = numbertoletter[0];
  
}else{
  if ((joy1Map > 0 && joy2Map > 0)){
  // si les 2 joysticks sont activé
    joy1char = numbertoletter[1];
    
  }else{
    if (joy1Map > 0){
      // si le joystick 1 est activé et que l'autre ne l'est pas
      joy1char = numbertoletter[2];
    }else{
      // si le joystick 2 est activé et que l'autre ne l'est pas
      joy1char = numbertoletter[3];
    }
  }
}

vw_send((uint8_t *)joy1char, strlen(joy1char));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
delay(20);

}
