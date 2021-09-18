/*
TO DO:
		- hay un problema con la creacion de la infija, en la que se incluyen NULLs
*/

#include "Stack.h"
class ConvertidorPostfija{
private:
	string infija[64]; // = {"123", "+", "321"}
	int infijaSize = 0; // tamaño de ese arreglo
	Stack pila;	//pilas
	Stack posfija;
	
	void desplegarPostfija2(int size){
		if (size == 0){
			return;
		}else{
			desplegarPostfija2(--size);
			cout<<*(posfija.getPila() + size);
		}
	}
	
	
public:
	void inicializarConvertidor(string expresion, int expresionSize){
		inicializarInfija(expresion, expresionSize); //WORKS
		extraerOperadores(expresion, expresionSize); //WORKS
		
		return;
	}
	void extraerOperadores(string expresion, int i){
		if (i == 0){
			return;
		}else{
			extraerOperadores(expresion, --i);
			switch ( expresion[i] ){
				case '(':
				case ')':
				case '^':
				case '*':
				case '/':
				case '+':
				case '-':
					{
						string str = "";
						str = expresion[i];
						pila.push( str );
						break;
					}
				default:
					break;
			}
		}
	}
	void inicializarInfija(string expresion, int size){//WORKS
		string str1 = "";
		int j = -1;
		for (int i = 0; i<size; i++){
			switch ( expresion[i] ){
				case '(':
				case ')':
				case '^':
				case '*':
				case '/':
				case '+':
				case '-':
					if (str1 != "") infija[++j] = str1;
					++infijaSize;
					str1 = expresion[i];
					infija[++j] = str1;
					++infijaSize;
					str1 = "";
					break;
				default:
					str1 += expresion[i];
					break;
			}
			if ( i == size - 1){
				infija[++j] = str1;
				++infijaSize;	
			}
		}
		cout<<"infija: ";
		for (int i = 0; i<infijaSize; i++){
			cout<<infija[i];
		}
		cout<<endl;
		//WORKS
	}

	void paso4(){ // pasar contenidos de pila a posfija
		if (pila.isEmpty()){
			return;
		}else{
			if ( pila.getCima() == "(" ){
				pila.pop();
			}else{
				posfija.push(pila.getCima());
				pila.pop();	
			}
			paso4();
		}
	}
	
	void evaluar(int i){ // i = 0, cambio a ifs por que estoy usando string en vez de char, y string no se puede usar con switch
		if (i == infijaSize){
			paso4();
			return;
		}else{
			if ( isInt( *(infija + i), 0, infija[i].size() ) && *(infija + i) != ""){	// PASO 1
				//cout<<"isInt.evaluar.i: "<<*(infija + i)<<endl;
				posfija.push(*(infija + i));
				
			}else if (pila.isEmpty()){	//PASO 2.a
			
				pila.push(*(infija + i));
				
			}else{  //PASO 2.b
			
				if ( *(infija+i) == "(" || *(infija+i) == "^" ){
					
					pila.push(*(infija + i));
					
				}else if ( *(infija+i) == "*" || *(infija+i) == "/" ){
					
					if ( pila.getCima() != "^" && pila.getCima() != "*" && pila.getCima() != "/" ){
						pila.push(*(infija + i));
					}else{
						posfija.push(pila.getCima());
						pila.pop();
						--i;
					}
					
				}else if ( *(infija+i) == "+" || *(infija+i) == "-" ) {
					
					if ( pila.getCima() == "("){
						pila.push(*(infija + i));
					}else{
						posfija.push(pila.getCima());
						pila.pop();
						--i;
					}
					
				}else if (*(infija+i) == ")"){
					
					paso3();
					
				}
			}
			evaluar(++i);
		}
	}
	void paso3(){ // pasar contenido de pila hasta topar con (
		if (pila.getCima() == "("){
			pila.pop();
			return;
		}else{
			posfija.push(pila.getCima());
			pila.pop();
			paso3();
		}
	}
	
	bool isInt(string str, int j, int size){
		string str3 = "";
		/*ALL GOOD:
		cout<<"isInt.str: "<<str<<endl;
		cout<<"isInt.j: "<<j<<endl;
		cout<<"isInt.size: "<<size<<endl;*/
		for (int i = 0; i<size; i++){
			if (str[i] > 47 && str[i] < 58){
				str3 += str[i];
				//cout<<"isInt.str[i]: "<<str[i]<<endl; //GOOD
				++j;
			}
		}
		if (size == j){
			//cout<<"int: "<<str3<<endl;
			return true; 
		}
		else{ return false; }
	}

	Stack getPostfija(){
		return posfija;
	}
	Stack getPila(){
		return pila;
	}
	
	void desplegarPostfija(){
		desplegarPostfija2( posfija.getSize(0) );
	}
	void desplegarPila(){
		desplegarPila2( pila.getSize(0) );
	}
	void desplegarPila2(int size){
		if (size == 0){
			return;
		}else{
			desplegarPila2(--size);
			cout<<*(pila.getPila() + size);
		}
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

