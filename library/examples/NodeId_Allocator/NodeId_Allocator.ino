const byte  send_pins[] = {2, 3,4, A1, A2, A3, A4, 5, 6, 7, 8, 9, 10, 11, 12, A0};
const byte  led_pin     =  13;

const int   setup_delay = 500;

void setup()
{
  pinMode(led_pin, OUTPUT);
  for (byte i = 0; i < sizeof(send_pins); i = i + 1) 
  {
    pinMode     (send_pins[i], OUTPUT); 
    digitalWrite(send_pins[i], HIGH  );
  }
  Serial.begin(9600);
  while (!Serial);
  delay(setup_delay);
}

void loop()
{
  for (byte node_id = 0; node_id < sizeof(send_pins); node_id = node_id + 1)
  {
    digitalWrite(send_pins[node_id], LOW);
      delay(1);
      Serial.print((char)(node_id + '0'));
      delay(100);
    digitalWrite(send_pins[node_id], HIGH);
  }
  while(true);
}
