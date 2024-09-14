//Variables
int tiempo;
int p1=0;
int p2=0;
void inicio(){
  digitalWrite(13,LOW);//se apaga el led
  Serial.println("¡Preparense!"); //mensaje de inicio
  tiempo=random(1,5);
  delay(tiempo*1000);
  digitalWrite(13,HIGH);
}
void comparar(){
  while(!digitalRead(2) && !digitalRead(3)){ //lee los pines que se pulsan
  }
  if(digitalRead(2)){//comprueba si el jugador 1 fue quien presiono el boton
    p1++;
  }
  if(digitalRead(3)){//comprueba si el jugador 2 fue quien presiono el boton
    p2++;
  }
}
void setup(){
  Serial.begin(9600);//inicia la comunicacion serial
  pinMode(2,INPUT);//pines para los pulsadores
  pinMode(3,INPUT);
  pinMode(13,OUTPUT); //pin del led del centro
  //pin del buzzer
  //pines de la pantalla
}
void loop(){
  inicio();
  comparar();
  Serial.println("Jugador1 / Jugador2");//imprime el marcador
  Serial.println(""+String(p1)+" "+String(p2));
}