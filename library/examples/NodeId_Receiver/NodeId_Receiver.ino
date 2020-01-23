#include <EEPROM.h>

const byte  send_pin    =   2;
const byte  led_pin     =  13;

const int   id_addr     =   0;
const int   setup_delay = 100;

byte        node_id     =   0;
bool        done        = false;

void setup()
{
  pinMode(send_pin, INPUT );
  pinMode(led_pin,  OUTPUT);
  digitalWrite(led_pin, LOW);
  Serial.begin(9600);
  while (!Serial);
  delay(setup_delay);  
}

void loop()
{
  if (!done)
  {
    if (Serial.available())
    {
      byte addr = Serial.read();
      if (digitalRead(send_pin) == LOW)
      {
        node_id = addr - '0';
        EEPROM.write(id_addr, node_id);
        digitalWrite(led_pin, HIGH);
        done = true;
      }
    }
  }
}
