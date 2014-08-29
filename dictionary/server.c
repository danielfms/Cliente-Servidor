//  Hello World server

#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int main (void)
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new (); // caja negra
    void *responder = zmq_socket (context, ZMQ_REP); // creando un socket, ZMQ_REP diferente de ZMQ_REQ de client.c
    int rc = zmq_bind (responder, "tcp://*:5555"); // // con bind crea el socket, con connect de client se conecta
    assert (rc == 0); // aborta si rc es cero, no pudo crear el socket

    while (1) {
        char buffer [10];
        zmq_recv (responder, buffer, 10, 0);  /// bloquea si no recibe nada
        buffer[9]='\0';
        printf ("Received %s\n",buffer);
        sleep (1);          //  Do some 'work' // simula latencia tiempo en que se demora en enviar y recibir.
        zmq_send (responder, "World", 5, 0);
    }
    return 0;
}
