#include "fnPrototype.h"
#include "settings.h"
#include "i2sModule.h"
#include "playAudio.h"
#include "rtcModule.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Start");

  configRTC();
  rtcAdjust();
  initSD();
  configI2S();

  playMainAudio("3_50");
  delay(1000);
  playMainAudio("3_51");
}

void loop() {

  Serial.println(getCurrentTime());
  delay(1000);
}
