CC = gcc
CFLAGS = -g
TARGETS = mdz
all: $(TARGETS)

#objetivos: dependencias
#reglas (tab)

mdz: main.c functions.c server.c socket.c child.c getRequest.c postRequest.c
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm -fv $(TARGETS) *.o 
