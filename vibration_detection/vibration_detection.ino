//
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "vibration-detection-be284-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "GMN1Mpw0QmIGQzo5b4AgiTaxwn6XpcI9jviLgtcc"
#define WIFI_SSID "Phone_hotspot"
#define WIFI_PASSWORD "12345678"
int vib_pin=D5;
int power=D6;
void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  // connect to wifi.
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  pinMode(vib_pin,INPUT);
  pinMode(power,OUTPUT);
  digitalWrite(power,HIGH);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
  int val;
  long data= vibrations();
  Serial.println(data);
  delay(200);
  Firebase.pushFloat("vibration_data", data);
  
  Firebase.setFloat("current_vibration_data", data);
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
}

long vibrations(){
  long value=pulseIn(vib_pin,HIGH);
  return value;
  }
