
#include <iostream>
#include <unordered_map> // unordered correspondencia 
#include <string.h>

using namespace std;

class Point{
private:
		double x;
		double y;
		


public:

	Point(void) // Por defecto 
	{
		x = 1.0;
		y = 5.0;
	}
	Point(double p)
	{
		x = p;
		y = p;
	}

	void setX(double newX){
		x=newX;

	}


	void setY(double newY){
		y=newY;
	}

	void print(void) const { // const : hace que este metodo no pueda cambiar los atributos

		cout << '<' << x << ',' << y << '>' << std::endl;
	}


};

class Cadena{
private:



public:

};


int main(void)
{	
	unordered_map<string,int>h;
	h["hola"]=4;
	h.insert(make_pair("mundo",5));
	h.insert(make_pair("hola",14)); //sobreescribe con la llave hola

	auto f= h.find("mundo"); //tipo de dato inferido
	if(f==h.end()){
		cout<<"Key was not found"<<endl;
	}else{|||||||||||||||||||||||||||||
		cout<<"Key was found"<<endl;
		cout<<"Associated value "<<f->second<<endl; // devuelve una pareja en f, accedemos a la llave con first y al valor con second

	}

	cout<<"Size of hashtable "<<h.size()<<endl;

	for(const auto& entry: h){  //referencia entonces lo accedenos con punto, si es un apuntador con ->
		cout<<"("<<entry.first<<" -> "<< entry.second<<")"<<endl;
	}

	/*AVERIGUAR PORQUE SALE 4 Y NO 14
		LEER DOCUMENTACION
	*/
	
	return 0;
}