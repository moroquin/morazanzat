int dlk = 4;
int dt = 2;
boolean imprimir = false;
int con = 0;
unsigned long lastInt = 0;

void setup() {
  Serial.begin(9600);
  pinMode(dlk, INPUT);
  pinMode(dt, INPUT);
  attachInterrupt(digitalPinToInterrupt(dt), contador, LOW);
}

void loop() {
  if (imprimir) {
    Serial.print("imp");
    Serial.println(con);
    imprimir = false;
  }
}

void contador() {  
  unsigned long timeInt = millis();
  if (timeInt - lastInt > 1) {
    if (digitalRead(dlk) == HIGH) {
      imprimir = true;
      con++;
    }
  }
  lastInt = timeInt;
}
