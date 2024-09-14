void verde(int x){ //Funcion para el encendido y secuencia de la luz verde
  digitalWrite(x-5,HIGH); // SE RESTAN 5 PARA ENCENDER EL LED ROJO
  digitalWrite(x,HIGH);
  delay(3000);
  for(int i=1; i<=4; i++){
    digitalWrite(x,HIGH);
    delay(500);
    digitalWrite(x,LOW);
    delay(500);
  }
  digitalWrite(x-5,LOW);
}
void naranja(int x){ //Funcion para el encendido y secuencia de la luz naranja 
  if(x==9){
    digitalWrite(x+2,HIGH); // SE SUMAN 2 PARA ENCENDER EL LED ROJO
    digitalWrite(x,HIGH);
    delay(2000);
    digitalWrite(x,LOW);
    digitalWrite(x+2,LOW); 
    delay(500);
  }
  if(x==12){
    digitalWrite(x-4,HIGH);// SE RESTAN 4 PARA ENCENDER EL LED ROJO
    digitalWrite(x,HIGH);
    delay(2000);
    digitalWrite(x,LOW);
    digitalWrite(x-4,LOW);
  }
  
}
void rojo(int x){ //Funcion para el encendido y secuencia de la luz roja
  digitalWrite(x-1,HIGH); 
  digitalWrite(x,HIGH);
  delay(3000);
  for(int i=1; i<=4; i++){
    digitalWrite(x-1,HIGH);
    delay(500);
    digitalWrite(x-1,LOW);
    delay(500);
  }
  digitalWrite(x,LOW);
  digitalWrite(x-1,LOW);
}

void setup() {
  // Define los pines de conexión
  for(int i=8;i<=13;i++){
    pinMode(i,OUTPUT);  
  }
  Serial.begin(9600);//incializar el monitor serial a 9600 baudios
}

void loop() {
  //DOS SEMAFOROS
  //SE MANDA LLAMAR LAS FUNCIONES Y SE LE MANDA COMO PARAMETRO EL PIN DE CADA LED
  verde(13);
  naranja(12);
  rojo(11);
  naranja(9);

  
}
