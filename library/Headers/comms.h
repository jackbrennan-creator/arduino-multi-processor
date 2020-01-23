#pragma once
#include <Arduino.h>

const byte node_id_addr      = 0;

const byte send_pin          = 2;
const byte receive_pin       = 3;
const byte received_pin      = 4;

//port d
const byte send_bit          = 0b00000100;
const byte receive_bit       = 0b00001000;
const byte received_bit      = 0b00010000;
const byte data_hi_bits      = 0b11100000;

//port c
const byte sink_bits         = 0b00001111;
const byte port_bits         = 0b00110000;

//port b
const int data_lo_bits       = 0b00011111;

extern volatile byte node_id;
extern volatile bool sending;
extern volatile bool sent;
extern volatile bool receiving;
extern volatile bool received;
extern volatile byte data;
extern volatile byte sink_and_port;
extern volatile byte receiver;

void set_node_id();

void send_pin_change();

void receive_pin_change();

inline void set_bus();

inline void release_bus();

void enable_pin_change_interrupts();
