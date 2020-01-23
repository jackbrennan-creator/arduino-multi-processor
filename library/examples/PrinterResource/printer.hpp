#include <DataFlow.h>

typedef class printer: public node
{
  public:
    const byte control_port = 1;
    const byte text_port    = 2;
        
    void initialise()
    {
      Serial.begin(9600);
      while (!Serial);
    }
    
    void run()
    {
      Serial.println("Printer Running");
      while (true)
      {
        byte client_id = receive_on(control_port);
        serve_client(client_id);
      }
    }
    
    void serve_client(byte client_id)
    {
      Serial.print("Output by client "); 
      Serial.println(client_id);
      Serial.println("-----------------------"); 
      int line_length = receive_int_on(text_port);
      while (line_length >= 0)
      {
        while (line_length > 0)
        {
          char ch = (char)receive_on(text_port);
          Serial.print(ch);
          line_length = line_length - 1;
        }
        Serial.println();
        line_length = receive_int_on(text_port);
      }
      Serial.println("-----------------------"); 
    }
};
