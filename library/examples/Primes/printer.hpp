#pragma once
#include <DataFlow.h>

typedef class printer: public node
{
  public:
    const byte input_port = 1;
    
    void initialise()
    {
      Serial.begin(9600);
      while (!Serial);
    }
    
    void run()
    {
      Serial.println("Primes");
      while (true)
      {
        byte prime = receive_on(input_port);
        Serial.println(prime);
      }
    }
};
