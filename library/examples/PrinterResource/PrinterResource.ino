#include <DataFlow.h>

const byte printer_node_id =  min_node + 0;

#include "printer.hpp"
#include "client1.hpp"
#include "client2.hpp"
#include "client3.hpp"

const byte client1_node_id =  min_node + 1;
const byte client2_node_id =  min_node + 2;
const byte client3_node_id =  min_node + 3;

void setup()
{
  const int change_this_value_to_alter_the_timing_of_client_operations = 20;
  randomSeed(change_this_value_to_alter_the_timing_of_client_operations);
  init_dataflow();
  switch (this_node())
  {
    case printer_node_id: activate_node(new printer()); break;
    case client1_node_id: activate_node(new client1()); break;
    case client2_node_id: activate_node(new client2()); break;
    case client3_node_id: activate_node(new client3()); break;
  }
}

void loop()
{
}
