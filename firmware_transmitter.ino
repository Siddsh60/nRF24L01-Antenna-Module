#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001"; // Must match RX

void setup() {
  Serial.begin(9600);

  radio.begin();

  radio.setPALevel(RF24_PA_LOW);

  radio.setChannel(108);

  radio.openWritingPipe(address);

  radio.stopListening(); // TX mode

  Serial.println("TX ready. Type something and press Enter.");
}

void loop() {
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n'); // read until Enter

    message.trim(); // remove any trailing whitespace

    if (message.length() > 0) {
      char buffer[32]; // nRF24L01 max payload ~32 bytes

      message.toCharArray(buffer, 32);

      bool ok = radio.write(&buffer, sizeof(buffer));

      if (ok) {
        Serial.println("Sent: " + message);
      } else {
        Serial.println("Send failed");
      }
    }
  }
}
