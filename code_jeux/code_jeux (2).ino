#include <SPI.h>
#include <SD.h> // Inclure la librairie SD
#define SDPIN 30 // Chip Select du lecteur SD
#include <TMRpcm.h> 

TMRpcm audio;
File myFile;

const int pinbuton1 = 4; //33
const int pinbuton2 = 12; 
const int pinbuton3 = 37;
const int pinbuton4 = 39;
const int pinbuton5 = 41;
const int pinbuton6 = 2;//35

const byte temps_delais = 5000;

/*
 * def pin led RGB
 * 
 * led 1:
 *  R:1
 *  G:2
 *  B:3
 *  
 *  led 2:
 *  R:4
 *  G:5
 *  B:6
 *  
 *  led 3:
 *  R:7
 *  G:8
 *  B:9
 *  
 * led 4:
 *  R:10
 *  G:11
 *  B:12
 *  
 * led 5:
 *  R:13
 *  G:14
 *  B:15
 *  
 */
const byte PIN_LED_ROUGE = 10; //23

const byte PIN_LED2_R = 33; //4
const byte PIN_LED2_G = 5;
const byte PIN_LED2_B = 6;

const byte PIN_LED3_R = 7;
const byte PIN_LED3_G = 10; //8
const byte PIN_LED3_B = 9;

const byte PIN_LED4_R = 23; //10
const byte PIN_LED4_G = 11;
const byte PIN_LED4_B = 35; //12

const byte PIN_LED5_R = 13;
const byte PIN_LED5_G = 14;
const byte PIN_LED5_B = 15;

const byte PIN_LED_BLANC = 8; //22

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //initialisation boutons
  pinMode(pinbuton1, INPUT);
  pinMode(pinbuton2, INPUT);
  pinMode(pinbuton3, INPUT);
  pinMode(pinbuton4, INPUT);
  pinMode(pinbuton5, INPUT);
  pinMode(pinbuton6, INPUT);

  //initialisation leds
  pinMode(PIN_LED_ROUGE, OUTPUT);
  pinMode(PIN_LED_BLANC, OUTPUT);
  pinMode(PIN_LED2_R, OUTPUT);
  pinMode(PIN_LED2_G, OUTPUT);
  pinMode(PIN_LED2_B, OUTPUT);
  pinMode(PIN_LED3_R, OUTPUT);
  pinMode(PIN_LED3_G, OUTPUT);
  pinMode(PIN_LED3_B, OUTPUT);
  pinMode(PIN_LED4_R, OUTPUT);
  pinMode(PIN_LED4_G, OUTPUT);
  pinMode(PIN_LED4_B, OUTPUT);
  pinMode(PIN_LED5_R, OUTPUT);
  pinMode(PIN_LED5_G, OUTPUT);
  pinMode(PIN_LED5_B, OUTPUT);
  
  //initialisation de la partie audio
  audio.speakerPin = 13;
  audio.setVolume(4); // gestion du volume de 0 à 7
  audio.quality(1); 

  // Initialisation de la carte SD
  if (!SD.begin(SDPIN)) { 
    Serial.println("SD initialization failed!"); //  S'il y a un soucis "initialization failed!" s'affichera au moniteur
    return;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean buton1 = digitalRead(pinbuton1); //rouge
  boolean buton2 = digitalRead(pinbuton2); //bleu
  boolean buton3 = digitalRead(pinbuton3); //vert
  boolean buton4 = digitalRead(pinbuton4); //jaune
  boolean buton5 = digitalRead(pinbuton5); //magenta
  boolean buton6 = digitalRead(pinbuton6); //blanc

  Serial.print("bouton6: ");
  Serial.print(buton6);
  Serial.print("    bouton1: ");
  Serial.println(buton1);
  
  if (buton1 == 1){
    digitalWrite(PIN_LED_ROUGE, HIGH);
    audio.play("sounds/rouge.wav");
    delay(temps_delais); //mettre une variable à place de 5000
    digitalWrite(PIN_LED_ROUGE, LOW);
  }
  
  if (buton2 == 1){
    displayColor(0, 0, 255, 2);
    //led bleu
    audio.play("sounds/bleu.wav");
    delay(temps_delais);
    displayColor(0, 0, 0, 2);
  }

  if (buton3 == 1){
    displayColor(0, 255, 0, 3);
    //led vert
    audio.play("sounds/vert.wav");
    delay(temps_delais);
    displayColor(0, 0, 0, 3);
  }

  if (buton4 == 1){
    displayColor(255, 255, 0, 4);
    //led jaune
    audio.play("sounds/jaune.wav");
    delay(temps_delais);
    displayColor(0, 0, 0, 4);
  }

  if (buton5 == 1){
    displayColor(255, 0, 255, 5);
    //led magenta
    audio.play("sounds/magenta.wav");
    delay(temps_delais);
    displayColor(0, 0, 0, 5);
  }

  if (buton6 == 1){
    digitalWrite(PIN_LED_BLANC, HIGH);
    //led blanc
    audio.play("sounds/blanc.wav");
    delay(temps_delais);
    digitalWrite(PIN_LED_BLANC, LOW);
  }
   
  }

  void displayColor(byte r, byte g, byte b, byte led) {
    // fonction pour l'allumage avec un couleur donné
    if (led == 2){
       analogWrite(PIN_LED2_R, ~r);
       analogWrite(PIN_LED2_G, ~g);
       analogWrite(PIN_LED2_B, ~b);
    }

    if (led == 3){
       analogWrite(PIN_LED3_R, ~r);
       analogWrite(PIN_LED3_G, ~g);
       analogWrite(PIN_LED3_B, ~b);
    }

    if (led == 4){
       analogWrite(PIN_LED4_R, ~r);
       analogWrite(PIN_LED4_G, ~g);
       analogWrite(PIN_LED4_B, ~b);
    }

    if (led == 5){
       analogWrite(PIN_LED5_R, ~r);
       analogWrite(PIN_LED5_G, ~g);
       analogWrite(PIN_LED5_B, ~b);
    }
}
