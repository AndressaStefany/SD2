// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class

#include "Socket.h"

using namespace std;

class ClientSocket : private Socket
{
 public:

  ClientSocket ( string host, int port );
  virtual ~ClientSocket(){};

  const ClientSocket& operator << ( const string& ) const;
  const ClientSocket& operator >> ( string& ) const;

};


#endif
