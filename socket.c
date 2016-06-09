#include "header.h"

int Socket(int port)
{

  struct sockaddr_in direction = { };

  int sfd;
  printf ("Server HTTP\n");
  printf ("Port: %d\n", port);

  sfd = socket ( AF_INET, SOCK_STREAM, 0 );

  if (sfd < -1)
    {
      perror ("Error creating socket\n");
      return -1;
    }

  direction.sin_family = AF_INET;
  direction.sin_port = htons (port);
  direction.sin_addr.s_addr = INADDR_ANY;

  if (bind (sfd, (struct sockaddr *) &direction, sizeof (direction)) == -1)
    {
      perror ("Binding error \n");
      return -1;
    }

  if (listen (sfd, 10) < 0)
    {
      perror ("Listening error \n");
      return -1;
    }

  return sfd;

}                                                                                        
