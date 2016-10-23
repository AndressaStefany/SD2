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
    while(!fim){
        try
        {
            // andressa 192.168.0.6
            ClientSocket client_socket ( "192.168.0.53", 5000 );
            string resposta;
            try
            {
                client_socket << "sensores";
                client_socket >> resposta;

                double temperatura, fluxo, tempo;
                stringstream ss;
                ss << resposta;
                ss >> temperatura >> fluxo >> tempo;
                w->setTemp(temperatura);
                w->setFluxo(fluxo);
                w->setTempo(tempo);
                sleep(1);
            }
            catch ( SocketException& ) {}
        }
        catch ( SocketException& e )
        {
            cout << "Exception was caught:" << e.description() << "\n";
        }
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
