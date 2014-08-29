# This is a variable
CC=g++ -std=c++11
ZMQ=/home/utp/cs/zmq/
ZMQ_HDRS=$(ZMQ)/include
ZMQ_LIBS=$(ZMQ)/lib


all: client server

client: client.cc
	$(CC) -I$(ZMQ_HDRS) -c client.cc
	$(CC) -L$(ZMQ_LIBS) -o client client.o -lzmq -lczmq

server: server.cc
	$(CC) -I$(ZMQ_HDRS) -c server.cc
	$(CC) -L$(ZMQ_LIBS) -o server server.o -lzmq -lczmq

clean:
	rm -f client.o server.o client server *~



#/home/utp/Descargas
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/utp/cs/zmq/lib