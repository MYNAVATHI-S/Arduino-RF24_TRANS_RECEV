// Transmitter Code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN
const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();  // Set as transmitter
}

void loop() {
  const char text[] = "RF24_OK";
  radio.write(&text, sizeof(text));  // Send message
  delay(1000);  // Wait 1 second
}
