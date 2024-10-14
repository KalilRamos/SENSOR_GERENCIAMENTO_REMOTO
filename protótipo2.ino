#include <DHT.h> // Inclui biblioteca para o funcionamento do sensor
#include "thingProperties.h" // Inclui a biblioteca necessária para a integração do circuíto com a plataforma Arduino Cloud

const int DHTPIN = 13;
const int DHTTYPE = DHT11;
float temperatura = 0;
float ultimaTemperatura = 0; // Variável para armazenar a última leitura de temperatura

// Define os pinos do LED e do buzzer
const int ledPin = 27;         // Pino do LED (temperatura >= 27 °C)
const int alertLedPin = 26;    // Pino do LED de alerta (temperatura < 2 °C)
const int buzzerPin = 25;      // Pino do buzzer ativo


DHT dht(DHTPIN, DHTTYPE); // Define o tipo do sensor DHT11

void setup() {
  // Inicia o monitor serial
  Serial.begin(9600);
  delay(1500); // Intervalo de 1 segundo e meio entre as impressões no monitor serial

  pinMode(ledPin, OUTPUT);
  pinMode(alertLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  
  // Defined in thingProperties.h
  initProperties();

  // Conecta com o Arduino Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  // Inicia o sensor
  dht.begin();
}

// Função para ler a temperatura do sensor
float lerTemperatura() {
  float temperature = dht.readTemperature(); // Sensor lê a temperatura
  return temperature; // Retorna a temperatura obtida
}

// Função chamada quando há mudança na temperatura
void onDht11Change() {
  Serial.println("Mudança detectada no valor da temperatura!");
  // Aqui você pode implementar qualquer ação que deseja executar quando houver uma mudança na temperatura
  // Por exemplo, enviar uma notificação, atualizar algo no cloud, etc.
}

void loop() {
  // Atualiza os dados no cloud
  ArduinoCloud.update();
  delay(1000); // Intervalo de 1 segundo para a atualização na plataforma de monitoramento
  
  // Lê a temperatura atual
  temperatura = lerTemperatura();
  
  // Verifica se a temperatura mudou significativamente
  if (abs(temperatura - ultimaTemperatura) > 0.5) {
    onDht11Change(); // Chama a função caso a mudança seja detectada
    ultimaTemperatura = temperatura; // Atualiza a última temperatura
  }
  
  // Atualiza o valor da temperatura no cloud com 1 casa decimal
  dht11 = round(temperatura * 10) / 10.0; // Formata a temperatura para 1 casa decimal

  // Imprime a temperatura no monitor serial com °C
  Serial.print("Temperatura (C): ");
  Serial.println(String(temperatura, 1) + " °C");

  delay(1000); // Intervalo de 1 segundo para o loop do código
}
