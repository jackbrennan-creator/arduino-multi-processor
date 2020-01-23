#include <DataFlow.h>
#include "printer_client.hpp"

typedef class client3: public printer_client
{
  public:

    void run()
    {
      delay(random(100, 500));
      print_section_1();
      delay(random(100, 500));
      print_section_2();
    }
    
    void print_section_1()
    {
      acquire_printer();
        print_value("Temperature: ", 18);
        print_value("Humidity:    ", 37.4);
      release_printer();
    }
    
    void print_section_2()
    {
      acquire_printer();
        print_value("Temperature: ", 24.25);
        print_value("Humidity:    ", 28.76);
      release_printer();
    }
};
