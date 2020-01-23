#include <DataFlow.h>
#include "printer_client.hpp"

typedef class client1: public printer_client
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
        print_line("Debugging is twice as hard as writing the code in the first place.");
        print_line("Therefore, if you write the code as cleverly as possible,");
        print_line("you are, by definition, not smart enough to debug it");
        print_line("--Brian Kernighan");
      release_printer();
    }
    
    void print_section_2()
    {
      acquire_printer();
        print_line("Don't call it 'code' Brian! Coding implies encryption.");
        print_line("'Source text' should be written as clearly as possible,");
        print_line("and never encrypted.");
        print_line("--Me");
      release_printer();
    }
};
