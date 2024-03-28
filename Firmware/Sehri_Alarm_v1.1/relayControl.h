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
  }
  else {
    digitalWrite(SOCKET_CONTROL, LOW);
  }
}

void acControl(bool status) {
  if (status) {
    digitalWrite(AC_CONTOL, HIGH);
  }
  else {
    digitalWrite(AC_CONTOL, LOW);
  }
}

void converterControl(bool status) {
  if (status) {
    digitalWrite(CONVERTER_CONTROL, LOW);
  }
  else {
    digitalWrite(CONVERTER_CONTROL, HIGH);
  }
}


void dcControl(bool status) {
  if (status) {
    digitalWrite(DC_CONTROL, LOW);
    dcSource = true;
  }
  else {
    digitalWrite(DC_CONTROL, HIGH);
    dcSource = false;
  }
}


void detectPowerSource() {
  if (digitalRead(ELECTRICITY_DETECT)) {
    if (dcSource) {
      dcControl(0);
      delay(2000);
      acControl(1);
    }
  } else {
    if (!dcSource) {
      acControl(0);
      delay(2000);
      dcControl(1);
    }
  }
}
