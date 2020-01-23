#pragma once
#include <DataFlow.h>

typedef class numbers: public node
{
  public:
    connection output;

    numbers(connection numbers_output): output(numbers_output) {} 
    
    void run()
    {
      int number = 2;
      while (true)
      {
        send_int_to(number, output);
        number = number + 1;
      }
    }
};
