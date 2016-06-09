#include "header.h"

void NameConfig (char **name)
{

  *name = malloc ( sizeof (char) * strlen (optarg) );   //We saved the size of the config file
  strcpy( *name, optarg );

}


int PortNumber ( char *file )
{

  char buffer[800];
  memset( buffer, 0, 800 );

  char *buf;
  int port; 
  int fd;

  fd = open ( file, O_RDONLY );
  read( fd, buffer, sizeof (buffer) );
  close(fd);

  if( !strncmp ( buffer, "port", 4 ) )
    {
      buf = strtok( buffer, "=" );       // first Token 
      buf = strtok( NULL, "\n" );        // second token
      port = atoi(buf);
    }
                                                                                                         
  return port;

}

char* Droot ( char *file )
{

  char buffer[800];
  memset( buffer, 0, 800 );
  int fd;

  fd = open( file, O_RDONLY );
  read( fd, buffer, sizeof (buffer) );
  close(fd);


  char *buf;

  char *buf2 = "/";

  char *buf3 = malloc( 300 * sizeof (char) );


  if( strncmp ( buffer, "droot", 5) )
    {

      buf = strtok( buffer, "/" );

      buf = strtok( NULL, "\n" );

      strcpy( buf3, buf2 );
      strcat( buf3, buf );


    }

  return buf3;


}

