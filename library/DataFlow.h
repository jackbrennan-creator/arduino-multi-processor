#pragma once

const byte min_node =  0;
const byte max_node = 15;
const byte nodes    = max_node - min_node + 1;

typedef struct connection
{
  byte node, port;
};

typedef class node
{
  public:
    node(){}
    virtual void initialise(){}
    virtual void run(){}
  
};

typedef node* node_ref;

void init_dataflow();

void init_dataflow(byte id);

void send_to(byte value, connection c);

void send_to(byte value, byte sink, byte port);

void send_int_to(int value, connection c);

void send_int_to(int value, byte sink, byte port);

void send_long_to(long value, connection c);

void send_long_to(long value, byte sink, byte port);

void send_float_to(float value, connection c);

void send_float_to(float value, byte sink, byte port);

byte receive_on(byte port);

int receive_int_on(byte port);

int receive_long_on(byte port);

int receive_float_on(byte port);

byte this_node();

void activate_node(node_ref selection);

connection link(byte node, byte port);

connection link(byte node);
