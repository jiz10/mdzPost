#include "header.h"

char* Child (int acceptfd, char *route)
{

  int fd;
  int varRead;
  int varRead3;

// for resource
  long length = 0;
  char file[256];
  char type[256];

// for response
  char *state;
  char header[256];
  char *version = "HTTP/1.1";

  char buffer[8000];            	//request
  memset ( buffer, 0, sizeof buffer );
  char* diff=malloc(4*sizeof(char));
  
  char buffer2[800];
  memset ( buffer2, 0, sizeof buffer2 );


  char *name = malloc ( 256 * sizeof (char) );


  if ( ( varRead = read ( acceptfd, buffer, sizeof(buffer) ) ) > 0 )
    {
      memset( type, 0, sizeof type );
      memset( file, 0, sizeof file );
	  strncpy(diff,buffer,4);
		

		if ((strncmp(diff, "GET", 3 ))== 0) {
					printf("\nlo manejo yo GET\n"); 
					name = GetRequest(buffer, file, type, &length,route);

		}else if((strncmp(diff,"POST",4))== 0){
					printf("\nlo manejo yo POST\n");
					name = PostRequest(buffer, file, type, &length,route);

		}else{
				state = "500 INTERNAL SERVER ERROR\n";
				write(acceptfd,state,strlen(state));
				//exit(0);
				close(acceptfd);
		
		}


		if ((fd = open(file,O_RDONLY)) <0){
			state = "404 NOT FOUND\n";
			write(acceptfd,state,strlen(state));
			close (fd);
			close(acceptfd);


		}
		else {
			state = "200 OK";
			varRead3 = snprintf(header, sizeof header, "%s %s\nContent-Length: %ld\nContent-Type: %s\n\n", version, state, length, type);
			write(acceptfd, header, varRead3);
			while((varRead3 = read(fd, buffer2, sizeof buffer2)) > 0){
			
				write(acceptfd, buffer2, varRead3);
				memset(buffer2, 0, sizeof buffer2);
			}
	
				close(fd);
				close(acceptfd);
		}
	}	// fin if leido	

	
return name;

} // fin funcion

