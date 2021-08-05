//#include <SPI.h>
//#include <SD.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <OakOLED.h>


OakOLED oled;

// set up variables using the SD utility library functions:
//Sd2Card card;
//SdVolume volume;
//SdFile root;

// Create a file to store the data
//File myFile;

//const int chipSelect = 4;//pin for the SD Card Adapter

SoftwareSerial BT(7, 8); //Rx,Tx


void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -

  // Bluetooth
  while(!Serial);
  BT.begin(9600);

 //SD Card
  //Serial.print("\nInitializing SD card...");

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  //if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    //Serial.println("initialization failed. Things to check:");
    //Serial.println("* is a card inserted?");
    //Serial.println("* is your wiring correct?");
    //Serial.println("* did you change the chipSelect pin to match your shield or module?");
    //while (1);
  //} else {
    //Serial.println("Wiring is correct and a card is present.");
  //}

  //OLED 
  oled.begin();
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(1);
  oled.setCursor(0, 0);

  oled.println("Initializing heartRate..");
  oled.display();
 
}

void loop() {
  
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('!');
  }
  else{
    
    Serial.println(analogRead(A0));
    oled.println(analogRead(A0));
     
      
  }

  //Write from Serial Monitor to Bluetooth HC06
  if (Serial.available()){
    BT.write(Serial.read());
}  

  //Send data from Bluetooth to Smartphone
  BT.print(Serial.read());
    
  //Wait for a bit to keep serial data from saturating
  delay(1);
}
