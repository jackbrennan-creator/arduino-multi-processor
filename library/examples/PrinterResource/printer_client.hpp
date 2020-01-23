#pragma once
#include <DataFlow.h>

typedef class printer_client: public node
{
  public:
    const byte printer_control_port = 1;
    const byte printer_text_port    = 2;
    
    void acquire_printer()
    {
      send_to(this_node(), printer_node_id, printer_control_port);
    }

    void print_value(String caption, int value)
    {
      String value_string = String(value);
      send_int_to(caption.length() + value_string.length(), printer_node_id, 2);
      send_string(caption     );
      send_string(value_string);
    }

    void print_value(String caption, float value)
    {
      String value_string = String(value);
      send_int_to(caption.length() + value_string.length(), printer_node_id, 2);
      send_string(caption     );
      send_string(value_string);
    }

    void print_value(String caption, double value)
    {
      String value_string = String(value);
      send_int_to(caption.length() + value_string.length(), printer_node_id, 2);
      send_string(caption     );
      send_string(value_string);
    }
    
    void print_line(String s)
    {
      send_int_to(s.length(), printer_node_id, 2);
      send_string(s);
    }
    
    void release_printer()
    {
      send_int_to(-1, printer_node_id, printer_text_port);
    }

  private:
  
    void send_string(String s)
    {
      for (int i = 0; i < s.length(); i = i + 1)
        send_to((byte)s[i], printer_node_id, 2);
      
    }
};
