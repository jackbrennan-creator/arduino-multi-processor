#include <DataFlow.h>
#include "printer_client.hpp"

typedef class client2: public printer_client
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
        print_line("Computer science is no more about computers");
        print_line("than astronomy is about telescopes.");
        print_line("--Edsger Dijkstra");
      release_printer();
    }
    
    void print_section_2()
    {
      acquire_printer();
        print_line("It should be mandatory that you understand computer science.");
        print_line("--will.i.am");
      release_printer();
    }
};
