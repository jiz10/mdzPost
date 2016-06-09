#include "header.h"

int Server( char *route, int fdsocket, int port)
{
 struct sockaddr_in direction_cli = { };
 socklen_t direction_cli_len = sizeof direction_cli;
 int acceptfd;
 char buffer[800];
 memset (buffer, 0, sizeof buffer);
 signal(SIGCHLD, SIG_IGN);
 while(( acceptfd = accept ( fdsocket, ( struct sockaddr* ) &direction_cli, &direction_cli_len ) ) > 0 )
  {
   switch (fork())
    {
     case -1:
      perror("Error creating fork \n");
      return -1;   
    
     case 0:
      close(fdsocket);
      Child( acceptfd, route );
      break;
    }
  
   close(acceptfd);
  }
 return 0;
}

