//  Hello World client
#include <czmq.h>
#include <string>
#include <iostream>
//Hola
using namespace std;

int main(int argc, char** argv) {
 
  zctx_t *context = zctx_new();
  void *requester = zsocket_new(context, ZMQ_REQ);
  zsocket_connect(requester, "tcp://localhost:5555");

  // Creates an empty message
  zmsg_t* request = zmsg_new();
  
  if (strcmp(argv[1],"find") == 0) {
    zmsg_addstr(request,"Find");
    zmsg_addstr(request,argv[2]);
  } else if (strcmp(argv[1],"add") == 0) {
    zmsg_addstr(request,"Add");
    zmsg_addstr(request,argv[2]);
    zmsg_addstr(request,argv[3]);
  } else {
    cout << "error!\n";
  } 
  
  // Sends message request through socket requester
  zmsg_send(&request,requester);
  
  zmsg_t* resp = zmsg_recv(requester);
  
  zmsg_print(resp);      
         
  zctx_destroy(&context);
 
  return 0;
}







