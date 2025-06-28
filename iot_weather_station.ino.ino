#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// OLED display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Weather Station");
  display.display();
  delay(2000);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("°C  Humidity: ");
  Serial.print(hum);
  Serial.println("%");

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Weather Station");
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(temp, 1);
  display.print(" C");
  display.setCursor(0, 45);
  display.print(hum, 1);
  display.print(" %");
  display.display();

  delay(3000);
}
