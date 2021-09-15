#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "Evaluador.h"
using namespace std;

void toUpper(char* str, int, int);
void deploy(char* str, int);
int countChars(char* expresion, int i);

void initEvaluador();

Evaluador evaluador;

int main(){
	cout<<"  INFIJA >> ";
	char expresion[128];
	cin.getline(expresion, 128);
	int expresionSize = countChars(expresion, 0);
	toUpper(expresion, 0, expresionSize);
	
	evaluador.setInfija(expresion, expresionSize);

	cout<<"\nPOSTFIJA << ";
	deploy(evaluador.getPostfija().getPila(), evaluador.getPostfija().getSize(0));
	return 0;
}

void deploy(char *expresion, int size){
	if (size == 0){
		return;
	}else{
		deploy(expresion, --size);
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

void toUpper(char* str, int i, int size){
	if ( i == size ) {
		return;
	}else{
		if (str[i] > 96 && str[i] < 123 ){
			str[i] -= 32;
		}
		toUpper(str, ++i, size);
	}
}





