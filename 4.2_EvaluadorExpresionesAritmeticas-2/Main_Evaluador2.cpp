/*
TO DO:
	1. Validacion [1]: si ya hay una infija; ya no se puede meter otra hasta reiniciar con [6]
	2. Pasar todos los operadores a la pila antes de eliminarlos durante la conversion
	3. cambiar los stacks a STRING para mantener numeros compuestos
		123 != 1, 2 y 3
		
		tomar
*/

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "Convertidor2.h"
#include "Evaluador2.h"
using namespace std;

void aMayusculas(string* str, int, int);
//void desplegar(string* str, int);
int countstrings(string* expresion, int i);
void leerEleccion(int&);
void ingresarInfija();
void consultarInfija();
void infijaAPostfija();
void mostrarCimaDePila();
void desplegarPila();
void reiniciar();
void infijaEstatica();
void resultado();

void initConvertidor();

ConvertidorPostfija convertidor;
Evaluador evaluador;


//string expresion = "2+3";
//string expresion = "1.432-(22^2*14)/(12+37/21^2)";
//string expresion = "(1/2)^3+4*(5-6)"; //(1/2)^3+4*(5-6)	31+2/(3-1)
//string expresion = "3+2/(3-1)";
//a-(b^c*d)/(b+c/a^d)
//1-(2^3*4)/(2+3/1^4)

string expresion;
int expresionSize;

int main(){
	int eleccion;
	//infijaEstatica();
	do{
		system("CLS");
		cout<<"Evaluador de Expresiones Aritméticas\n"<<
		"--------------------------------\n"<<
		"Eliga una opción: \n\n"<<
		"[1] Ingresar expresion infija con numeros \n"<<
		"[2] Consultar expresion ingresada \n"<<
		"[3] Convertir infija a postfija\n"<<
		"[4] Mostrar cima de pila de operadores\n"<<
		"[5] Mostrar operadores en pila\n"<<
		"[6] Vaciar pila y reiniciar expresiones\n"<<
		"[7] Mostrar resultado final\n"<<
		"[8] Salir\n"<<
		"\n Elección > ";	
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
		case 7:
			resultado();
			break;
		default:
			cout<<"ELECCION << "<<eleccion<<endl;
	}
	system("pause");
}

void resultado(){
	cout<<"\n----[7] Mostrar resultado final-\n"<<endl;
	evaluador.setPostfija(convertidor.getPostfija());
	//cout<<"case7.evaluador.getPostfija().getSize(0): "<<evaluador.getPostfija().getSize(0)<<endl;
	//cout<<"case7.convertidor.getNumOperaciones: "<<convertidor.getNumOperaciones()<<endl;
	evaluador.evaluar(0, convertidor.getNumOperaciones());
	cout<<endl;
}
void mostrarCimaDePila(){
	cout<<"\n----[5] Mostrar cima de la pila-\n"<<endl;
	if (!convertidor.getPila().isEmpty()){
		cout<<" Cima << "<< convertidor.getPila().getCima();
	}else{
		cout<<" La pila de operadores está vacía"<<endl;
	}
	cout<<"\n\n";
}
void reiniciar(){
	cout<<"\n----[6] Vaciar pila y reiniciar-\n"<<endl;
	convertidor.clearStacks();

}
/*
void reiniciar(){
	cout<<"\n----[6] Vaciar pila y reiniciar-\n"<<endl;
	int result = convertidor.clearStacks();
	switch (result){
		case 1:
			cout<<" La pila ha sido vaciada"<<endl;
			cout<<" La expresion postfija se ha reiniciado\n"<<endl;
			break;
		case 2:
			cout<<" La pila ha sido vaciada"<<endl;
			cout<<" ATENCION: La expresion postfija ya estaba vacía\n"<<endl;
			break;
		case 3:
			cout<<" ATENCION: La pila ya estaba vacia"<<endl;
			cout<<" ATENCION: La expresion postfija ya estaba vacía\n"<<endl;
			break;
	}
}
*/
void desplegarPila(){
	cout<<"\n----[4] Mostrar operadores------\n"<<endl;
	cout<<"Pila << ";
	convertidor.getPila().desplegar( convertidor.getPila().getSize(0) );
	cout<<"\n\n";
}


void ingresarInfija(){
	cout<<"\n----[1] Ingresar expresion------\n"<<endl;
	cout<<"  Ingrese infija >> ";
	cin>>expresion;
	convertidor.inicializarConvertidor(expresion, expresion.size()); 
	cout<<"\n";
}
/*
void infijaEstatica(){
	//aMayusculas(expresion, 0, expresionSize);
	
	convertidor.inicializarConvertidor(expresion, expresion.size()); 
	cout<<"\n\n";
}*/

void consultarInfija(){
	cout<<"\n----[2] Consultar expresion-----\n"<<endl;
	cout<<expresion;
	cout<<"\n\n";
}
void infijaAPostfija(){
	cout<<"\n----[3] Convertir a postfija----\n"<<endl;
	convertidor.clearStacks();
	convertidor.evaluar(0);
	cout<<" Infija: "<<expresion<<endl;
	cout<<" Postfija: ";
	convertidor.desplegarPostfija();
	cout<<"\n\n";

}
int countstrings(string* expresion, int i){
	if ( *(expresion + i) ==  "\0"){
		return i;
	}else{
		countstrings(expresion, ++i);
	}
}
int getSize(string *expresion, int i){ // 0
	if ( *(expresion + i) ==  "\0"){
		return i;
	}else{
		getSize(expresion, ++i);
	}
}





