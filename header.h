#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

void NameConfig( char **name );

int PortNumber( char *file ); 

char *Droot( char *file ); 

int Server( char *route, int fdsocket, int port );

int Socket (int port);

char *Child( int acceptfd, char *route );

char *GetRequest ( char *buffer, char *file, char *type, long *longitud, char *route );

char *PostRequest ( char *buffer, char *file, char *type, long *longitud, char *route );

#endif
