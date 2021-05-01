#include "SPI.h" // SPI library
#include "MFRC522.h" // RFID library (https://github.com/miguelbalboa/rfid)
const int pinRST = 9;
const int pinSDA = 10;
MFRC522 mfrc522(pinSDA, pinRST); // Set up mfrc522 on the Arduino
void setup() {
  SPI.begin(); // open SPI connection
  mfrc522.PCD_Init(); // Initialize Proximity Coupling Device (PCD)
  Serial.begin(9600); // open serial connection
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
}
String temp;
int j = 0, k = 0;

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) { // (true, if RFID tag/card is present ) PICC = Proximity Integrated Circuit Card
    if (mfrc522.PICC_ReadCardSerial()) { // true, if RFID tag/card was read
      Serial.print("RFID TAG ID:");
      temp = (char *)mfrc522.uid.uidByte;
    }
    Serial.print(temp);
    Serial.println(); // Print out of id is complete.
    delay(100);
    if (temp == "T*]#")
      j++;
    else//if(temp=="⸮E⸮_")
      k++;
      delay(250);
  }
  if (k % 2 == 0 && j % 2 == 0) {
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  Serial.print(k);
  Serial.print(j);
  Serial.println(' ');
}
