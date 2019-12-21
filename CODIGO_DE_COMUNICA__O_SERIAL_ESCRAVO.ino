
#include <Wire.h>                //Inclui a biblioteca I2C

#define ledPin 7

//Função auxiliar para processar os dados recebidos do Master
void receiveEvent()
{
  while (Wire.available()){
  
      // le o byte recebido
    char received = Wire.read();

    // se o byte recebido for igual a 0, apaga o LED
    if (received == 0) {
      digitalWrite(ledPin, LOW);
    }

    // se o byte recebido for igual a 1 acende o LED
    if (received == 1) {
      digitalWrite(ledPin, HIGH);
    }
  
  }
}


void setup()
{
  pinMode(ledPin, OUTPUT);             //Saída para o LED
  digitalWrite(ledPin, LOW);
  
  Wire.begin(15);                //Barramento I2C do endereço 15
  Serial.begin(9600);

}

void loop()
{
  Wire.onReceive(receiveEvent);  //Recepção de dados (chama função auxiliar)
  delay(100);
}
