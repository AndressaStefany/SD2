#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

float temperatura = 33.4;
float fluxo = 10.40;

int main ( int argc, char* argv[] )
{
	cout<< "running....\n";

	try
	{
		// Create the socket
		ServerSocket server ( 30000 );

		while ( true )
		{

			ServerSocket new_sock;
			server.accept ( new_sock );

			try
			{
				while ( true )
				{
					string pedido, resposta;
					new_sock >> pedido;

					if(pedido == "sensores"){
						cout<<pedido<<endl;
						cout<<temperatura<<endl;
						cout<<fluxo<<endl;

						stringstream conversaoTemp;
						conversaoTemp<<temperatura;
						conversaoTemp>>resposta;

						stringstream conversaoFluxo;
						conversaoFluxo<<fluxo;
						conversaoFluxo>>resposta;
					}

					else if(pedido == "mudar"){

					}

					else
						new_sock << "ERRO";
				}
			}
			catch ( SocketException& ) {}

		}
	}
	catch ( SocketException& e )
	{
		cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}

	return 0;
}

