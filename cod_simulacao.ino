const int lm35 = A1;
const int buzzer = A0;
const int ledV = A2;
const int ledVe = 12;
const int buzzer2 = 11;



void setup()
{
  Serial.begin(9600); // Inicia o monitor serial
  delay(1500); // Delay de 1,5 segundos para a atualização do monitor serial
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
  float TemperaturaC =(Tensao-0.5)*100; //equação de conversão de tensão para temperatura em graus celsius
  
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
    digitalWrite(ledVe, LOW);  // Apaga o LED verde
    digitalWrite(buzzer, HIGH);// Liga o sinal sonoro do buzzer
    digitalWrite(buzzer2, LOW);//desliga o sinal sonoro do buzzer2

    delay(1000);
}
  
  delay(1000);
  
  
  }
