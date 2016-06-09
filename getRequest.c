#include "header.h"

char *GetRequest (char *buffer,char *file, char *type, long *length, char *route){

int varRead;
int fd;

char *method;
char *buffer2 = malloc(80000*sizeof(char));
strcpy(buffer2,buffer);

char auxFile[256];
memset(auxFile,0,sizeof auxFile);

char auxFile2[256];
memset(auxFile2,0,sizeof auxFile2);

char file2[256]; // index.html
memset(file2,0,sizeof file2);

char *file3;

char *buf = malloc(256*sizeof(char)); //para nombre
char *ext = malloc(256*sizeof(char)); //para extension

char *name = malloc(256*sizeof(char)); // nombre del archivo

			buf = strtok( buffer, "/" ); 
			method= buf;
			buf = strtok( NULL, " " ); 
			file3 = buf; // almacena nombre del archivo
			//printf("\n3:%s\n",archivo3);

	//apunta a index si no hay parametro
	if ((strncmp (file3, "HTTP/1.1",8))==0){
		
		strncpy (file2, "index.html", 10); // archivo2 solo lo uso para el index.html
		strcpy(file3, file2); // copio index.html a archivo3
	}

	
	

	printf ("El archivo es: %s\n",file3); 
	strcpy(name, file3); 
	strcpy(auxFile, file3); //copia para parsear extension

			ext = strtok( auxFile, "." ); 
			ext = strtok( NULL, " " ); 
			//ext = buf2;

// tipo de extensiones

	if (strcmp(ext,"html") == 0){
			strncpy(type,"text/html",256);
	}

	if (strcmp(ext,"jpg") == 0){
			strncpy(type,"image/jpeg",256);
	}

	if (strcmp(ext,"pdf") == 0){
			strncpy(type,"application/pdf",256);
	}

	if (strcmp(ext,"txt") == 0){
			strncpy(type,"text/plain",256);
	}

	//ruta completa del archivo
	strcpy(auxFile, file3); //aux tiene el nombre del archivo

	strncpy(file3, route, 256);

	strncat(file3, auxFile, 256);

	strcpy(file,file3);

	
	if ((fd = open(file,O_RDONLY)) != -1){ // si el archivo existe
			
			while ((varRead = read(fd,auxFile2,sizeof(auxFile2))) > 0)

					*length = *length + varRead; //terminar con la longitud del archivo
			
					close (fd);
	}
	
	return name;

} // fin funcion
