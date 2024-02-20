

// Initialize SPIFFS
void initSPIFFS() {
  if (!SPIFFS.begin(true)) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  Serial.println("SPIFFS mounted successfully");
}


//Initialize SD Card
void initSD() {
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    return;
  }
  Serial.println("Card mounted successfully");
}


// Read File from SPIFFS
String readFile(fs::FS &fs, const char *path) {
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return String();
  }

  String fileContent;
  while (file.available()) {
    fileContent = file.readStringUntil('\n');
    break;
  }
  Serial.println(fileContent);
  return fileContent;
}

// Write file to SPIFFS
void writeFile(fs::FS &fs, const char *path, const char *message) {
  Serial.printf("Writing file: %s\r\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("- failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    Serial.println("- file written");
  } else {
    Serial.println("- frite failed");
  }
}

void appendFile(fs::FS &fs, const char *path, const char *message) {
  Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if (file.print(message)) {
    Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();
}



uint16_t getDuration(fs::FS &fs, const char *path, String musicName) {
  Serial.printf("Reading file: %s\r\n", path);

  char filename[20];
  uint16_t value;

  File file = fs.open(path);
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return int();
  }

  String fileContent;
  while (file.available()) {
    fileContent = file.readStringUntil('\n');

    if (fileContent.indexOf(musicName) >= 0) {
      sscanf(fileContent.c_str(), "%[^,],%d", filename, &value);
//      Serial.print("File name: ");
//      Serial.print(filename);
//      Serial.print(" Duration: ");
//      Serial.println(value);
      return value;
    }
  }

  file.close();
  return 0;
}
