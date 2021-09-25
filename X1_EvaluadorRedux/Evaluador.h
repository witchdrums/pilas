class Evaluador{
private:
	string expresionOriginal;
	string comodin;
	int expresionSize;
	int numberCount;
	
	Stack infija;
	Stack postfija;
	Stack pila;

public:
	void inicializar(string expresion){
		expresionOriginal = expresion;
		comodin = "";
		expresionSize = expresionOriginal.size();
		llenarInfija(0);
		countNums(infija.getSize(0));
	}
	void llenarInfija(int i){
		if (i == expresionSize){
			infija.push(comodin);
			infija.deploy(infija.getSize(0));
			return;
		}else{
			switch (expresionOriginal[i]){
				case '(':
				case ')':
				case '^':
				case '/':
				case '*':
				case '+':
				case '-':
					if (comodin != "") 
						infija.push(comodin);
					comodin = expresionOriginal[i];
					infija.push(comodin);
					comodin = "";
					break;
				default:
					comodin += expresionOriginal[i];
					break;
			}
			llenarInfija(++i);
		}
	}
	
	void countNums(int j){
		for (int i  = 0; i<j+1; i++){
			if (isNum(infija.getCima())){
				++numberCount;
			}
			infija.pop();
		}
		cout<<"numberCount = "<<numberCount<<endl;
	}
	
	bool isNum(string str){
		for (int i = 0; i<str.size(); i++){
			if ( !(str[i] > 47 && str[i] < 58 || str[i] == 46) ){
				return false;
			}else if (i == str.size()-1){
				cout<<"str: "<<str<<endl;
				return true;
			}
		}
	}
	
	
	/*
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
	*/
};

/*
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
		
		evaluar(0);
		
		return;
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
	
};
*/

