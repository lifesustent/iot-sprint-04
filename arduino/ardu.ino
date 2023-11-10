#include <ArduinoJson.h>
#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 5 // Pino ao qual o sensor DHT22 está conectado
#define DHTTYPE DHT22 // Tipo do sensor DHT (DHT22 ou DHT11)

DHT dht(DHTPIN, DHTTYPE);

int AlertaTempBaixa = 8;
int AlertaTempAlta = 13;
int TempBaixa = 0;
int TempAlta = 35;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  pinMode(AlertaTempBaixa, OUTPUT);
  pinMode(AlertaTempAlta, OUTPUT);

  dht.begin();

  lcd.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
  lcd.print("Umidade:");
  
  // Inicializar a comunicação serial com uma taxa de 9600 bps
  Serial.begin(9600);
}

void loop() {
  float temperatura = dht.readTemperature() / 10;
  float umidadePercent = dht.readHumidity() / 100;

  // Criar um objeto JSON
  StaticJsonDocument<200> jsonDocument;
  jsonDocument["temperatura"] = temperatura;
  jsonDocument["umidade"] = umidadePercent;

  // Serializar o JSON para uma string
  String jsonString;
  serializeJson(jsonDocument, jsonString);

  // Enviar as leituras para o Node-RED via porta serial
  Serial.println(jsonString);

  // Exibir leituras no LCD
  lcd.setCursor(13, 0);
  lcd.print("    ");
  lcd.setCursor(13, 0);
  lcd.print(temperatura);
  
  lcd.setCursor(8, 1);
  lcd.print("    ");
  lcd.setCursor(8, 1);
  lcd.print(umidadePercent);

  // Enviar as leituras para o Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C, Umidade: ");
  Serial.print(umidadePercent);
  Serial.println("%");

  // Atualizar os alertas conforme necessário
  if (temperatura >= TempAlta) {
    digitalWrite(AlertaTempBaixa, LOW);
    digitalWrite(AlertaTempAlta, HIGH);
  } else if (temperatura <= TempBaixa) {
    digitalWrite(AlertaTempBaixa, HIGH);
    digitalWrite(AlertaTempAlta, LOW);
  } else {
    digitalWrite(AlertaTempBaixa, LOW);
    digitalWrite(AlertaTempAlta, LOW);
  }

  delay(1000);
}
