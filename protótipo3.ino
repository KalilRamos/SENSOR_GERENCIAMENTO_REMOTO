//CIRCUITO INTEGRADO AO ARDUINO CLOUD

#include <DHT.h> // Inclui biblioteca para o sensor DHT11
#include "thingProperties.h" // Inclui a biblioteca para a integração com a plataforma Arduino Cloud

// Definição dos pinos e tipos de sensores
#define DHTPIN 13  // Pino do sensor DHT11
#define DHTTYPE DHT11  // Define o tipo de sensor DHT (DHT11)

// Define os pinos do LED e do buzzer
const int ledPin = 27;         // Pino do LED (temperatura >= 27 °C)
const int alertLedPin = 26;    // Pino do LED de alerta (temperatura < 2 °C)
const int buzzerPin = 25;      // Pino do buzzer ativo

// Variáveis de controle de tempo
unsigned long previousMillis = 0; // Armazena o tempo anterior
const long interval = 5000;       // Intervalo de 5 segundos (5000 ms)

float temperatura = 0; // Variável para armazenar valor da temperatura
float ultimaTemperatura = 0; // Variável para armazenar a última leitura de temperatura

// Inicializa o sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicia o monitor serial
  Serial.begin(115200);
  delay(1500); // Intervalo de 1 segundo e meio entre as impressões no monitor serial

  // Inicializa os pinos como saída
  pinMode(ledPin, OUTPUT);
  pinMode(alertLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Inicia o sensor DHT11
  dht.begin();

  // Defined in thingProperties.h
  initProperties();

  // Conecta com o Arduino Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

// Função para ler a temperatura do sensor
float lerTemperatura() {
  float temperature = dht.readTemperature(); // Sensor lê a temperatura
  return temperature; // Retorna a temperatura obtida
}

// Função para ler a umidade do sensor
float lerUmidade() {
  float humidity = dht.readHumidity(); // Sensor lê a umidade
  return humidity; // Retorna a umidade obtida
}

// Função chamada quando há mudança na temperatura
void onDht11Change() {
  Serial.println("Mudança detectada no valor da temperatura!");
  // Aqui você pode implementar qualquer ação quando houver uma mudança na temperatura
}

// Função principal do loop
void loop() {
  // Atualiza os dados no cloud
  ArduinoCloud.update();
  delay(1000); // Intervalo de 1 segundo para a atualização na plataforma de monitoramento

  temperatura = lerTemperatura(); // circuito lê a temperatura
  float humidity = lerUmidade(); // circuito lê a humidade

  // Verifica se houve falha na leitura
  if (isnan(humidity) || isnan(temperatura)) {
    Serial.println("Falha ao ler do sensor DHT11!");
    return;
  }

  // Mostra a umidade e a temperatura no monitor serial
  Serial.print("Umidade: ");
  Serial.print(humidity); // printa a variável umidade no monitor serial
  Serial.print("%  Temperatura: ");
  Serial.print(temperatura); // printa a variável temperatura
  Serial.println("°C");

  // Atualiza o valor da temperatura no cloud com 1 casa decimal
  dht11 = round(temperatura * 10) / 10.0; // Certifique-se de que 'dht11' está definida corretamente no thingProperties.h

  // Verifica a temperatura e controla o LED e o buzzer
  if (temperatura >= 27.0) { // Condição para quando a temperatura for maior ou igual a 27 °C
    digitalWrite(ledPin, HIGH); // Acende o LED

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      tone(buzzerPin, 500); // Liga o buzzer
      delay(2000); // Apita por 2 segundos
      noTone(buzzerPin); // Desliga o buzzer
    }
  } else {
    digitalWrite(ledPin, LOW);  // Apaga o LED
    noTone(buzzerPin); // Desliga o sinal sonoro do buzzer
  }

  // Acende o LED de alerta se a temperatura for menor que 2 °C
  if (temperatura < 2.0) {
    digitalWrite(alertLedPin, HIGH); // Acende o LED de alerta
  } else {
    digitalWrite(alertLedPin, LOW);  // Apaga o LED de alerta
  }

  delay(1000); // Delay de 1 segundo para o loop do código
}
