#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main ( int argc, char* argv[] )
{
  try
    {

      ClientSocket client_socket ( "192.168.0.53", 30000 );

      std::string reply,texto;
      while(1){
	      try
		{
	          getline(cin,texto);
		  client_socket << texto;
		  client_socket >> reply;
		  std::cout << "Resposta do servidor:\n\"" << reply << "\"\n";	
		}
	      catch ( SocketException& ) {}
      }
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}
