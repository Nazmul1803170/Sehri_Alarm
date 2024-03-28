bool dcSource = false;

void configRelay() {
  pinMode(SOCKET_CONTROL, OUTPUT);
  pinMode(AC_CONTOL, OUTPUT);
  pinMode(DC_CONTROL, OUTPUT);
  pinMode(CONVERTER_CONTROL, OUTPUT);
  pinMode(ELECTRICITY_DETECT, INPUT_PULLDOWN);
}

void socketControl(bool status) {
  if (status) {
    digitalWrite(SOCKET_CONTROL, HIGH);
    Serial.println("Socket ON");
  }
  else {
    digitalWrite(SOCKET_CONTROL, LOW);
    Serial.println("Socket OFF");
  }
}

void acControl(bool status) {
  if (status) {
    digitalWrite(AC_CONTOL, HIGH);
    Serial.println("AC Source ON");
  }
  else {
    digitalWrite(AC_CONTOL, LOW);
    Serial.println("AC Source OFF");
  }
  delay(1000);
}

void converterControl(bool status) {
  if (status) {
    digitalWrite(CONVERTER_CONTROL, LOW);
    Serial.println("Converter Power ON");
  }
  else {
    digitalWrite(CONVERTER_CONTROL, HIGH);
    Serial.println("Converter Power OFF");
  }
}


void dcControl(bool status) {
  if (status) {
    digitalWrite(DC_CONTROL, LOW);
    dcSource = true;
    Serial.println("DC Source ON");
  }
  else {
    digitalWrite(DC_CONTROL, HIGH);
    dcSource = false;
    Serial.println("DC Source OFF");
  }
  delay(1000);
}


void detectPowerSource() {
  if (digitalRead(ELECTRICITY_DETECT)) {
    if (dcSource) {
      dcControl(0);
      delay(1000);
      acControl(1);
    }
  } else {
    if (!dcSource) {
      acControl(0);
      delay(1000);
      dcControl(1);
    }
  }
}
