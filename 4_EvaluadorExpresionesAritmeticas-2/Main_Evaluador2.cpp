/*
TO DO:
	1. Validacion [1]: si ya hay una infija; ya no se puede meter otra hasta reiniciar con [6]
	2. Pasar todos los operadores a la pila antes de eliminarlos durante la conversion
*/

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "Evaluador.h"
using namespace std;

void aMayusculas(char* str, int, int);
void desplegar(char* str, int);
int countChars(char* expresion, int i);
void leerEleccion(int&);
void ingresarInfija();
void consultarInfija();
void infijaAPostfija();
void mostrarCimaDePila();
void desplegarPila();
void reiniciar();

void initEvaluador();

Evaluador evaluador;
char expresion[128];
int expresionSize;

int main(){
	int eleccion;
	do{
		system("CLS");
		cout<<"Evaluador de Expresiones Aritm�ticas\n"<<
		"--------------------------------\n"<<
		"Eliga una opci�n: \n\n"<<
		"[1] Ingresar expresion infija con numeros \n"<<
		"[2] Consultar expresion ingresada \n"<<
		"[3] Convertir infija a postfija\n"<<
		"[4] Mostrar cima de pila de operadores\n"<<
		"[5] Mostrar operadores en pila\n"<<
		"[6] Vaciar pila y reiniciar expresiones\n"<<
		"[7] Mostrar resultado final\n"<<
		"[8] Salir\n"<<
		"\n Elecci�n > ";	
		cin>>eleccion;
		
		leerEleccion(eleccion);
		
	} while( eleccion != 8);
	return 0;
}

void leerEleccion(int &eleccion){
	switch (eleccion){
		case 1:
			ingresarInfija();
			
			break;
		case 2:
			cout<<"\n Infija en memoria << ";
			consultarInfija();
			break;
		case 3:
			infijaAPostfija();
			break;
		case 4:
			mostrarCimaDePila();
			break;
		case 5:
			desplegarPila();
			break;
		case 6:
			reiniciar();
			break;
		/*
		case :
			break;
		case :
			break;
		case :
			break;
		case :
			break;
			*/
		default:
			cout<<"ELECCION << "<<eleccion<<endl;
	}
	system("pause");
}

void mostrarCimaDePila(){
	if (!evaluador.getPila().isEmpty()){
		cout<<" Cima de pila de operadores << "<< evaluador.getPila().getCima();
	}else{
		cout<<" La pila de operadores est� vac�a"<<endl;
	}
}

void reiniciar(){
	cout<<"\n----[6] Vaciar pila y reiniciar-\n"<<endl;
	int result = evaluador.clearStacks();
	switch (result){
		case 1:
			cout<<" La pila ha sido vaciada"<<endl;
			cout<<" La expresion postfija se ha reiniciado\n"<<endl;
			break;
		case 2:
			cout<<" La pila ha sido vaciada"<<endl;
			cout<<" ATENCION: La expresion postfija ya estaba vac�a\n"<<endl;
			break;
		case 3:
			cout<<" ATENCION: La pila ya estaba vacia"<<endl;
			cout<<" ATENCION: La expresion postfija ya estaba vac�a\n"<<endl;
			break;
	}
}

void desplegarPila(){
	cout<<"PILA: ";
	evaluador.getPila().desplegar( evaluador.getPila().getSize(0) );
	cout<<"SIZE: "<<evaluador.getPila().getSize(0);
	cout<<endl;
}

void ingresarInfija(){
	cin.ignore();
	cout<<"  Ingrese infija >> ";
	cin.getline(expresion, 128);
	
	expresionSize = countChars(expresion, 0);
	aMayusculas(expresion, 0, expresionSize);
	
	evaluador.inicializarEvaluador(expresion, expresionSize); 
	cout<<"\n\n";
}

void consultarInfija(){
	desplegar(expresion, expresionSize);
	cout<<"\n";
}

void infijaAPostfija(){
	desplegarPila();
	evaluador.getPila().clear();
	desplegarPila();
	
	cout<<"\n Expresion infija <<";
	consultarInfija();
	evaluador.evaluar(0);
	cout<<"\n Expresion postfija <<";
	desplegar(evaluador.getPostfija().getPila(), evaluador.getPostfija().getSize(0));
	cout<<endl;
}

void desplegar(char *expresion, int size){
	if (size == 0){
		return;
	}else{
		desplegar(expresion, --size);
		cout<<*(expresion + size);
	}
}

int countChars(char* expresion, int i){
	if ( *(expresion + i) ==  '\0'){
		return i;
	}else{
		countChars(expresion, ++i);
	}
}

void aMayusculas(char* str, int i, int size){
	if ( i == size ) {
		return;
	}else{
		if (str[i] > 96 && str[i] < 123 ){
			str[i] -= 32;
		}
		aMayusculas(str, ++i, size);
	}
}

int getSize(char *expresion, int i){ // 0
	if ( *(expresion + i) ==  '\0'){
		return i;
	}else{
		getSize(expresion, ++i);
	}
}





