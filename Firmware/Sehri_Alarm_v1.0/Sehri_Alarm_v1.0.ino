#include "functionPrototype.h"
#include "fileHandler.h"
#include "playMusic.h"
#include "esp32_wdt.h"



#define MUSIC_NAME0 "000xxx.wav"
#define MUSIC_NAME1 "001xxx.wav"
#define MUSIC_NAME2 "002xxx.wav"
#define MUSIC_NAME3 "003xxx.wav"
#define MUSIC_NAME4 "004xxx.wav"

void setup() {
  Serial.begin(115200);
  Serial.println("Start");


  
  
  initSD();

  configAmplifier();

  playMusic(MUSIC_NAME0);
//  delay(5000);
//  playMusic(MUSIC_NAME1);
//  delay(5000);
//  playMusic(MUSIC_NAME2);
//  delay(5000);
//  playMusic(MUSIC_NAME3);
//  delay(5000);
//  //playMusic(MUSIC_NAME4);

}

void loop() {
  if (musicStartingTimeG) {
    if (millis() - musicStartingTimeG >= (musicDurationG * 1000)) {
      Serial.println("End playing music");
      musicStartingTimeG = 0;
      delay(5000);
      playMusic(MUSIC_NAME1);
    }
  }
}
