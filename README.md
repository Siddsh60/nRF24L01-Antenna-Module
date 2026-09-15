nRF24L01-Antenna-Module
An Arduino-based wireless communication system built using two nRF24L01 2.4 GHz RF transceiver modules. One Arduino operates as a transmitter while another operates as a receiver, allowing digital messages to be encoded into packets, transmitted wirelessly, received, and displayed through the Serial Monitor.

The nRF24L01 is a wireless RF transceiver capable of both transmitting and receiving data in the 2.4 GHz ISM frequency band.
In this project, two nRF24L01 modules communicate with each other: Arduino TX → nRF24L01 → Wireless RF Signal → nRF24L01 → Arduino RX
The Arduino communicates with the nRF24L01 through the SPI (Serial Peripheral Interface) protocol.

Components

- 2× Arduino Uno
- 2× nRF24L01 transceiver modules
- nRF24L01 adapter boards
- Jumper wires
- USB cables
- Computer with Arduino IDE

How It Works

1) Arduino creates the message
The transmitter Arduino receives a message through the Serial Monitor. The program stores the message as digital data that can be sent to the nRF24L01.

2)  Arduino communicates with the nRF24L01 using SPI communication protocol

Important connections include:

- CE – enables the nRF24L01's transmit or receive mode
- CSN – selects the nRF24L01 for SPI communication
- SCK – SPI clock signal
- MOSI – sends data from the Arduino to the nRF24L01
- MISO – sends data from the nRF24L01 back to the Arduino
- IRQ – interrupt output indicating certain radio events
- 
3) The transmitter nRF24L01 converts the digital data into an RF signal and transmits it through its antenna. The project uses one of the nRF24L01's available channels in the 2.4 GHz ISM band. The transmitter and receiver must use matching communication settings, including the same address and channel.

4) The receiver nRF24L01 antenna detects the incoming RF signal. The module processes the received signal and recovers the transmitted digital packet.

5) The receiving Arduino reads the packet from the nRF24L01 through SPI. The received message is then printed to the Arduino Serial Monitor.

The complete communication path is therefore:

User Input
↓
Transmitter Arduino
↓
SPI
↓
nRF24L01 Transmitter
↓
2.4 GHz RF Transmission
↓
nRF24L01 Receiver
↓
SPI
↓
Receiver Arduino
↓
Serial Monitor

## nRF24L01 Pinout

| Pin | Purpose |
|-----|---------|
| GND | Ground |
| VCC | Power |
| CE | Enables transmit/receive modes |
| CSN | SPI chip select |
| SCK | SPI clock |
| MOSI | Arduino → nRF24L01 data |
| MISO | nRF24L01 → Arduino data |
| IRQ | Interrupt signal from nRF24L01 |

Adapter Board
An nRF24L01 adapter board is used between the Arduino power supply and RF module.
The adapter includes:

- 3.3 V voltage regulation
- Decoupling capacitors
- Protection components

The regulator converts the Arduino's 5 V supply into the stable 3.3 V supply required by the nRF24L01, while the decoupling capacitors help reduce supply-voltage fluctuations.

Transmitter:
1. Initializes the nRF24L01
2. Configures the RF channel and address
3. Enters transmit mode
4. Reads a message from the Serial Monitor
5. Places the message into a data buffer
6. Sends the packet wirelessly

Receiver:
1. Initializes the nRF24L01
2. Configures the same RF channel and compatible address
3. Enters receive mode
4. Waits for an incoming packet
5. Reads the received data
6. Displays the message on the Serial Monitor

## Result

The completed system allows text entered on one Arduino to be transmitted wirelessly to another Arduino using two nRF24L01 RF transceivers.

This demonstrates a complete embedded wireless communication chain:

**Digital Data → SPI → RF Transmission → RF Reception → SPI → Digital Data**
