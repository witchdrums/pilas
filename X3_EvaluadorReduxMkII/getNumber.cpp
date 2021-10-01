#include <iostream>
#include "Pila.h"
using namespace std;

void getNumbers(string, string,int,int, int);
void desplegarInfija();
bool isOperator(char c);
void convertir(int i);
void invertirPostfija(int i);
void paso3();
void paso4();

Pila pila1;
Pila postfija;

string infija[64];
int infijaCharCount;
int expresionSize;

int main(){
	postfija.inicializar();
	pila1.inicializar();
	string expresiones[10] = {
		"12+3/(4*2)", //12342*/+
		"1.432-(22^2*14)/(12+37/21^2)",
		"(1/2)^3+4*(5-6)",
		"1+3"
	};
	getNumbers(expresiones[1], "", expresiones[1].size(), 0, 0);
	desplegarInfija();
	
	convertir(0);
	postfija.desplegar();
	invertirPostfija(0);
}

void invertirPostfija(int i){
	if (postfija.estaVacia()){
		pila1.desplegar();
		return;
	}else{
		pila1.push(postfija.getCima());
		postfija.pop();
		invertirPostfija(++i);
	}
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
void convertir(int i){ //j = infija.getcima() + 1
	if (i == infijaCharCount){
		paso4();
		return;
	}else{
	
		if ( isOperator(infija[i][0]) ){	// PASO 1
			
			postfija.push( infija[i] );
			
			//cout<<"postfijaCima: "<<postfija.getCima()<<endl;
		}else if (pila1.estaVacia()){	//PASO 2.a
			pila1.push( infija[i]);
	
		}else{  //PASO 2.b
			switch ( infija[i][0] ){
				case '(':
				case '^':
					pila1.push( infija[i] );
					break;
				case '*':
				case '/':
					if ( pila1.getCima()[0] != '^' && pila1.getCima()[0] != '*' && pila1.getCima()[0] != '/' ){
						pila1.push( infija[i] );
					}else{
						postfija.push( pila1.getCima() );
						pila1.pop();
						--i;
					}
					break;
				case '+':
				case '-':
					if ( pila1.getCima()[0] == '('){
						pila1.push( infija[i] );
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
		convertir(++i);
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
void desplegarInfija(){
	for (int i = 0; i<64; i++){
		cout<<infija[i];
	}
}
bool isOperator(char c){
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

void getNumbers(string expresion, string help, int size, int i, int j){
	if (i == size){
		if (help != "")
			infija[j++] = help ;
		infijaCharCount = j;
		return;
	}else{
		switch ( expresion[i] ){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
			case '.':
				help += expresion[i];
				break;
			default:
				if (help != "")
					infija[j++] = help ;
				help = expresion[i];
				infija[j++] = help ;
				help="";
		}
	}
	getNumbers(expresion, help, size, ++i, j);
}
