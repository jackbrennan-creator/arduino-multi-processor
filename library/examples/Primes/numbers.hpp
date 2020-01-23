#pragma once
#include <DataFlow.h>

typedef class numbers: public node
{
  public:
    connection output;

    numbers(connection numbers_output): output(numbers_output) {} 
    
    void run()
    {
      byte number = 2;
      while (true)
      {
        send_to(number, output);
        delay(100);
        number = number + 1;
      }
    }
};
