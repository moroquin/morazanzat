#include <Wire.h>
//Pines de entrada del Arduino
const int LEFT_SENSOR = 10;
const int RIGHT_SENSOR = 9;
//Variables que se utilizan en el pluviometro
int counter = 0;
boolean bandera = false;
//Conexion I2C
#define SLAVE_ADDRESS = 0x8

void setup(){
//Inicializacion de los pines
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);  
//Inicializacion del puerto Serial  
  Serial.begin(9600);
//Inicializacion de la conexion I2C  
  Wire.begin(0x8);
  Wire.onRequest(requestEvents);
  Wire.onReceive(receiveEvents);
}
  /*
  Funcionamiento del contador, cada valor en el count es equivalente a 1ml de agua por xcm^2
  El metodo funciona con una bandera para omitir que se tome en cuante si pasa de subida y bajada por el sensor
  cuando esta enfrente del sensor la entrada es 0 o LOW entonces
  cuando la bandera es verdades es aceptado el sensor izquierdo
  cuando la bandera es falsa es aceptado el sensor derecho
  */
void loop(){
  if(bandera && digitalRead(LEFT_SENSOR)==LOW){
    counter++; 
    Serial.print(counter);
    Serial.println(" L");   
    bandera = false;
  }else if(!bandera && digitalRead(RIGHT_SENSOR)==LOW){
    counter++;
    Serial.print(counter);
    Serial.println(" R");
    bandera = true;
  } 
}

//Los print son codigo solo para verificar la informacion
//Wire.write envia los datos por I2C
void requestEvents(){
  Serial.println(F("---> recieved request"));
  Serial.print(F("sending value : "));
  Serial.println(counter);
  Wire.write(counter);
}

//Wire.read recibe la informacion por el I2C
//igual los print son datos inutiles
void receiveEvents(int numBytes){  
  Serial.println(F("---> recieved events"));
  counter = Wire.read();
  Serial.print(numBytes);
  Serial.println(F("bytes recieved"));
  Serial.print(F("recieved value : "));
  Serial.println(counter);
}
