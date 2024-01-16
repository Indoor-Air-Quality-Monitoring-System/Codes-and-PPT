 #include "MQ135.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


const int aqsensor = 28; // Assuming the MQ135 is connected to analog pin A0
const int greenLed = 14; // Green LED connected to pin 14
const int yellowLed = 3; // Yellow LED connected to pin 3
const int redLed = 2;    // Red LED connected to pin 2
const int buzzer = 11;   // Buzzer connected to pin 11

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
  pinMode(greenLed, OUTPUT); // Set the green LED pin as an output
  pinMode(yellowLed, OUTPUT); // Set the yellow LED pin as an output
  pinMode(redLed, OUTPUT);    // Set the red LED pin as an output
  pinMode(buzzer, OUTPUT);    // Set the buzzer pin as an output
  
  Wire.begin(); // Initialize I2C for SDA on I04 and SCL on I05
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();
}

void loop() {
  MQ135 gasSensor = MQ135(aqsensor); // Read MQ135 analog outputs at A0 and store it in ppm
  float ppm = gasSensor.getPPM();

  Serial.print("Air Quality: ");
  Serial.println(ppm); // Print value of ppm

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Air Quality: ");
  
  // Control LEDs and buzzer based on ppm value
  if (ppm < 0.075) {
    // If ppm is between 100 and 150, turn on green LED
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
    display.println("Good\n");
    display.println(ppm);
    display.display();
  } else if (ppm >= 0.075 && ppm < 0.135) {
    // If ppm is between 150 and 200, turn on yellow LED
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
    display.println("Okayish\n");
    display.println(ppm);
    display.display();
  } else if (ppm >= 0.135) {
    // If ppm is 200 or above, turn on red LED and buzzer
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzer, HIGH);
    display.println("Bad\n");
    display.println(ppm);
    display.display();
  }

  delay(500); // Wait for 500 milliseconds
}
 