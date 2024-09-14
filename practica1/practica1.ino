void setup() {
  //Define los pines en donde se conectan las salidas
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}
void loop() {
  //Enciende y apaga los leds
  digitalWrite(13,HIGH);
  delay(3000);
  digitalWrite(13,LOW);
  delay(3000);
  digitalWrite(12,HIGH);
  delay(3000);
  digitalWrite(12,LOW);
  delay(3000);
  digitalWrite(11,HIGH);
  delay(3000);
  digitalWrite(11,LOW);
  delay(3000);
  
}
