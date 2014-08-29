# This is a variable
CC=g++ -std=c++11


all: client server

client: client.c
	$(CC) -c client.c
	$(CC) -o client client.o -lzmq -lczmq
	

server:  server.c
	$(CC) -c server.c
	$(CC) -o server server.o -lzmq -lczmq

clean:
	rm -f client.o server.o client server *~


#$ LD_LIBRARY_PATH=/usr/local/lib
#$ export LD_LIBRARY_PATH
#$ ./example