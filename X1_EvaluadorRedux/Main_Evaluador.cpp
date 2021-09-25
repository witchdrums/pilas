#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "Evaluador.h"
using namespace std;

void aMayusculas(char* str, int, int);
void desplegar(char* str, int);
int countChars(char* expresion, int i);

void initEvaluador();

Evaluador evaluador;

int main(){
	cout<<"  INFIJA >> ";
	char expresion[128];
	cin.getline(expresion, 128);
	
	int expresionSize = countChars(expresion, 0);
	aMayusculas(expresion, 0, expresionSize);
	
	evaluador.inicializarEvaluador(expresion, expresionSize); 

	cout<<"\nPOSTFIJA << ";
	desplegar(evaluador.getPostfija().getPila(), evaluador.getPostfija().getSize(0));
	return 0;
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





