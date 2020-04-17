// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 11, en = 10, d4 = 4, d5 = 7, d6 = 8, d7 = 9;
const int ledred = 6, ledblue = 5, ledir = 3, buzzer = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int matlabData;


void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial port to connect. Needed for native USB
  Serial.println("start");
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, driver!");
  pinMode(ledred, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(ledir, OUTPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 2 as an output
  
}

void loop() {
  digitalWrite(ledir, HIGH);
  delay(1000);
  digitalWrite(ledir, LOW);
  delay(1000);
  digitalWrite(ledred, HIGH);
  delay(1000);
  digitalWrite(ledred, LOW);
  delay(1000);
  digitalWrite(ledblue, HIGH);
  delay(1000);
  digitalWrite(ledblue, LOW);
  delay(1000);
  if(Serial.available()>0) // if there is data to read
   {
    matlabData=Serial.read(); // read data    
    
    if(matlabData!=4) {
      tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(1000);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(200);        // ...for 1sec
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Warning");
    }
     else if(matlabData==4){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Yes! Good!!");  
      noTone(buzzer);     // Stop sound...
      delay(1000);        // ...for 1sec 
      
      }
    }
}
