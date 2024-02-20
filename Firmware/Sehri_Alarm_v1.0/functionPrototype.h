#include "SPIFFS.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"

#include <DFRobot_MAX98357A.h>


//fileHandler.h
void initSPIFFS();
void initSD();
String readFile(fs::FS &fs, const char *path);
void writeFile(fs::FS &fs, const char *path, const char *message);
void appendFile(fs::FS &fs, const char *path, const char *message);
uint16_t getDuration(fs::FS &fs, const char *path, String musicName);

//playMusic.h
void configAmplifier();
void playMusic(String musicFileName);
void printMusicList(void);
