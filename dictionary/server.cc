//  Hello World server

#include <czmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unordered_map>
#include <string>
#include <cassert>
#include <iostream>


using namespace std;

typedef unordered_map<string,string> DictType;

//Server's state
DictType dict;

void dispatch(zmsg_t* incmsg,zmsg_t* outmsg){
    zmsg_print(incmsg);
    string operation(zmsg_popstr(incmsg));
    string w(zmsg_popstr(incmsg));
    if(operation.compare("Find")==0){
        //Look up a word in dict
        
        if(dict.count(w)>0){
            //The word is in the dict
            string meaning=dict[w];

            zmsg_addstr(outmsg,"found");
            zmsg_addstr(outmsg,meaning.c_str());
        }else{
            zmsg_addstr(outmsg,"Word does not exists!!!");
        }
    }else if (operation.compare("Add")==0){
        //Add a word to dict
      
        string meaning(zmsg_popstr(incmsg));

        dict[w]=meaning;

        zmsg_addstr(outmsg,"added");
    }else{
        zmsg_addstr(outmsg,"Error");
    }
}

int main (void)
{
    //  Socket to talk to clients
    zctx_t *context = zctx_new ();
    void *responder = zsocket_new (context, ZMQ_REP); // creando un socket, ZMQ_REP diferente de ZMQ_REQ de client.c
    zsocket_bind (responder, "tcp://*:5555"); // // con bind crea el socket, con connect de client se conecta

    while (1) {
        zmsg_t* incmsg=zmsg_new();
        zmsg_t* outmsg=zmsg_new();
        incmsg=zmsg_recv (responder); 
        dispatch(incmsg,outmsg);

        zmsg_send(&outmsg,responder);
        
    }
    return 0;
}
