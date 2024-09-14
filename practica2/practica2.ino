void setup() {
  //Define los pines de conexión
  for(int i=7; i<=13; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // Secuencia 1: Orden inverso
  for(int j=13; j>=7; j--){ //Utiliza el for para encenderlos en un orden
    digitalWrite(j,HIGH);
    delay(500);
    digitalWrite(j,LOW);
    delay(500);
  }
  //Secuencia 2: Orden normal
  for(int j=7; j<=13; j++){ //Utiliza el for para encenderlos en un orden
    digitalWrite(j,HIGH);
    delay(500);
    digitalWrite(j,LOW);
    delay(500);
  }
  //Secuencia 3: triple encendido
  for(int j=13; j>=7; j--){
    for(int l=0;l<=2;l++){
      digitalWrite(j,HIGH);
      delay(500);
      digitalWrite(j,LOW);
      delay(500);
    }
  }
  //Secuencia 4: encienden de uno en uno y apagan de uno en uno
  for(int j=13; j>=7; j--){
    digitalWrite(j,HIGH);
    delay(500);
  }
  for(int j=13; j>=7; j--){
    digitalWrite(j,LOW);
    delay(500);
  }
  //Secuencia 5: 
  for(int i = 0; i < 4; i++){
    digitalWrite(7 + i, HIGH);  // Enciende LED en el pin (7 + i)
    digitalWrite(13 - i, HIGH); // Enciende LED en el pin (13 - i)
    delay(500); // Espera
  }

  delay(500); // Espera antes de apagar los LEDs

  for(int i = 0; i < 4; i++){
    digitalWrite(7 + i, LOW);  // Apaga LED en el pin (7 + i)
    digitalWrite(13 - i, LOW); // Apaga LED en el pin (13 - i)
    delay(500); // Espera
  }

  delay(500); // Espera antes de reiniciar el ciclo
  
}
