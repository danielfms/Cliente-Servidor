//  Hello World client
#include <czmq.h>
#include <string>
#include <iostream>

using namespace std;

int main (int argc, char ** argv)
{
    
    zctx_t *context = zctx_new (); //Caja negra provee acceso al medio de paso de mensajes
    void *requester = zsocket_new(context, ZMQ_REQ); // crea socket
    zsocket_connect (requester, "tcp://192.168.8.156:5555"); // decir puerto al socket, del ejemplo el vaso.
    
    //creates an empty message
    zmsg_t* request= zmsg_new();

    if(strcmp(argv[1],"find")==0){
        zmsg_addstr(request,"Find");
        zmsg_addstr(request,argv[2]);
    }else if(strcmp(argv[1],"add")==0){
        zmsg_addstr(request,"Add");
        zmsg_addstr(request,argv[2]);
        zmsg_addstr(request,argv[3]);
        }else{
            cout<<"error!\n";
        }
    

    //Sends message  request thorugh socket requester
    zmsg_send(&request,requester);
    zmsg_t* resp=zmsg_recv(requester);

    zmsg_print(resp);
    //printmsg(resp);

 
    zctx_destroy(&context);
 

    return 0;
}




//gcc -I/home/utp/cs/zmq/include -c client.c
//gcc -L/home/utp/cs/zmq/lib -o client client.o -lzmq
// ./client