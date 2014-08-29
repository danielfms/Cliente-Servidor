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
        char buffer [256]; // Variable en la que se guarda la operacion enviada por el cliente
        zmq_recv (responder, buffer, 256, 0);  /// bloquea si no recibe nada
        //buffer[9]='\0';
        int i=0,l=0, resul,f=0; // resul: Se guarda la suma de los operando, f: bandera para separar los dos numeros de la cadena
                                // l: En esta variable se guarda la longitud de la cadena que tiene la operacion

        char s1[256],s2[256]; // Variables para guardar las dos cadenas de cada numero
        char op; // Variable en la que se va a guardar el operador
        l=strlen(buffer); // Tamaño del buffer
        int j=0;
        for (i=0,j=0;i<l;i++){
            char a=buffer[i];
            if(f==0){
                if(a=='+'||a=='-'||a=='*'||a=='/'){
                    op=buffer[i];
                    s1[i]='\0';
                    f=1;
                }else
                    s1[i]=a;
            }else{
                s2[j]=a;
                j++;
            }  
        }
        s2[j]='\0';

        int u1=atoi(s1); 
        int u2=atoi(s2);

        switch(op){
            case '+': resul=u1+u2; 
                      break;
            case '-': resul=u1-u2; 
                      break;
            case '*': resul=u1*u2; 
                      break;
            case '/': resul=u1/u2; 
                      break;
        }


        char r[256];

        sprintf(r,"%d",resul);
        printf("%d %c %d = %s\n",u1,op,u2,r);

        
        printf ("Received: %s\n",buffer); 
        sleep (1);          //  Do some 'work' // simula latencia tiempo en que se demora en enviar y recibir.
        zmq_send (responder,r,256, 0);
    }
    return 0;
}
