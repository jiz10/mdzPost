#include "header.h"

int main( int argc, char **argv )
{
 int fdsocket; 		//file descriptor del socket
 int option;
 char *route;
 char buffer[800];

 memset ( buffer, 0 , sizeof buffer );

 char *configFile = NULL;
 int port;

 while ( (option = getopt( argc, argv, "f:") ) >= 0 )
  {
   switch (option)
    {
     case 'f': 		//Abrir archivo .conf
      NameConfig (&configFile);
      break;
    }
  }
 
 if (!configFile)
  {
   configFile = "g5.conf";
  }

 port = PortNumber(configFile);   //funciones.c devuelve el puerto
 
 route = Droot(configFile);
 fdsocket = Socket(port);
 Server(route, fdsocket, port);

 return 0;

} 

