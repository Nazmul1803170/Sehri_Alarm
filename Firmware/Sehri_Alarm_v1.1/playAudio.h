#include "String.h"
#define INTRO_PATH    "/announcement/intro.mp3"
#define ENDING_PATH   "/announcement/ending.mp3"
#define CT_DIR        "/current_time/"
#define SET_DIR       "/sahri_end_time/"
#define SLT_DIR       "/sahri_left_time/"
#define GAJAL_DIR     "/gajal/"

void playMainAudio(String currentTime){
  String ctPath = String(CT_DIR) + String("ct_") + String(currentTime) + String(".mp3");
  String setPath = String(SET_DIR)+ String("set_") + String(currentDate) + String(".mp3");
  playAudio(INTRO_PATH);
  playAudio(ctPath);
  playAudio(setPath);
  playAudio(ENDING_PATH);
}
