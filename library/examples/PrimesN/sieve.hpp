#pragma once
#include <DataFlow.h>

typedef class sieve: public node
{
  public:
    const byte input_port = 1;
    connection output, printer;
    
    static const byte max_primes = 100;
    int               primes[max_primes];
    byte              next_prime = 0;

    sieve(connection sieve_output, connection printer_output): 
      output(sieve_output), printer(printer_output) 
    {
    }
    
    void run()
    {
      int prime = receive_int_on(input_port);
      digitalWrite(13, HIGH);
      add_prime(prime);
      while (true)
      {
        int  value = receive_int_on(input_port);
        bool is_prime = true;
        for (byte i = 0; i < next_prime; i = i + 1)
          if (value % primes[i] == 0)
          {
            is_prime = false;
            break;
          }
        if (is_prime) add_prime(value);
      }
    }

    void add_prime(int prime)
    {
      if (next_prime < max_primes)
      {
        primes[next_prime] = prime;
        next_prime = next_prime + 1;
        send_to(0, printer.node, 0);
        send_int_to(prime, printer);
      }
      else if (this_node() < max_node) send_int_to(prime, output);
    }
};
