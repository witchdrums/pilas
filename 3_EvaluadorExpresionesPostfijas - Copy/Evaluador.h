#include "Stack.h"
class Evaluador{
private:
	char *infija;
	int infijaSize = 0;
	Stack pila;
	Stack posfija;
	
public:
	void setInfija(char* expresion, int expresionSize){
		infija = expresion;
		infijaSize = expresionSize;
		
		evaluar(0);
		return;
	}
	void paso4(){
		if (pila.isEmpty()){
			return;
		}else{
			if ( pila.getTop() == '(' ){
				pila.pop();
			}else{
				posfija.push( pila.pop2() );	
			}
			paso4();
		}
	}
	void evaluar(int i){
		if (i == infijaSize){
			paso4();
			return;
		}else{
			if ( *(infija + i) > 64 && *(infija + i) < 91){	// PASO 1
				posfija.push(*(infija + i));
			}else if (pila.isEmpty()){	//PASO 2.a
				pila.push(*(infija + i));
			}else{  //PASO 2.b
				switch ( *(infija + i) ){
					case '(':
					case '^':
						pila.push(*(infija + i));
						break;
					case '*':
					case '/':
						if ( pila.getTop() != '^' && pila.getTop() != '*' && pila.getTop() != '/' ){
							pila.push(*(infija + i));
						}else{
							posfija.push( pila.pop2() );
							--i;
						}
						break;
					case '+':
					case '-':
						if ( pila.getTop() == '('){
							pila.push(*(infija + i));
						}else{
							posfija.push( pila.pop2() );
							--i;
						}
						break;
					case ')':
						paso3();
						break;
				}
			}
			evaluar(++i);
		}
	}
	void paso3(){
		if (pila.getTop() == '('){
			pila.pop();
			return;
		}else{
			posfija.push( pila.pop2() );
			paso3();
		}
	}

	Stack getPostfija(){
		return posfija;
	}
	
};

