#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define TEMP_SENSOR A0
#define FAN_PWM 5
#define BUZZER 6
#define BUTTON 7
#define DHTPIN 8
#define DHTTYPE DHT22 // Use DHT11 if needed

DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(128, 64, &Wire, -1);

bool manualOverride = false;
int fanSpeed = 0;

void setup() {
  pinMode(FAN_PWM, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  dht.begin();
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  displayMessage("System Initializing...");
  delay(2000);
}

void loop() {
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    temperature = analogRead(TEMP_SENSOR) * 0.488; // Approximation
  }

  if (digitalRead(BUTTON) == LOW) {
    manualOverride = !manualOverride;
    delay(300);  // Debounce
  }

  if (manualOverride) {
    fanSpeed = 255; // Full speed
    displayMessage("Manual Mode\nFan: MAX");
  } else {
    fanSpeed = getFanSpeed(temperature);
    displayMessage("Auto Mode\nTemp: " + String(temperature) + " C\nFan: " + String(map(fanSpeed, 0, 255, 0, 100)) + "%");
  }

  analogWrite(FAN_PWM, fanSpeed);

  if (temperature >= 50) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(1000);
}

int getFanSpeed(float temp) {
  if (temp < 30) return 0;
  else if (temp < 35) return 100;
  else if (temp < 40) return 150;
  else if (temp < 50) return 200;
  else return 255;
}

void displayMessage(String msg) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(msg);
  display.display();
}
