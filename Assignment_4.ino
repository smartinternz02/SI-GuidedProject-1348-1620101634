//ASSIGNMENT-4                           // NAME:V.Hemanth
                                                                                                                          // ROLL NO:19R11A0284


#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
int LED=2;
int trigpin=5;
int echopin=4;
 int a=7;
 int b=6;
void setup()
{
  pinMode(echopin,INPUT);
   pinMode(trigpin,OUTPUT);
   pinMode(LED,OUTPUT);
 Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device has started, now you can pair it with bluetooth!");
}

void loop()
{
  int Data= (SerialBT.read());
  digitalWrite(trigpin,HIGH);
 delay(1000);
 digitalWrite(trigpin,LOW);
 int duration=pulseIn(echopin,HIGH);
 int distance=(duration*0.0343)/2;
 Serial.print("the distance is");
 Serial.println(distance);
 delay(1000); 
    if (distance>100)
    {
      SerialBT.print("water level is");
      SerialBT.print(distance);
      SerialBT.println(" :NULL");
    }
    else
    {
      SerialBT.print("Water level is");
      SerialBT.print(distance);
      SerialBT.println(" :FULL");
    }
    if (Data==a);
    {
      digitalWrite(LED,HIGH);
      
    }
    if(Data==b)
    {
    digitalWrite(LED,LOW);
   
    } 
  delay(20);
  
}
