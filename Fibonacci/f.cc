#include <iostream>
#include <chrono> 

using namespace std;

int fib(int n){
	if(n<2)
		return n;

	return fib(n-1)+fib(n-2);
}

int main(){

	int n;
	cout<<"Ingrese el numero al cual se le va a calcular fib(n): ";
	cin>>n;
	chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

	int f=fib(n);

	end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);
    cout <<elapsed_seconds.count() << "s"<<endl;

 	cout<<"Fibonacci de "<<n<<": "<<f<<endl;
	return 0;
}