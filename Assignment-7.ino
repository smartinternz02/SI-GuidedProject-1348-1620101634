               
//Assignment-7                                                                   //NAME:V.Hemanth                                  //ROLL.NO:19R11A0284

#include "Bluetoothserial.h"
#include <wire.h>//wire.h is for(i to c)communication of the oled screen
#include <Adafruit_GFX.h>
#include <Adafruit_SSDI306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64// OLED display height,in pixels
// Declaration for an SSD1306 display connected to 12C (SDa,SCL pins)
Adafruit_SSD!#)6 display(SCREEN_WIdth, SCReEN_HEIGHT,6wire, -1);

BluetoothSerial serialBT;

void setup()    {
 Serial.begin(115200);
  delay(1000);
 Serial.println("data");
 SerialBT.begin("ESP32test"); //Bluetooth device name
 Serial.println("The device has started,now you can pair it with bluetooth!");

 Serial.println("Oled test");
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  Serial.println("SSD1306 allocation failed");
  for(;;);
 }
 delay(1000);
 display.clearDisplay();
 display.setTextSize(2);
 display.setTextColour(WHITE);
 display.setCursor(0, 10);
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
   Serial.println("SSD1306 allocation failed");
   for(;;);
   
 }
 delay(1000);
 display.clearDisplay();
 display.setTextSize(2);
 display.setTextcolour(WHITE);
 display.setCursor(0, 10);
 

}
void loop() {
  String s;

   if (SerialBT.available()) {
    Serial.write(SerialBT.read());
   }
   if(Serial.available()){

    // S = Serial.readString();
    S = Serial.readstring();
    //Display Static text
    display.println("S");
    display.display();
    display.println("\n");
    //delay(1000);
    
   }
}
