/*
TO DO:
		- hay un problema con la creacion de la infija, en la que se incluyen NULLs
*/

#include "Stack.h"
#include <iostream>
#include <string>
#include <math.h>
class ConvertidorPostfija{
private:
	string infija[64]; // = {"123", "+", "321"}
	int infijaSize = 0; // tamaño de ese arreglo
	int numOperaciones = 0;
	Stack pila;	//pilas
	Stack posfija;
	Stack pilaDeNumeros;	//pilaDeNumeross
	Stack posfijaInvertida;
	char operacion;
	
	
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
			//numOperaciones = pila.getSize(0);
			return;
		}else{
			extraerOperadores(expresion, --i);
			switch ( expresion[i] ){
				case '^':
				case '*':
				case '/':
				case '+':
				case '-':
					{
						++numOperaciones;
						//cout<<"numOperaciones: "<<numOperaciones<<endl;
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
	void inicializarInfija(string expresion, int size){ //falta version recursiva
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

	//INFIJA A POSTFIJA
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
			if ( esNumero( *(infija + i), 0, infija[i].size() ) && *(infija + i) != ""){	// PASO 1
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
	//INFIJA A POSTFIJA
	
	//EVALUAR POSTFIJA
	void invertirPostfija(){
		if (posfija.isEmpty()){
			cout<<"posfijaInvertida: ";
			posfijaInvertida.desplegar(posfijaInvertida.getSize(0));
			cout<<endl;
			return;
		}else{
			posfijaInvertida.push(posfija.getCima());
			posfija.pop();
			invertirPostfija();
		}
	}
	void evaluar2(int i, int numOperaciones){
		if (i == numOperaciones){
			cout<<"\nRestultado: "<< pilaDeNumeros.getCima()<<endl;
			pilaDeNumeros.pop();
			return;
		}else{
			if ( esNumero( posfijaInvertida.getCima(), 0, posfijaInvertida.getCima().size() ) ){
				//if ( esNumero2( posfija.getCima(), 0, 0, posfija.getCima().size() ) ){
				
				pilaDeNumeros.push( posfijaInvertida.getCima() );
				
			}else if (!posfijaInvertida.isEmpty()){
				
				operacion = posfijaInvertida.getCima()[0]; 	//guardar operador en variable
				
				pilaDeNumeros.push(to_string( operar() )) ; 	//meter resultado de operacion en pilaDeNumeros
				
				++i; 	// incrementar numero de operaciones realizadas
				operacion = '/0'; // limpiar variable
				
			}else{
				
				i = numOperaciones;
				/*si las expresiones y pilas se reinician, en la siguiente expresion, el algoritmo
				no se detendrá incluso si la pila invertida esta vacia, por lo que con este else 
				aseguro que el algoritmo siempre se detenga cuando la invertida esté vacía
				*/
			}
			posfijaInvertida.pop(); // remover cima de la posfija
			evaluar2(i, numOperaciones); // repetir hasta que i == numOperaciones
		}
	}
	float operar(){
		cout<<"operar.operacion: "<<operacion<<endl;
		
		float b = stof(pilaDeNumeros.getCima());
		pilaDeNumeros.pop();
		float a = stof(pilaDeNumeros.getCima());
		pilaDeNumeros.pop();
		
		cout<<"operar.a: "<<a<<endl;
		cout<<"operar.b: "<<b<<endl;	
		switch (operacion){
			case '^': cout<<"evaluador.operar:"<<pow(a,b)<<endl;
				return pow(a,b);
			case '/': cout<<"evaluador.operar:"<<a/b<<endl;
				return a/b;
			case '*': cout<<"evaluador.operar:"<<a*b<<endl;
				return a*b;
			case '+': cout<<"evaluador.operar:"<<a+b<<endl; 
				return a+b;
			case '-': cout<<"evaluador.operar:"<<a-b<<endl;
				return a-b;
		}
	}
	//EVALUAR POSTFIJA
	
	bool esNumero(string str, int j, int size){ //falta version recursiva
		string str3 = "";
		for (int i = 0; i<size; i++){
			if (str[i] > 47 && str[i] < 58 || str[i] == 46){
				str3 += str[i];
				++j;
			}
		}
		if (size == j){
			return true; 
		}
		else{ return false; }
	}

	
	bool isInt(string str, int j, int size){
		string str3 = "";
		for (int i = 0; i<size; i++){
			if (str[i] > 47 && str[i] < 58){
				str3 += str[i];
				++j;
			}
		}
		if (size == j){
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
	
	int getNumOperaciones(){
		return numOperaciones;
	}
	
	int clearStacks(){
		pila.clear();
		posfija.clear();
	}
	void clearInfija(int i){
		if (i == infijaSize){
			return;
		}else{
			infija[i] = "";
			clearInfija(++i);
		}
	}

	
	Stack getPila2(){
		return pilaDeNumeros;
	}
	
	void reiniciar(){
		infijaSize = 0;
		pilaDeNumeros.clear();
		posfija.clear();
		posfijaInvertida.clear();
		operacion = '/0';
		clearInfija(0);
	}
	
};

