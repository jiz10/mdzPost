CC = gcc
CFLAGS = -g
TARGETS = tp4
all: $(TARGETS)

#objetivos: dependencias
#reglas (tab)

tp4: main.c functions.c server.c socket.c child.c getRequest.c postRequest.c
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm -fv $(TARGETS) *.o 
