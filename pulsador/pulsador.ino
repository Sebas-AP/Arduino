void setup() {
  // put your setup code here, to run once:
  //Se coloca INPUT porque estamos recibiendo informacion
  pinMode(13,OUTPUT);//Pin para el led
  pinMode(3, INPUT); //Pin para cerrado
  pinMode(2, INPUT); //Pin para abierto
  Serial.begin(9600); //Se inicializa el puerto serial

}

int up=0; //Se inicializa cerrado
int down=0;//Se inicializa abierto

void loop() {
  // put your main code here, to run repeatedly:
  
  up= digitalRead(3); //Se leera que que esta pasando en el pin 3 
  down= digitalRead(2);//Se leera que que esta pasando en el pin 2
  //Serial.println(down); //Para mostrar cerrado
  Serial.println(up); //Para mostrar abierto
  if(up==0){
    digitalWrite(13,HIGH);
  }
  if(down==1){
    digitalWrite(13,LOW);
  }
}
