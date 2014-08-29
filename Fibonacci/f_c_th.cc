#include <iostream>
#include <thread>
#include <chrono> 
#include <unordered_map>

using namespace std;

std::unordered_map<int,int> ht;

void fib(int n,int *f){
	if(n<2){
		*f=n;
	}else{
		int f1,f2;
		fib(n-1,&f1);
		fib(n-2,&f2);

		*f=f1+f2;
	}

	
}

int f_c(int n){
	int f;
	if(n<2){
		fib(n,&f);
		return f;
	}
	if(ht.count(n)>0)
		return ht[n];

	int f1,f2;
	thread t1(fib,n-1,&f1);
	thread t2(fib,n-2,&f2);
	t1.join();	
	t2.join();
	f=f1+f2;
	ht[n]=r;

	return f;
}


int main(){


	int n;
	cout<<"Ingrese el numero al cual se le va a calcular fib(n): ";
	cin>>n;

	chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

	int f=f_c(n);

	end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);
    cout <<elapsed_seconds.count() << "s"<<endl;

	cout<<"Fibonacci de "<<n<<": "<<f<<endl;
	return 0;
}