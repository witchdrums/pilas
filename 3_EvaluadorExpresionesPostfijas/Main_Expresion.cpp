#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "Evaluador.h"
using namespace std;

void toUpper(char* str, int, int);
void toUpper2(char* str, int);
void deploy(char* str, int);
int countChars(char* expresion, int i);

void initEvaluador();

//Stack stack;
Evaluador evaluador;

int main(){
	/*
	char expresion[128];
	cout<<"IN >> ";
	cin.getline(stack.pila, 128);
	int size = stack.getSize(0);
	toUpper(stack.pila, 0, size);
	
	stack.deploy(size);
	cout<<"\nchars: "<< size;
	*/
	initEvaluador();
	return 0;
}

void initEvaluador(){
	char expresion[128];
	char stack[128];
	char posfijaStack[128];
	cout<<"IN >> ";
	cin.getline(expresion, 128);
	evaluador.setInfija(expresion, stack, posfijaStack);
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
		//cout<<"return: "<<str<<endl;
		return;
	}else{
		if (str[i] > 96 && str[i] < 123 ){
			str[i] -= 32;
		}
		toUpper(str, ++i, size);
	}
}





