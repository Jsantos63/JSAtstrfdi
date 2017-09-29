/*Talos electronics
 * Detector de Tarjetas para kit RFID
*/

//Librerias Necesarias
#include <SPI.h>
#include <Wire.h>
#include <RFID.h>


/*
Conexiones PinOut:
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D9
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D8
3.3V            3.3V         3.3V
*/

//Se definen los pines SDA y RESET
#define SDA_DIO   10
#define RESET_DIO 9

RFID RC522(SDA_DIO, RESET_DIO); //Se crea la instancia del la clase RC522

void setup() 
{
  SPI.begin(); 
  Serial.begin(9600);
  RC522.init();
}

void loop() 
{
if (RC522.isCard())
    {
      RC522.readCardSerial();
      Serial.print("Tarjeta detectada: ");

      
      for(int i=0;i<5;i++)
      {
        Serial.print(RC522.serNum[i],HEX);
        Serial.print(" ");
      }
      Serial.println("");
    }

}
