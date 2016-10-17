#include "mainwindow.h"
#include <QApplication>

#include <thread>
#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

MainWindow* w;
bool fim= false;

void Comunica()
{
    try
    {
        ClientSocket client_socket ( "192.168.0.53", 30000 );
	//ClientSocket client_socket ( "192.168.0.6", 30000 );

        string resposta;

        try
        {
            while(!fim){
                client_socket << "sensores";
                client_socket >> resposta;

                double x, y;
                string a;
                stringstream ss;
                ss << resposta;
                ss >> x >> y;
                w->setTemp(x);
                w->setFluxo(y);
                sleep(1);
            }
        }
        catch ( SocketException& ) {}
    }
    catch ( SocketException& e )
    {
        cout << "Exception was caught:" << e.description() << "\n";
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w= new MainWindow;
    w->show();
    thread socket(Comunica);
    fim= !a.exec();
    socket.join();
    return 0;
}
