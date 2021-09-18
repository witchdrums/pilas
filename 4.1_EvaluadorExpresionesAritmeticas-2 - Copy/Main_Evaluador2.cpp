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
#include "Convertidor.h"
#include "Evaluador.h"
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

//string expresion = "(1/2)^3+4*(5-6)"; //(1/2)^3+4*(5-6)	31+2/(3-1)
string expresion = "3+2/(3-1)";

int expresionSize;

int main(){
	int eleccion;
	infijaEstatica();
	do{
		system("CLS");
		cout<<"Convertidor de Expresiones Aritméticas\n"<<
		"--------------------------------";
		cout<<"\nExpresion: "; consultarInfija();
		cout<<"\nPila: "; desplegarPila();
		cout<<"\n    Cima: "<<convertidor.getPila().getCima();
		cout<<"\nPostfija: ";
		convertidor.desplegarPostfija();
		cout<<"\nPostfija inversa: ";
		evaluador.desplegarPostfija();
		cout<<"\nResultado postfija: "<<evaluador.getResultado();
		cout<<"\n--------------------------------\n"<<
		"Eliga una opción: \n\n"<<
		"[3] Convertir infija a postfija\n"<<
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
			//ingresarInfija();
			
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
			//desplegarPila();
			break;
		case 6:
			reiniciar();
			break;
		case 7:
			evaluador.setPostfija(convertidor.getPostfija());
			evaluador.evaluar(0, convertidor.getPila().getSize(0));
			break;
		/*
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

void resultado(){
	
}

void mostrarCimaDePila(){
	if (!convertidor.getPila().isEmpty()){
		cout<<" Cima de pila de operadores << "<< convertidor.getPila().getCima();
	}else{
		cout<<" La pila de operadores está vacía"<<endl;
	}
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
	convertidor.getPila().desplegar( convertidor.getPila().getSize(0) );
}

/*
void ingresarInfija(){
	cin.ignore();
	cout<<"  Ingrese infija >> ";
	cin.getline(expresion, 128);
	
	expresionSize = countstrings(expresion, 0);
	aMayusculas(expresion, 0, expresionSize);
	
	convertidor.inicializarConvertidor(expresion, expresionSize); 
	cout<<"\n\n";
}*/

void infijaEstatica(){
	//aMayusculas(expresion, 0, expresionSize);
	
	convertidor.inicializarConvertidor(expresion, expresion.size()); 
	cout<<"\n\n";
}

void consultarInfija(){
	cout<<expresion;
	cout<<"\n";
}
void infijaAPostfija(){
	convertidor.clearStacks();
	cout<<"PILA:";
	convertidor.desplegarPila();
	convertidor.evaluar(0);

}
/*
void infijaAPostfija(){
	desplegarPila();
	convertidor.getPila().clear();
	desplegarPila();
	
	cout<<"\n Expresion infija <<";
	consultarInfija();
	convertidor.evaluar(0);
	cout<<"\n Expresion postfija <<";
	desplegar(convertidor.getPostfija().getPila(), convertidor.getPostfija().getSize(0));
	cout<<endl;
}
*/

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





