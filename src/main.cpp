#include <Arduino.h>
#include <HsHWebsocket/HsHWebsocket.h>

#define SERVER_URL "https://echo.websocket.org/"

void setup() {
  Serial.begin(115200);

  webSocket.onConnect([]() {
    Serial.println("WS - Connected");
  });

  webSocket.onDisconnect([]() {
    Serial.println("WS - Disconnected");
  });

  webSocket.onFrame([](char* data, size_t length) {
    Serial.printf("WS - Received: %s\n", data);
  });

  webSocket.onError([](WsError error) {
    Serial.printf("WS - Error: %d. Message: %s\n", error.code, error.message);
  });

  webSocket.listen(SERVER_URL);
  // webSocket.listen(SERVER_URL, "/path");
  // webSocket.listen(IPAddress(192, 168, 0, 1), 80, "/path");
  // webSocket.listen(IPAddress(192, 168, 0, 1), 80);
}

void loop() {
  vTaskDelay(1);
}