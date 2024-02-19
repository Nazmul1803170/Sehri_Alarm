#include "functionPrototype.h"
#include "fileHandler.h"
#include "playMusic.h"


#define MUSIC_NAME "002xxx.wav"

void setup(){
  Serial.begin(115200);
  Serial.println("Start");

  initSD();

  configAmplifier();

  playMusic(MUSIC_NAME);
}

void loop(){
  if(musicStartingTimeG){
    if(millis() - musicStartingTimeG >= (musicDurationG*1000)){
      Serial.println("End playing music");
      musicStartingTimeG = 0;
    }
  }
}
