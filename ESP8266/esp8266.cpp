#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "FABLABIUB";
const char* password = "fabbersxcansat";
const String apiKey = "2UXHCT0CHJLE2AA6";

WiFiClient client;

void setup() {
  Serial.begin(9600);       // communication with Mega2560
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n Connected to WiFi.");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if (Serial.available()) {
      String data = Serial.readStringUntil('\n');  // Expected format: "25.5,65.2,400,100,2.5"
      data.trim();
      
      float temp, hum, eco2, tvoc, wind;
      int items = sscanf(data.c_str(), "%f,%f,%f,%f,%f", &temp, &hum, &eco2, &tvoc, &wind);

      if (items == 5) {
        String url = "http://api.thingspeak.com/update?api_key=" + apiKey +
                     "&field1=" + String(temp) +
                     "&field2=" + String(hum) +
                     "&field3=" + String(eco2) +
                     "&field4=" + String(tvoc) +
                     "&field5=" + String(wind);

        HTTPClient http;
        http.begin(client, url);
        int httpCode = http.GET();

        if (httpCode > 0) {
          Serial.println("📡 Data sent to ThingSpeak: " + String(httpCode));
        } else {
          Serial.println(" Error sending data");
        }
        http.end();
      }
    }
  }

  delay(20000);  // ThingSpeak allows updates every 15s minimum
}
