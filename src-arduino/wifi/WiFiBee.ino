#include <multiprotocolShield.h>
#include <MCP23008.h>
#include <Wire.h>
    
const char ssid[]={"AT+SSID=RaspberryPi"};   // WiFi SSID
const char passwd[]={"AT+PASSWORD=raspberry"}; // WiFi password
static char ip_addr[15];

void setup()
{
  socket0.ON();
  delay(100);
  socket0.setMUX();

  wifi_connect();
  Serial.println(wifi_wait_ip());
}

void wifi_connect()
{
  Serial.begin(115200);
  delay(100);
  while(!Serial);
  Serial.print("+++");
  delay(1000);
  Serial.println(ssid);
  delay(100);
  Serial.println(passwd);  
  delay(100);
  Serial.println("AT+CONNECT");
  delay(500);
}

char * wifi_wait_ip() 
{
  String gotip = "Got IP:";
  String line;
  
  if (ip_addr[0] == '\0') {
    Serial.println("Debug: Wait init");
    while(true) {    // wait until got ip
      line = Serial.readString();
      if line.length
      Serial.println(line);
      if (gotip.equals(line.substring(0,7)))
        break;
    }
    int i = 7;
    while (line[i] != '\0') {
      ip_addr[i-7] = line[i];
      i++;
    }
    Serial.println("Debug: End init");
    return ip_addr;
  }
}

void loop()
{
    Serial.println("Hi! I'm Arduino.");
    delay(1000);
}
