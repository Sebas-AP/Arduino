#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

#define LED_TEMPERATURA 13
#define LED_LUMINOSIDAD 12
#define MOTOR_PIN 9

#define LCD_RS 12
#define LCD_EN 11
#define LCD_D4 5
#define LCD_D5 6
#define LCD_D6 7
#define LCD_D7 8

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializa la pantalla LCD
  lcd.begin(16, 2);

  // Inicializa los pines como salida
  pinMode(LED_TEMPERATURA, OUTPUT);
  pinMode(LED_LUMINOSIDAD, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  // Inicializa el sensor DHT
  dht.begin();
}

void loop() {
  // Lee la temperatura y la humedad del sensor DHT
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  // Si no se ha podido leer el sensor, muestra un mensaje de error
  if (isnan(temperatura) || isnan(humedad)) {
    lcd.setCursor(0, 0);
    lcd.print("Error sensor DHT");
    return;
  }

  // Lee el valor del sensor de luminosidad
  int valorLuminosidad = analogRead(A0);

  // Controla el estado de los LEDs
  if (temperatura > 25) {
    digitalWrite(LED_TEMPERATURA, HIGH);
  } else {
    digitalWrite(LED_TEMPERATURA, LOW);
  }

  if (valorLuminosidad > 500) {
    digitalWrite(LED_LUMINOSIDAD, HIGH);
  } else {
    digitalWrite(LED_LUMINOSIDAD, LOW);
  }

  // Controla la vibración del motor
  if (temperatura > 30) {
    analogWrite(MOTOR_PIN, 255);
  } else if (temperatura < 20) {
    analogWrite(MOTOR_PIN, 0);
  } else {
    analogWrite(MOTOR_PIN, 128);
  }

  // Muestra los valores en la pantalla LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperatura);
  lcd.print(" C");
  lcd.print(" Hum:");
  lcd.print(humedad);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Lum:");
  lcd.print(valorLuminosidad);

  delay(1000);
}
