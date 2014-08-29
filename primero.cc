
#include <iostream>
#include <unordered_map> // unordered correspondencia 
#include <string.h>

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

		std::cout << '<' << x << ',' << y << '>' << std::endl;
	}


};

class Cadena{
private:



public:

};



int main(void)
{	
	std::cout<<"Hello word!!!!!!!"<< std::endl;
    
	Point p, q(5.02);
	
	

	/*

	p.print();
	q.print();

	Point *ptr = &q;

	ptr->print();
	ptr->setX(4);

	*/

	// Creamos tabla  hash , con llave entera y valor de tipo Point

	std::unordered_map<int,Point> h; // para compilarlo g++ -std=c++11 -c primero.cc /  g++ -std=c++11 -o primero  primero.o 
	std::unordered_map<std::string,std::string> hcad;

	h[15] = p;

	h[42] = q;

	std::cout << "Entries in h" << h.size() << std::endl;
	h[42].setX(0.0);
	h[42].print();

	hcad["hola"]="Mundo";	
	hcad["Marvel"]="DC";
	hcad["Daniel"]="Diaz";
	hcad["Steve"]="Ajuasd";
	std::cout << "Valor de la llave hola : " << hcad["hola"] << std::endl;
	std::cout << "Valor de la llave Marvel : " << hcad["Marvel"] << std::endl;	
	std::cout << "Valor de la llave Daniel : " << hcad["Daniel"] << std::endl;	
	std::cout << "Valor de la llave Steve : " << hcad["Steve"] << std::endl;




	return 0;

}

