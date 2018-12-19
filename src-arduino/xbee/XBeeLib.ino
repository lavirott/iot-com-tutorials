#include <multiprotocolShield.h>
#include <MCP23008.h>
#include <Wire.h>
#include <XBee.h>

XBee xbee = XBee();

// Create an array for holding the data you want to send.
uint8_t payload[] = { 'H', 'i', '!', ' ', 'I', '\'', 'm', ' ', 'A', 'r', 'd', 'u', 'i', 'n', 'o', '.' };

// Specify the address of the remote XBee (this is the SH + SL)
XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x40d6623c);

void setup() {
  socket0.ON();
  delay(100);
  socket0.setMUX();

  Serial.begin(9600);
  delay(1000);
  xbee.setSerial(Serial);
}

void loop() {
  ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
  xbee.send(zbTx);
  delay(2000);
}
