CC=gcc
ARGS=-pthread -lncurses -ansi -std=c99 -O
CLEAN=rm -f

all: client server

client: client.c gui.h asciiarts.h
	$(CC) $(ARGS) -o client client.c gui.c asciiarts.c

server: server.c
	$(CC) $(ARGS) -o server server.c
	
clean:
	$(CLEAN) client server
