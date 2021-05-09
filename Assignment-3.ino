#include “DHT.h”
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define DHTPIN 4      
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup()
 {
  Serial.begin(9600);
  Serial.println(F(“DHTxx test!”));
   Dht.begin();
     Serial.begin(115200);
delay(1000);
Serial.println(“oled testing”);
  If(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(“SSD1306 allocation failed”);
    for(;;);}
      delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println();
  display.display(); 
   pinMode(2,OUTPUT);
   pinMode(13,OUTPUT);
   Serial.begin(9600);
}

void loop() {
   
  delay(2000);
  float h = dht.readHumidity();
   
  float t = dht.readTemperature();
 
  float f = dht.readTemperature(true);

 
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F(“Failed to read from DHT sensor!”));
    return;
  }
 
  float hif = dht.computeHeatIndex(f, h);
 
  float hic = dht.computeHeatIndex(t, h, false);
  int a= analogRead(15);
delay(2000);
   delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  
    display.print(F(“Humidity: “));
  display.print(h);
    display.print(F(“%  Temperature: “));
  display.print(t);
  display.print(F(“°C “));
  display.print(f);
  display.print(F(“°F  Heat index: “));
  display.print(hic);
 display.print(F(“°C “));
display.print(hif);
  display.println(F(“°F”));
  display.println(“the ldr value is”);
 display.println(a);
 
  If(a<=2500)
{
digitalWrite(2,HIGH);
    display.println(“LIGHT is ON”);
}
Else
{
   digitalWrite(2,LOW);
   display.println(“  LIGHT is OFF”);
} 
If(f>28)
{
  digitalWrite(13,HIGH);
  display.println(“FAN  is ON”);
  
}
else{
  digitalWrite(13,LOW);
  display.println(“FAN is OFF”);
}
}
