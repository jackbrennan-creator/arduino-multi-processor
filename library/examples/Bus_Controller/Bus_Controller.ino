const byte  spare_pin   = A5;
const byte  pulse_width = 12;
const byte  pulse_delay = 8;
const byte  send_pins[] = {2,          3,          4,          A1,         A2,         A3,         A4,         5,          6,          7,          8,          9,          10,         11,         12,         A0        };
const byte  send_bits[] = {0b00000100, 0b00001000, 0b00010000, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000, 0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00000001};
byte* const ports[]     = {&PORTD,     &PORTD    , &PORTD,     &PORTC,     &PORTC,     &PORTC,     &PORTC,     &PORTD,     &PORTD,     &PORTD,     &PORTB,     &PORTB,     &PORTB,     &PORTB,     &PORTB,     &PORTC    };

void setup()
{
  pinMode(spare_pin, OUTPUT);
  for (byte i = 0; i < sizeof(send_pins); i = i + 1) pinMode(send_pins[i], OUTPUT);
  for (byte i = 0; i < sizeof(send_pins); i = i + 1) digitalWrite(send_pins[i], HIGH);
}

void loop()
{
  while (true)
  { 
    PORTD = PORTD & ~send_bits[0];
    delayMicroseconds(pulse_width);
    PORTD = PORTD | send_bits[0];
    delayMicroseconds(pulse_delay);
    
    PORTD = PORTD & ~send_bits[1];
    delayMicroseconds(pulse_width);
    PORTD = PORTD | send_bits[1];
    delayMicroseconds(pulse_delay);
    
    PORTD = PORTD & ~send_bits[2];
    delayMicroseconds(pulse_width);
    PORTD = PORTD | send_bits[2];
    delayMicroseconds(pulse_delay);
    
    PORTC = PORTC & ~send_bits[3];
    delayMicroseconds(pulse_width);
    PORTC = PORTC | send_bits[3];
    delayMicroseconds(pulse_delay);
    
    PORTC = PORTC & ~send_bits[4];
    delayMicroseconds(pulse_width);
    PORTC = PORTC | send_bits[4];
    delayMicroseconds(pulse_delay);
    
    PORTC = PORTC & ~send_bits[5];
    delayMicroseconds(pulse_width);
    PORTC = PORTC | send_bits[5];
    delayMicroseconds(pulse_delay);
    
    PORTC = PORTC & ~send_bits[6];
    delayMicroseconds(pulse_width);
    PORTC = PORTC | send_bits[6];
    delayMicroseconds(pulse_delay);
    
    PORTD = PORTD & ~send_bits[7];
    delayMicroseconds(pulse_width);
    PORTD = PORTD | send_bits[7];
    delayMicroseconds(pulse_delay);
    
    PORTD = PORTD & ~send_bits[8];
    delayMicroseconds(pulse_width);
    PORTD = PORTD | send_bits[8];
    delayMicroseconds(pulse_delay);
    
    PORTD = PORTD & ~send_bits[9];
    delayMicroseconds(pulse_width);
    PORTD = PORTD | send_bits[9];
    delayMicroseconds(pulse_delay);
    
    PORTB = PORTB & ~send_bits[10];
    delayMicroseconds(pulse_width);
    PORTB = PORTB | send_bits[10];
    delayMicroseconds(pulse_delay);
    
    PORTB = PORTB & ~send_bits[11];
    delayMicroseconds(pulse_width);
    PORTB = PORTB | send_bits[11];
    delayMicroseconds(pulse_delay);
    
    PORTB = PORTB & ~send_bits[12];
    delayMicroseconds(pulse_width);
    PORTB = PORTB | send_bits[12];
    delayMicroseconds(pulse_delay);
    
    PORTB = PORTB & ~send_bits[13];
    delayMicroseconds(pulse_width);
    PORTB = PORTB | send_bits[13];
    delayMicroseconds(pulse_delay);
    
    PORTB = PORTB & ~send_bits[14];
    delayMicroseconds(pulse_width);
    PORTB = PORTB | send_bits[14];
    delayMicroseconds(pulse_delay);
    
    PORTC = PORTC & ~send_bits[15];
    delayMicroseconds(pulse_width);
    PORTC = PORTC | send_bits[15];
    delayMicroseconds(pulse_delay);
  }
}
