
#include <Wire.h>     // include Arduino Wire library
#include "rgb_lcd.h"  // include Seeed Studio LCD library

rgb_lcd lcd;  // initialize LCD library

void setup() {
  // initialize the LCD with 16 columns and 2 rows:
  lcd.begin(16, 2);
  Serial.begin(9600);

  // move cursor to upper left position (0, 0)
  lcd.setCursor(0, 0);

  // print text on the LCD
  lcd.print("Oxygen Sensor");


/*

  char txt[] = "Seeed Studio 16x2 LCD White on Blue \0";

  lcd.setCursor(0, 1);  // move cursor to second row
  lcd.print(txt);       // print text array
  delay(1000);          // wait a second

  while(txt[0] != '\0')
  {
    byte i = 0;
    lcd.setCursor(0, 1);
    while(txt[i] != '\0') // shift the text array to the left by 1 position
    {
      lcd.write(txt[i]);  // print one character
      txt[i] = txt[i+1];  // shift the text array to the left
      i++;
    }

    lcd.write(' ');  // print a space
    delay(200);      // wait 200 milliseconds
  }

  delay(1000);    // wait a second


  */


  
}

// main loop
void loop() {

int sensorValue = analogRead(A0); // Read analog voltage from A0 pin
float voltage = sensorValue * (3.3 / 1023.0); // Convert analog value to voltage (assuming 3.3V reference voltage)

Serial.print("2");

Serial.print("Sensor value: ");
Serial.print(sensorValue);
Serial.print(", Voltage: ");
Serial.print(voltage, 2); // Print voltage with 2 decimal places
Serial.println(" V");

delay(1000); // Wait for 1 second before taking another reading

lcd.setCursor(0, 1);  // move cursor to position (0, 1)
lcd.print(voltage * 11.8);



/*

  lcd.setCursor(0, 1);  // move cursor to position (0, 1)

  // print number of seconds since the lase reset
  lcd.print( millis()/1000 );

  delay(200);      // wait 200 milliseconds


*/


}

// end of example code.