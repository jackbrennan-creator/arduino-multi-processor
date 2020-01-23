#pragma once
#include <DataFlow.h>

typedef class sieve: public node
{
  public:
    const byte input_port = 1;
    connection output, printer;

    sieve(connection sieve_output, connection printer_output): 
      output(sieve_output), printer(printer_output) 
    {
    }
    
    void run()
    {
      byte prime = receive_on(input_port);
      send_to(prime, printer);
      digitalWrite(13, HIGH);
      while (true)
      {
        byte value = receive_on(input_port);
        if (value % prime != 0 && this_node() < max_node) send_to(value, output);
      }
    }
};
