#include "RTClib.h"

RTC_DS3231 rtc;

void configRTC() {
  Serial.begin(115200);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }
}


void rtcAdjust() {
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}



String getCurrentTime() {
  DateTime now = rtc.now();

  // Print the ISO string to the Serial Monitor
  char buf1[] = "hh:mm";
  String isoString = now.toString(buf1);

  return isoString;
}


bool isEqualTime(String time1, String time2) {
  int hour1, minute1, hour2, minute2;
  sscanf(time1.c_str(), "%d:%d", &hour1, &minute1);
  sscanf(time2.c_str(), "%d:%d", &hour2, &minute2);

  if (hour1 == hour2) {
    if (minute1 == minute2) {
      return true;
    }
  }

  return false;
}



String currentISOTime() {
  DateTime now = rtc.now();

  // Print the ISO string to the Serial Monitor
  char buf1[] = "YYYY-MM-DDThh:mm:ss";
  String isoString = now.toString(buf1);

  return isoString;
}
