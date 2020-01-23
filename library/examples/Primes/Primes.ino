#include <DataFlow.h>

#include "printer.hpp"
#include "numbers.hpp"
#include "sieve.hpp"

const byte printer_node =  min_node + 0;
const byte numbers_node =  min_node + 1;
const byte first_sieve  =  min_node + 2;

void setup()
{
  init_dataflow();
  switch (this_node())
  {
    case printer_node: activate_node(new printer());                                        break;
    case numbers_node: activate_node(new numbers(link(first_sieve)));                       break;
    default          : activate_node(new sieve(link(this_node() + 1), link(printer_node))); break;
  }
}

void loop()
{
}
