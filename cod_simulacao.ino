// Código do protótipo simulado no tinkercad, precisamos usar componentes genéricos, pois a simulação não possui os componentes específicos



const int lm35 = A1; // Define o pino do sensor de temperatura
const int buzzer = A0; // define o pino do buzzer 1
const int ledV = A2; // Define o pino do led verde
const int ledVe = 12; // Define o pino do led vermelho
const int buzzer2 = 11; // Define o pino do buzzer 2

void setup()
{
  Serial.begin(9600); // Inicia o monitor serial
  delay(1500); // Delay de 1,5 segundos para atuzalização do monitor serial
  pinMode(buzzer, OUTPUT); // Define a entrada do buzzer como saída
  pinMode(ledV, OUTPUT); // Define a entrada do LED vermelho como saída
  pinMode(ledVe, OUTPUT);// Define a entrada do LED verde com saída
  pinMode(buzzer2, OUTPUT); // Define a entrada do buzzer 2 como saída
}

void loop()
{
  int SensorTempTensao=analogRead(lm35);
  float Tensao=SensorTempTensao*5;
  Tensao/=1024;
  float TemperaturaC =(Tensao-0.5)*100; //equação de conversão fe tensão para temperatura
  
 Serial.print("  Temperatura: ");
 Serial.print(TemperaturaC);
 Serial.println("°C");// Imprime a temperatura em Graus Celsius
  
 if (TemperaturaC < 27.0) {
    digitalWrite(ledVe, HIGH); // Acende o LED verde
    digitalWrite(buzzer2,HIGH);//liga o sinal sonoro do buzzer2
    digitalWrite(ledV, LOW); //apaga o LED de alerta
    digitalWrite(buzzer, LOW);// Desliga o sinal sonoro do buzzer
  } else {
    digitalWrite(ledV, HIGH); // Acende o LED de alerta
    digitalWrite(ledVe, LOW);  // Apaga o LED verder
    digitalWrite(buzzer, HIGH);// Liga o sinal sonoro do buzzer
    digitalWrite(buzzer2, LOW);//desliga o sinal sonoro do buzzer2

    delay(1000);
}
  
  delay(1000);
  }
