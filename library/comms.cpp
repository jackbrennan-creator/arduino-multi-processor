#include "Headers/comms.h"
#include <EEPROM.h>

volatile byte  node_id       = 0;
volatile bool  sending       = false;
volatile bool  sent          = false;
volatile bool  receiving     = false;
volatile bool  received      = false;
volatile byte  data          = 0;
volatile byte  sink_and_port = 0;
volatile byte  receiver      = 0;

const byte portd_change_bit  = 0b00000100;
const byte portd_changed_bit = 0b00000100;

void set_node_id()
{
  node_id = EEPROM.read(node_id_addr);
}

void send_pin_change()
{
  if (sending)
    if ((PIND & send_bit) == 0)
    {
      set_bus();
      PCMSK2 = PCMSK2 | received_bit;
    }
    else
    {
      release_bus();
      PCMSK2 = PCMSK2 & ~received_bit;
      sending = !sent;
    }
}

ISR (PCINT2_vect)
{
  if (sending)
  {
    PCMSK2 = PCMSK2 & ~received_bit;
    sent = true;
  }
}

void receive_pin_change()
{
  if (receiving)
    if ((PIND & receive_bit) == 0)
    {
      DDRC = DDRC & ~(sink_bits | port_bits);
      receiver = PINC;
      if (receiver == sink_and_port)
      {
        data  = (PINB & data_lo_bits) | (PIND & data_hi_bits);
        DDRD  = DDRD | received_bit;
        PORTD = PORTD & ~received_bit;
        received  = true;
      }
    }
    else
    {
      DDRD  = DDRD & ~received_bit;
      PORTD = PORTD | received_bit;
      if (received) receiving = false;
    }
}

inline void set_bus()
{
  PORTC = sink_and_port;
  
  PORTB = PORTB & ~data_lo_bits;
  PORTB = PORTB | (data & data_lo_bits);
  
  PORTD = PORTD & ~data_hi_bits;
  PORTD = PORTD | (data & data_hi_bits);
  PORTD = PORTD & ~receive_bit;
  
  DDRB  = DDRB | data_lo_bits;
  DDRC  = DDRC | sink_bits | port_bits;
  DDRD  = DDRD | data_hi_bits;
  DDRD  = DDRD | receive_bit;
}

inline void release_bus()
{
  DDRC  = DDRC & ~(sink_bits | port_bits);
  DDRB  = DDRB & ~data_lo_bits;
  DDRD  = DDRD & ~(data_hi_bits | receive_bit);
  PORTC = PORTC | (sink_bits | port_bits);
  PORTB = PORTB | data_lo_bits;
  PORTD = PORTD | (data_hi_bits | receive_bit);
}

void enable_pin_change_interrupts()
{
  noInterrupts();
    PCIFR = PCIFR & ~portd_changed_bit;
    PCICR = PCICR | portd_change_bit;
  interrupts();
}
