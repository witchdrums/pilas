#include <iostream>
#include "Pila.h"
using namespace std;

void llenarInfija(string, int, int, string);
bool isNum(char c);
void paso3();
void paso4();
void convertir(int i, int j);

Pila infija;
Pila postfija;
Pila pila1;

int main(){
	infija.inicializar();
	postfija.inicializar();
	pila1.inicializar();
	string expresiones[10] = {
		"12+3/(4*2)", //12342*/+
		"1.432-(22^2*14)/(12+37/21^2)",
		"(1/2)^3+4*(5-6)",
		"1+3"
	};
	
	//llenarInfija(expresiones[1], expresiones[1].size(), 0, "");
	
	convertir(expresiones[1], 0, expresiones[1].size());
	//infija.desplegar();
	
	postfija.desplegar();
}
void paso4(){ // pasar contenidos de pila a posfija
	if (pila1.estaVacia()){
		return;
	}else{
		if ( pila1.getCima()[0] == '(' ){
			pila1.pop();
		}else{
			postfija.push(pila1.getCima());
			pila1.pop();	
		}
		paso4();
	}
}
void convertir(string expresion, int i, int j){ //j = infija.getcima() + 1
	if (i == j){
		paso4();
		return;
	}else{
	
		if ( isNum(expresion[i]) ){	// PASO 1
			
			
			
			postfija.push( infija.getCima() );
			
			//cout<<"postfijaCima: "<<postfija.getCima()<<endl;
		}else if (pila1.estaVacia()){	//PASO 2.a
			cout<<"fuck"<<endl;
			pila1.push( infija.getCima() );
			

		}else{  //PASO 2.b
			switch ( infija.getCima()[0] ){
				case '(':
				case '^':
					pila1.push( infija.getCima() );
					cout<<"pila1Cima: "<<pila1.getCima()<<endl;
					break;
				case '*':
				case '/':
					if ( pila1.getCima()[0] != '^' && pila1.getCima()[0] != '*' && pila1.getCima()[0] != '/' ){
						pila1.push( infija.getCima() );
					}else{
						postfija.push( pila1.getCima() );
						pila1.pop();
						--i;
					}
					break;
				case '+':
				case '-':
					if ( pila1.getCima()[0] == '('){
						pila1.push( infija.getCima() );
					}else{
						postfija.push( pila1.getCima() );
						pila1.pop();
						--i;
					}
					break;
				case ')':
					paso3();
					break;
			}
		}
		infija.pop();
		convertir(++i, j);
	}
}
void paso3(){ // pasar contenido de pila hasta topar con (
	if (pila1.getCima()[0] == '('){
		pila1.pop();
		return;
	}else{
		postfija.push(pila1.getCima());
		pila1.pop();
		paso3();
	}
}

bool isNum(char c){
	switch (c){
		case '(':
		case ')':
		case '^':
		case '/':
		case '*':
		case '+':
		case '-':
			return false;
		default:
			return true;
	}
}

/*
void llenarInfija(string expresion, int size, int i, string help){
	if (i == size){
		return;
	}else{
		switch (expresion[i]){
			case '(':
			case ')':
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
				if (help != ""){ infija.push(help);	}
				help = expresion[i];
				infija.push(help);
				help = "";
				break;
			default:
				help += expresion[i];
		}
		if (i == size - 1){ infija.push(help); }
		llenarInfija(expresion, size, ++i, help);
	}	
}

*/

