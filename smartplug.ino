// Blynk Configuration
#define BLYNK_TEMPLATE_ID "TMPL3N1hrANIp"
#define BLYNK_TEMPLATE_NAME "SMART PLUG"
#define BLYNK_AUTH_TOKEN "auth_token"

// Include Libraries
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "ssid";         // Replace with your WiFi SSID
char pass[] = "password";  // Replace with your WiFi Password

// Relay Pin Configuration
const int relayPin = 25; // GPIO pin connected to the relay

// Blynk Virtual Pin Handler
BLYNK_WRITE(V0) {
  int relayState = param.asInt(); // Get value from Blynk app (0 or 1)
   Serial.print(relayState);
  if (relayState == 1) {
    digitalWrite(relayPin, HIGH); // Turn Relay ON
    Serial.println("Relay ON");
  } else {
    digitalWrite(relayPin, LOW); // Turn Relay OFF
    Serial.println("Relay OFF");
  }
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.println(WiFi.localIP());

  // Initialize relay pin as OUTPUT
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure relay is OFF initially

  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("ESP32 is ready and connected to Blynk!");
}

void loop() {
  // Run Blynk
  Blynk.run();
   
}
