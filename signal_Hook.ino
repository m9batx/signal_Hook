#include "nRF24L01.h"
#include "printf.h"
#include "RF24.h"
#include "RF24_config.h"

#define CE_PIN  9
#define CSN_PIN 10
#define SERIAL_BAUD_RATE 2000000
#define PAYLOAD_SIZE 32
#define MIN_CHANNEL 0
#define MAX_CHANNEL 125

RF24 radio(CE_PIN, CSN_PIN);

const char tohex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
uint64_t pipe = 0x00AA;
byte buff[PAYLOAD_SIZE];
byte addr_len = 2;
byte chan = 0; // Start at channel 0

void set_nrf(byte addr_len, byte len, byte chan) {
    radio.setDataRate(RF24_250KBPS);
    radio.setCRCLength(RF24_CRC_DISABLED);
    radio.setAddressWidth(addr_len);
    radio.setPayloadSize(len);
    radio.setChannel(chan);
    radio.openReadingPipe(1, pipe);
    radio.startListening();
}

void handleSerialInput() {
    if (Serial.available() > 0) {
        byte in = Serial.read();
        if (in == 'w' && chan < MAX_CHANNEL) {
            chan++; // Increase the channel number
            radio.setChannel(chan);
            Serial.print("\nSet chan: ");
            Serial.print(chan);
        }
        if (in == 's' && chan > MIN_CHANNEL) {
            chan--; // Decrease the channel number
            radio.setChannel(chan);
            Serial.print("\nSet chan: ");
            Serial.print(chan);
        }
        if (in == 'q') {
            Serial.print("\n");
            radio.printDetails();
        }
    }
}

void sniffDataOnChannel(byte chan) {
    set_nrf(addr_len, PAYLOAD_SIZE, chan);
    Serial.print("\nListening on Channel: ");
    Serial.print(chan);

    unsigned long startMillis = millis();
    while (millis() - startMillis < 1000) {  // Sniff for 1 second on each channel
        if (radio.available()) {
            radio.read(&buff, sizeof(buff));
            Serial.print("\nData on Channel ");
            Serial.print(chan);
            Serial.print(": ");

            for (byte i = 0; i < sizeof(buff); i++) {
                Serial.print(tohex[buff[i] >> 4]);
                Serial.print(tohex[buff[i] & 0x0f]);
            }
        }
    }
}

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    printf_begin();
    radio.begin();
    set_nrf(addr_len, PAYLOAD_SIZE, chan);
    Serial.println("Starting Data Sniffing...");
}

void loop() {
    sniffDataOnChannel(chan);  // Sniff the current channel

    handleSerialInput();  // Handle user input for changing the channel or querying details
    delay(500);  // Optional: Delay between sniffing each channel to prevent overwhelming the output
}
