//  Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
    printf ("Connecting to hello world server...\n");
    void *context = zmq_ctx_new (); //Caja negra provee acceso al medio de paso de mensajes
    void *requester = zmq_socket (context, ZMQ_REQ); // crea socket
    zmq_connect (requester, "tcp://192.168.8.156:5555"); // decir puerto al socket, del ejemplo el vaso.
    //Tenemos una parte del socket


    int request_nbr;
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
        char buffer [10];
        printf ("Sending Hello %d...\n", request_nbr);
        zmq_send (requester, "aaaaa", 5, 0); // envia a traves del socket "hello", no bloquea
        zmq_recv (requester, buffer, 10, 0); // recibe una cadena llamada buffer a traves del socket, tambien es bloqueante
        printf ("Received World %d\n", request_nbr);
    }
    zmq_close (requester);  // cierra el socket libera el puerto tcp
    zmq_ctx_destroy (context); // destruye el contexto
    return 0;
}


//gcc -I/home/utp/cs/zmq/include -c client.c
//gcc -L/home/utp/cs/zmq/lib -o client client.o -lzmq
// ./client