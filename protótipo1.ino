#include "DHT.h"

// Define o pino do DHT11
#define DHTPIN 13  // Substitua pelo pino correto do sensor DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT (DHT11)

// Define os pinos do LED e do buzzer
const int ledPin = 27;         // Pino do LED (temperatura >= 27 °C)
const int alertLedPin = 26;    // Pino do LED de alerta (temperatura < 2 °C)
const int buzzerPin = 25;      // Pino do buzzer ativo

// Inicializa o sensor DHT
DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0; // Armazena o tempo anterior
const long interval = 5000;       // Intervalo de 1 minuto (60000 ms)

void setup() {
  // Inicializa os pinos como saída
  pinMode(ledPin, OUTPUT);
  pinMode(alertLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Inicializa a comunicação serial
  Serial.begin(115200);

  // Inicia o sensor DHT
  dht.begin();
}

void loop() {
  // Aguarda 2 segundos entre as leituras
  delay(1000);

  // Lê a umidade e a temperatura (em Celsius)
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Verifica se houve falha na leitura
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha ao ler do sensor DHT11!");
    return;
  }

  // Mostra a umidade e a temperatura no monitor serial
  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.print("%  Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Verifica a temperatura
  if (temperature >= 27.0) {
    digitalWrite(ledPin, HIGH); // Acende o LED verde

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      tone(buzzerPin, 500); // Liga o buzzer
      delay(2000); // Apita por 2 segundos
      noTone(buzzerPin); // Desliga o buzzer
    }
  } else {
    digitalWrite(ledPin, LOW);  // Apaga o LED normal
    noTone(buzzerPin);
  }

  // Acende o LED de alerta se a temperatura for menor que 2 °C
  if (temperature < 27.0) {
    digitalWrite(alertLedPin, HIGH); // Acende o LED de alerta
  } else {
    digitalWrite(alertLedPin, LOW);  // Apaga o LED de alerta
    delay(1000);
}
}
