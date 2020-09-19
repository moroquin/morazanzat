const int leftsensor = 10;
const int rightsensor = 9;
int counter = 0;
boolean bandera = false;

void setup(){
  pinMode(leftsensor, INPUT);
  pinMode(rightsensor, INPUT);
  Serial.begin(9600);
}

void loop(){
  if(bandera && digitalRead(leftsensor)==LOW){
    counter++; 
    Serial.print(counter);
    Serial.println(" L");   
    bandera = false;
  }else if(!bandera && digitalRead(rightsensor)==LOW){
    counter++;
    Serial.print(counter);
    Serial.println(" R");
    bandera = true;
  } 
}
