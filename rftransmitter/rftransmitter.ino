
#include <VirtualWire.h>
// variables pour les valeurs des joystick
char *joy1char;
char *joy2char;

//variables des joystick qui seront Map de -10 à 10 et ensuite de 0 à 20 pour faciliter le transfer en lettre
int joy1Map = 0;
int joy2Map = 0;

//Array pour le protocole chiffres vers lettres
char* numbertoletter[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U"};


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

joy1Map = 0;
joy2Map = 20;

//prtocole chiffres vers lettres. Copyright Félix Giffard ©
joy1char = numbertoletter[joy1Map];
joy2char = numbertoletter[joy2Map];



vw_send((uint8_t *)joy1char, strlen(joy1char));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
delay(20);


vw_send((uint8_t *)joy2char, strlen(joy2char));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,0);
delay(500);


}
