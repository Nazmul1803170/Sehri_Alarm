#include "RTClib.h"

RTC_DS3231 rtc;

struct Time {
  uint8_t hour;
  uint8_t minute;
};

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
  char buf1[] = "hh_mm";
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

  if(time1.indexOf(time2) >= 0){
    return true;
  }

  return false;
}

String getSahriEndTime(String date) {

  File file = SD.open("/sahri_end_time.txt");

  if (!file) {
    Serial.println("Error opening file.");
    return "";
  }

  while (file.available()) {
    String line = file.readStringUntil('\n');
    int posAt = line.indexOf('@');
    if (posAt == -1) {
      return ""; // '@' not found
    }

    String parseDate = line.substring(0, posAt);
    String parseTime = line.substring(posAt + 1);

    if (parseDate.indexOf(date) >= 0) {
      return parseTime;
    }
  }
  file.close(); 
}


String getCurrentDate() {
  DateTime now = rtc.now();

  // Print the ISO string to the Serial Monitor
  char buf1[] = "DD_MM";
  String isoString = now.toString(buf1);

  return isoString;
}


String currentISOTime() {
  DateTime now = rtc.now();

  // Print the ISO string to the Serial Monitor
  char buf1[] = "YYYY-MM-DDThh:mm:ss";
  String isoString = now.toString(buf1);

  return isoString;
}
