#include <WiFi.h>
#include <HTTPClient.h>

String ssid = "";
String password = "";
String site = "";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Kullanıcıdan Wi-Fi SSID
  Serial.println("Enter Wi-Fi SSID:");
  while(ssid == "") {
    if(Serial.available()) {
      ssid = Serial.readStringUntil('\n');
      ssid.trim();
    }
  }

  // Kullanıcıdan Wi-Fi şifresi
  Serial.println("Enter Wi-Fi Password:");
  while(password == "") {
    if(Serial.available()) {
      password = Serial.readStringUntil('\n');
      password.trim();
    }
  }

  // Kullanıcıdan site URL
  Serial.println("Enter target website URL:");
  while(site == "") {
    if(Serial.available()) {
      site = Serial.readStringUntil('\n');
      site.trim();
    }
  }

  // Wi-Fi bağlantısı
  WiFi.begin(ssid.c_str(), password.c_str());
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(site.c_str());

    int httpCode = http.GET();
    if (httpCode > 0) {
      WiFiClient* stream = http.getStreamPtr();
      uint8_t buffer[512]; // Chunk boyutu
      while (stream->available()) {
        int len = stream->readBytes(buffer, sizeof(buffer));
        // buffer işleme yok, sadece indiriyoruz → internet tüketimi
      }
      Serial.println("Chunk downloaded from site");
    } else {
      Serial.println("HTTP GET failed, code: " + String(httpCode));
    }

    http.end();
  } else {
    Serial.println("Wi-Fi disconnected, retrying...");
    WiFi.begin(ssid.c_str(), password.c_str());
  }

  delay(10); 
}
