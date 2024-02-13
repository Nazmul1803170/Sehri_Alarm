#include "functionPrototype.h"
#include "playMusic.h"

#define MUSIC_NAME "000xxx.wav"

void setup(){
  Serial.begin(115200);
  Serial.println("Start");


  configAmplifier();

  playMusic(MUSIC_NAME);
}

void loop(){
  delay(10000);
}
