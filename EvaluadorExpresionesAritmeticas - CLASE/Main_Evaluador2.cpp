/*
TO DO:
	1. [] Validacion [1]: si ya hay una infija; ya no se puede meter otra hasta reiniciar con [6]
	2. [] Pasar todos los operadores a la pila antes de eliminarlos durante la conversion
	3. [v] cambiar los stacks a STRING para mantener numeros compuestos
		123 != 1, 2 y 3
		
		tomar
*/

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "Convertidor2.h"
#include "Evaluador2.h"
using namespace std;

void leerEleccion(int&);
void ingresarInfija();
void consultarInfija();
void infijaAPostfija();
void mostrarCimaDePila();
void desplegarPila();
void reiniciar();
void infijaEstatica();
void resultado();
bool clearExpresion();

void initConvertidor();

ConvertidorPostfija convertidor;
//Evaluador convertidor;


//string expresion = "2+3";
//string expresion = "1.432-(22^2*14)/(12+37/21^2)";
//string expresion = "(1/2)^3+4*(5-6)"; //(1/2)^3+4*(5-6)	31+2/(3-1)
//string expresion = "3+2/(3-1)";
//a-(b^c*d)/(b+c/a^d)
//1-(2^3*4)/(2+3/1^4)

string expresion;
int expresionSize;
bool expresionConvertida = false;

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
	if (!expresionConvertida){
		convertidor.clearStacks();
		convertidor.evaluar(0);
		cout<<"ATENCION: La expresion fue convertida a postfija"<<endl;
	}
	convertidor.invertirPostfija();
	cout<<"Expresion infija: "<<expresion<<endl;
	cout<<"Expresion postfija: ";
	convertidor.desplegarPostfija();
	cout<<endl;
	convertidor.evaluar2(0, convertidor.getNumOperaciones());
	cout<<endl;
}
void mostrarCimaDePila(){
	cout<<"\n----[4] Mostrar cima de la pila-\n"<<endl;
	if (!convertidor.getPila().isEmpty()){
		cout<<" Cima: "<< convertidor.getPila().getCima();
	}else{
		cout<<" ERROR: La pila de operadores está vacía"<<endl;
	}
	cout<<"\n\n";
}
void reiniciar(){
	cout<<"\n----[6] Vaciar pila y reiniciar-\n"<<endl;
	
	convertidor.clearStacks();
	convertidor.clearInfija(0);
	convertidor.reiniciar();
	expresion = "";
	expresionConvertida = false;
	cout<<endl;
	cout<<"Las expresiones y pilas han sido reiniciadas"<<endl;

}
void desplegarPila(){
	cout<<"\n----[5] Mostrar operadores------\n"<<endl;
	if (convertidor.getPila().desplegar( convertidor.getPila().getSize(0))){	
		//continue;
	}
	else {
		cout<<" ERROR: La pila de operadores está vacía"<<endl;
	}
	cout<<"\n\n";
}
void ingresarInfija(){
	cout<<"\n----[1] Ingresar expresion------\n"<<endl;
	cout<<"  Ingrese infija: ";
	cin>>expresion;
	convertidor.inicializarConvertidor(expresion, expresion.size()); 
	cout<<"\n";
}
void consultarInfija(){
	cout<<"\n----[2] Consultar expresion-----\n"<<endl;
	if ( expresion != ""){
		cout<<"Infija en memoria: "<<expresion<<endl;
	}else{
		cout<<"ERROR: No hay una expresion en memoria"<<endl;
	}
	cout<<"\n";
}
void infijaAPostfija(){
	cout<<"\n----[3] Convertir a postfija----\n"<<endl;
	convertidor.clearStacks();
	convertidor.evaluar(0);
	cout<<" Infija: "<<expresion<<endl;
	cout<<" Postfija: ";
	convertidor.desplegarPostfija();
	cout<<"\n\n";
	
	expresionConvertida = true;
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





