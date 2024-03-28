#include "fnPrototype.h"
#include "settings.h"
#include "i2sModule.h"
#include "playAudio.h"
#include "rtcModule.h"
#include "relayControl.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Start");

  configRelay();
  configRTC();
  //rtcAdjust();
  initSD();
  configI2S();

//  playMainAudio("3_50");
//  delay(1000);
//  playMainAudio("3_51");

  socketControl(1);

  delay(2000);

  acControl(1);
  converterControl(1);

  delay(2000);

}

void loop() {
  detectPowerSource();
  Serial.println(getCurrentTime());
  delay(1000);
}
