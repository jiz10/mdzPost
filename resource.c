#include "header.h"

char* Resource( char *buffer, char *file, char *type, long *length, char *route )
{
 int varRead;
 int fd;

 char auxFile[256];
 memset( auxFile, 0, sizeof auxFile );

 char auxFile2[256];
 memset( auxFile2 , 0, sizeof auxFile2 );

 char file2[256];
 memset( file2, 0, sizeof file2 );

 char *file3;
 char *buf = malloc( 256 * sizeof(char) );
 char *ext = malloc( 256 * sizeof(char) );

 char *name = malloc( 256 * sizeof(char) );

 buf = strtok( buffer,"/" );
 
 buf = strtok( NULL, " " );

 file3=buf;


 if( (strncmp( file3, "HTTP/1.1", 8) ) == 0 )
  {
   strncpy( file2, "index.html", 10 );
   strcpy( file3, file2 );
  }
 
 strcpy( name, file3);
 strcpy( auxFile, file3);
 
 ext = strtok(auxFile,".");
 ext = strtok(NULL," ");

// extension types

 if( strcmp ( ext,"html" ) == 0 )
  {
   strncpy( type, "text/html", 256 );
  }
 
 if( strcmp ( ext, "jpg" ) == 0 )
  { 
   strncpy( type, "image/jpeg", 256 );
  }

 if( strcmp (ext, "pdf" ) == 0 )
  {
   strncpy( type, "application/pdf", 256 );
  }
 
 if( strcmp (ext, "txt") == 0 )
  {
   strncpy( type, "text/plain", 256 );
  }
 strcpy( auxFile, file3 );
 strncpy( file3, route, 256 );
 strncat( file3, auxFile, 256 );
 strcpy( file, file3 );

 if ( ( fd=open (file, O_RDONLY)) != -1)
  {
   while ((varRead = read(fd, auxFile2, sizeof(auxFile2) ) ) > 0 )
    {
      *length = *length + varRead;
    }
   close(fd);
  }

 return name;
}
   
