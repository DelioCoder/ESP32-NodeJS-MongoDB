#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

short int httpResponseCode;
const char *ssid = "";
const char *password = "";
String url;

float temperatura, humedad;

DHT dht(5, DHT11);

void Conectar(){
  Serial.println("Se esta conectando a la red Wifi denominada ");
  
  WiFi.begin(ssid, password);
  delay(1000);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi connected");
  Serial.println("IP address");
  Serial.println(WiFi.localIP());
};

void setup() {
  Serial.begin(115200);
  dht.begin();
  Conectar();
}

void Temperatura(){
  humedad = dht.readHumidity();
  temperatura = dht.readTemperature();
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Falla al leer el sensor DHT11!");
    return;
  }
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print(" % ");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");

}

void Enviar(){
  HTTPClient http;
  http.addHeader("Content-Type", "application/json");
  url = "http://192.168.0.7:4000/api/data?Temperatura="+String(temperatura)+"&Humedad="+String(humedad);//IP NodeJS
  http.begin(url.c_str());
  int httpResponseCode = http.POST("");
  delay(300);
  if (httpResponseCode > 0) {
    Serial.printf("Solicitud POST enviada con éxito. Código de respuesta: %d\n", httpResponseCode);
  } else {
    Serial.printf("Error al enviar la solicitud POST. Código de respuesta: %d\n", httpResponseCode);
  }
  http.end();
}

void loop(){
    
    Temperatura();
    Enviar();   
    delay(1000);
    
}
