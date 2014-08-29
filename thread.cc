#include <iostream>
#include <thread>

using namespace std;

int accum=0;

void square(int x){
	accum= accum + (x*x);
}

/*
void threadFunction(void){
	//cout<<"Thread!!!!!"<<"hello!!!!";
	for(int i=65;i<=3000;i++){
		cout<<i;
	}
}*/
int main(void){
	thread t(square,10);  /// (funcion, parametros)

	
	//cout<<"Main!!!!!"<<"wordl!!!!!!";
	/*for(int i=65;i<=3000;i++){
		cout<<"##";
	}*/
	t.join();  //sincronizar, terminar de ejecutar el hilo para seguir con el return.
	cout<<"Accum's value "<<accum<<endl;
	
	
	return 0;
}