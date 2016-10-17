#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

float temperatura = 0;
float fluxo = 20;

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

						temperatura+=1;
						if(temperatura>500)
							temperatura= 0;
						fluxo-=1;
						if(fluxo<0)
							fluxo=20;
						conversaoTemp << temperatura << " " << fluxo;
						resposta= conversaoTemp.str();
						cout << resposta << endl;
					}

					else if(pedido == "mudar"){

					}

					else
						resposta= "Erro";
					new_sock << resposta;
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

