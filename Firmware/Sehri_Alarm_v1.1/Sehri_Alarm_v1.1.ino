#include "fnPrototype.h"
#include "settings.h"
#include "relayControl.h"
#include "i2sModule.h"
#include "playAudio.h"
#include "rtcModule.h"


void setup() {
  Serial.begin(115200);
  Serial.println("Start");

  configRelay();
  configRTC();
  //rtcAdjust();
  initSD();
  configI2S();

  currentDate = getCurrentDate();
  currentDate = "28_3";
  sahriEndTime = getSahriEndTime(currentDate);
  announceStartTime = "01_10";  // Need to calculate from 1 hr ago from sahri end
  Serial.print("Sahri End Time: ");
  Serial.println(sahriEndTime);

  //  playMainAudio("3_50");
  //  delay(1000);
  //  playMainAudio("3_51");

  dcControl(0);
  acControl(0);
  converterControl(0);

  socketControl(1);
  delay(500);



}

void loop() {
  String currentTime = getCurrentTime();
  Serial.print("Current Time: ");
  Serial.println(currentTime);
  if (!isAnnounceStart) {
    if (isEqualTime(currentTime, announceStartTime)) {
      Serial.println("Announce Start");
      converterControl(1);
      dcControl(0);
      acControl(1);
      isAnnounceStart = true;
      delay(2000);
      playStartingAudio();
    }
  } else {
    playMainAudio(currentTime);
  }

  delay(1000);
}
