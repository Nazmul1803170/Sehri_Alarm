#include "fnPrototype.h"

// Testing purpose
String audioFiles[] = {"/000xxx.wav","/001xxx.wav","/002xxx.wav","/003xxx.wav"};


void setup(){
  Serial.begin(115200);
  Serial.println("Start");

  initSD();
  configI2S();

  for(int i=0;i<4;i++){
    Serial.println(audioFiles[i]);
  }
}
int i=0;
void loop(){
  playAudio(audioFiles[i]);
  i++;
}
