#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001"; // Must match TX

void setup() {
  Serial.begin(9600);

  radio.begin();

  radio.setPALevel(RF24_PA_LOW);

  radio.setChannel(108);

  radio.openReadingPipe(0, address);

  radio.startListening(); // RX mode

  Serial.println("RX ready. Waiting for messages...");
}

void loop() {
  if (radio.available()) {
    char buffer[32] = ""; // buffer for received message

    radio.read(&buffer, sizeof(buffer));

    Serial.print("Received: ");

    Serial.println(buffer);
  }
}
