#include <iostream>
#include "Stack.h"
using namespace std;
class Evaluador{
public:
	Stack infija;
	Stack pila;
	Stack posfija;
	
	Evaluador(char* expresion){
		infija.setPila(expresion);
		infija.deploy(infija.getSize(0));
	}
};
