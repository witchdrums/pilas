#include "Stack.h"
class Evaluador{
private:
	char *infija; // apunta al arreglo char de la expresion
	int infijaSize = 0; // tamaño de ese arreglo
	Stack pila;	//pilas
	Stack posfija;
	
public:
	void inicializarEvaluador(char* expresion, int expresionSize){
		infija = expresion;
		infijaSize = expresionSize;
		extraerOperadores(infijaSize);
		
		return;
	}
	void extraerOperadores(int i){
		if (i == 0){
			return;
		}else{
			extraerOperadores(--i);
			switch ( *(infija + i) ){
				case '(':
				case ')':
				case '^':
				case '*':
				case '/':
				case '+':
				case '-':
					pila.push( *(infija + i) );
					break;
				default:
					break;
			}
		}
	}
	
	void paso4(){ // pasar contenidos de pila a posfija
		if (pila.isEmpty()){
			return;
		}else{
			if ( pila.getCima() == '(' ){
				pila.pop();
			}else{
				posfija.push(pila.getCima());
				pila.pop();	
			}
			paso4();
		}
	}
	void evaluar(int i){ // i = 0
		if (i == infijaSize){
			paso4();
			return;
		}else{
			if ( *(infija + i) > 47 && *(infija + i) < 58){	// PASO 1
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
						if ( pila.getCima() != '^' && pila.getCima() != '*' && pila.getCima() != '/' ){
							pila.push(*(infija + i));
						}else{
							posfija.push(pila.getCima());
							pila.pop();
							--i;
						}
						break;
					case '+':
					case '-':
						if ( pila.getCima() == '('){
							pila.push(*(infija + i));
						}else{
							posfija.push(pila.getCima());
							pila.pop();
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
	void paso3(){ // pasar contenido de pila hasta topar con (
		if (pila.getCima() == '('){
			pila.pop();
			return;
		}else{
			posfija.push(pila.getCima());
			pila.pop();
			paso3();
		}
	}

	Stack getPostfija(){
		return posfija;
	}
	Stack getPila(){
		return pila;
	}

	
	void clearInfija(){
		
	}
	
	int clearStacks(){
		if ( pila.clear() ){
			if ( posfija.clear() ){
				return 1;
			}else{
				return 2;
			}
		}else{
			return 3;
		}
	}
	
};

