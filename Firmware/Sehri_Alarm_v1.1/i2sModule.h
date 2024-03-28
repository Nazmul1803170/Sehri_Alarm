// Include required libraries
#include "Arduino.h"
#include "Audio.h"
#include "SD.h"
#include "FS.h"

// Create Audio object
Audio audio;

void initSD() {
  // Set microSD Card CS as OUTPUT and set HIGH
  pinMode(SD_CS, OUTPUT);
  digitalWrite(SD_CS, HIGH);

  // Initialize SPI bus for microSD Card
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);

  // Start microSD Card
  if (!SD.begin(SD_CS))
  {
    Serial.println("Error accessing microSD card!");
    while (true);
  }

  Serial.println("SD init successfully");
}

void configI2S() {
  // Setup I2S
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);

  // Set Volume
  audio.setVolume(51);
}

void playAudio(String audioName) {
  // Open music file
  audio.connecttoFS(SD, audioName.c_str());
  Serial.println("Start to play audio.");
  Serial.print("Audio name: ");
  Serial.println(audioName);
  while (audio.isRunning()) {
    detectPowerSource();
    audio.loop();
  }
  Serial.println("End to play audio.");
}
