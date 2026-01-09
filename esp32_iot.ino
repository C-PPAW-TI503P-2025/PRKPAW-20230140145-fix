#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "NAMA_WIFI_ANDA";
const char* password = "PASSWORD_WIFI_ANDA";

// Ganti 192.168.x.x dengan IP Laptop Anda (cek pakai ipconfig)
const char* serverUrl = "http://192.168.1.7:3001/api/iot/data"; 

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    
    // Data Dummy (Nanti ganti dengan bacaan sensor DHT/LDR)
    float suhu = 25.5 + random(0, 50) / 10.0;
    float kelembaban = 60.0 + random(0, 20) / 10.0;
    int cahaya = random(100, 1000);
    
    // Format JSON
    String payload = "{\"suhu\": " + String(suhu) + 
                     ", \"kelembaban\": " + String(kelembaban) + 
                     ", \"cahaya\": " + String(cahaya) + "}";
    
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");
    
    int httpResponseCode = http.POST(payload);
    
    if(httpResponseCode > 0){
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  }
  
  delay(5000); // Kirim setiap 5 detik
}
