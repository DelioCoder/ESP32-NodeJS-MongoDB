#include "DHT.h"

DHT dht(5, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Prueba del sensor DHT11");
  //Preparar la libreria para comunicarse con el sensor.
  dht.begin();
}

void loop() {
    // put your main code here, to run repeatedly:
    //Esperar entre mediciones un tiempo de 2 segundos
    delay(2000);
    //Leer la humedad usando el método READHUMIDITY
    float humedad = dht.readHumidity();
    //Ler la temperatura usando el metodo READTEMPERATURE
    float temperatura = dht.readTemperature();
    //Revisar que los resultados sean valores numericos válidos.
    //Evaluando si la comunicación es correcta
    if (isnan(humedad) || isnan(temperatura)) {
      Serial.println("Falla al leer el sensor DHT11!");
      return;
    }
    // Imprimir el resultado en el monitor serial
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.print(" % ");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" *C");
}
