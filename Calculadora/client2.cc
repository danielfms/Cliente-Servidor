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
    zmq_connect (requester, "tcp://localhost:5555"); // decir puerto al socket, del ejemplo el vaso.
    //Tenemos una parte del socket


    int request_nbr;
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
        char o[256];  // Variable en la que se guarda la operacion que va a enviar el cliente
        char r [256]; // Variable en la que se va a guardar la respuesta del servidor

        printf ("Sending Operation %d...\n", request_nbr);

        scanf("%s",o);  // Leer la operacion, sin espacios. Ej: "45+45"

        zmq_send (requester,o, 256, 0); // Envia a traves del socket la operacion, no bloquea
        zmq_recv (requester, r, 256, 0); // Recibe el resultado del servidor a traves del socket, tambien es bloqueante
        printf ("Received Result: %s\n", r);
    }
    zmq_close (requester);  // cierra el socket libera el puerto tcp
    zmq_ctx_destroy (context); // destruye el contexto
    return 0;
}


//gcc -I/home/utp/cs/zmq/include -c client.c
//gcc -L/home/utp/cs/zmq/lib -o client client.o -lzmq
// ./client