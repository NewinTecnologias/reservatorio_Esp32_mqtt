
// Autor: Elismar Silva
//github : Biblioteca SensorUltrasoico (https://github.com/ElismarSilva/SensorUltrasonico)


/*


Sistema de Monitoramento de Reservatório de Água com ESP32 e Sensor Ultrassônico.

Este projeto consiste em um sistema de monitoramento de nível de água em um reservatório utilizando um ESP32 e um sensor ultrassônico HCSR04. O sistema mede a distância 
entre a borda do reservatório e o fundo e converte essa distância em porcentagem, enviando os dados para o Node-RED via MQTT.
*/

// Inclusão de bibliotecas
#include <WiFi.h>
#include <PubSubClient.h>
#include <SensorUltrasonico.h>

// Definições de pinos para o sensor ultrassônico
const int TRIG_PIN = 13;
const int ECHO_PIN = 14;

WiFiClient WIFI_CLIENT;
PubSubClient MQTT_CLIENT;
SensorUltrasonico ultrasonico(TRIG_PIN, ECHO_PIN);

//Credenciais WiFi
const char* ssid = " Seu ssid";
const char* password = "sua senha";

void setup() {
  Serial.begin(115200);
  delay(10);
  
  Serial.println();
  Serial.print("Conectando com ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("WiFi conectado. IP: ");
  Serial.println(WiFi.localIP());

 // Seu servidor 
  MQTT_CLIENT.setServer("seuservidor.com", 1883);
  MQTT_CLIENT.setClient(WIFI_CLIENT);
}

void loop() {
  if (!MQTT_CLIENT.connected()) {
    reconnect();
  }

  // Obtém a distância do sensor ultrassônico em centímetros
float distancia = ultrasonico.distanciaCM();
Serial.print("cm: ");
Serial.println(distancia);
// Ajusta o valor da distância para o novo intervalo desejado (de 0 a 31 cm para 100 a 0)
float distanciaAjustada = map(distancia, 0, 31, 100, 0);

// Converte o valor float ajustado para uma string com 2 casas decimais
char tempFloat[10];
dtostrf(distanciaAjustada, 4, 2, tempFloat);

// Publica o valor da distância ajustada no tópico MQTT
MQTT_CLIENT.publish("distancia", tempFloat);

  // Verifica a inscrição e aguarda eventos MQTT
  MQTT_CLIENT.loop();

  delay(2000); // Aguarda 2 segundos antes de publicar novamente
}

// Reconecta com o broker MQTT
void reconnect() {
  while (!MQTT_CLIENT.connected()) {
    Serial.println("Tentando se reconectar com o Broker MQTT.");
    if (MQTT_CLIENT.connect("")) {
      Serial.println("Conectado ao MQTT.");
      MQTT_CLIENT.subscribe("distancia"); // AQUI SE INSCREVE.
    } else {
      Serial.print("Falha na conexão com o Broker MQTT. Tentando novamente em 5 segundos...");
      delay(5000); // Aguarda 5 segundos antes de tentar novamente
    }
  }
}
