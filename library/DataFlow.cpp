#include <Arduino.h>
#include "DataFlow.h"
#include "Headers/comms.h"

void init_dataflow()
{
  set_node_id();
  init_dataflow(node_id);
}

void init_dataflow(byte id)
{
  node_id = id;
  pinMode(send_pin,     INPUT);
  pinMode(receive_pin,  INPUT);
  pinMode(received_pin, INPUT);
  enable_pin_change_interrupts();
  release_bus();
}

void send_to(byte value, connection c)
{
  send_to(value, c.node, c.port);
}

void send_to(byte value, byte sink, byte port)
{
  data          = value;
  sink_and_port = sink & sink_bits | (port << 4) & port_bits;
  sending       = true;
  sent          = false; 
  attachInterrupt(digitalPinToInterrupt(send_pin), send_pin_change, CHANGE);
  while (sending);
  detachInterrupt(digitalPinToInterrupt(send_pin));
}

void send_int_to(int value, connection c)
{
  send_int_to(value, c.node, c.port);
}

void send_int_to(int value, byte sink, byte port)
{
	byte buffer[sizeof(int)];
	memcpy(buffer, &value, sizeof(int));
  for (int i = 0; i < sizeof(int); i = i + 1) send_to(buffer[i], sink, port);
}

void send_long_to(long value, connection c)
{
  send_long_to(value, c.node, c.port);
}

void send_long_to(long value, byte sink, byte port)
{
	byte buffer[sizeof(long)];
	memcpy(buffer, &value, sizeof(long));
  for (int i = 0; i < sizeof(long); i = i + 1) send_to(buffer[i], sink, port);
}

void send_float_to(float value, connection c)
{
  send_float_to(value, c.node, c.port);
}

void send_float_to(float value, byte sink, byte port)
{
	byte buffer[sizeof(float)];
	memcpy(buffer, &value, sizeof(float));
  for (int i = 0; i < sizeof(float); i = i + 1) send_to(buffer[i], sink, port);
}

byte receive_on(byte port)
{
  sink_and_port = node_id & sink_bits | (port << 4) & port_bits;
  receiver      = 0;
  receiving     = true;
  received      = false;
  attachInterrupt(digitalPinToInterrupt(receive_pin), receive_pin_change, CHANGE);
  while (receiving);
  detachInterrupt(digitalPinToInterrupt(receive_pin));
  return data;
}

int receive_int_on(byte port)
{
	byte buffer[sizeof(int)];
  int  value;
  for (int i = 0; i < sizeof(int); i = i + 1) buffer[i] = receive_on(port);
  memcpy(&value, buffer, sizeof(int));
  return value;
}

int receive_long_on(byte port)
{
	byte buffer[sizeof(long)];
  long value;
  for (int i = 0; i < sizeof(long); i = i + 1) buffer[i] = receive_on(port);
  memcpy(&value, buffer, sizeof(long));
  return value;
}

int receive_float_on(byte port)
{
	byte buffer[sizeof(float)];
  float value;
  for (int i = 0; i < sizeof(float); i = i + 1) buffer[i] = receive_on(port);
  memcpy(&value, buffer, sizeof(float));
  return value;
}

byte this_node()
{
  return node_id;
}

void activate_node(node_ref selection)
{
  if (selection != nullptr)
  {
    selection->initialise();
    selection->run();
  }
}

connection link(byte node, byte port)
{
  connection c;
  c.node = node;
  c.port = port;
  return c;
}

connection link(byte node)
{
  return link(node, 1);
}
