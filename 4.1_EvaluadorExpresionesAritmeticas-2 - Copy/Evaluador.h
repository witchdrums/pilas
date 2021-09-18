/*
TO DO:
		- hay un problema con la creacion de la infija, en la que se incluyen NULLs
*/

#include "Stack.h"

#include <iostream>
using namespace std;
class Evaluador{
private:
	int infijaSize = 0; // tamaño de ese arreglo
	Stack pila;	//pilas
	Stack postfija;
	int resultado;
	
	
public:
	
	void setPostfija(Stack p){
		postfija = p;
		cout<<"evaluador.postfija: ";
		postfija.desplegar(postfija.getSize(0));
	}
	
	
};

//infija: 3+2/(3-1)
//3+2/(2)
//3+1
//4

//post: 3231-/+

/*
postfija invertida:		pila:	operacion:
 +/-1323				
 +/-132					3
 +/-13					32
 +/-1					323
 +/-					3231	3-1 = 2
 +/						322		2/2 = 1
 +						31		3+1 = 4


*/
