#include <iostream>
#include "Stack.h"
using namespace std;
class Evaluador{
public:
	Stack infija;
	Stack pila;
	Stack posfija;
	setInfija(char* expresion, char* stack, char* posfijaStack){
		infija.setPila(expresion);
		pila.setPila(stack);
		posfija.setPila(posfijaStack);
		
		evaluar(0, infija.getSize(0), 0);
		
		cout<<"INFIJA: ";
		infija.deploy(infija.getSize(0));
		cout<<"\nPILA: ";
		pila.deploy(pila.getSize(0));
		cout<<"\nPOSFIJA: ";
		posfija.deploy(posfija.getSize(0));
		
	}
	
	void evaluar(int i, int size, int n){
		if (i == size){
			return;
		}else{
			switch ( *(infija.getPila() + i) ){
				case 'Q':
					pila.push(*(infija.getPila() + i));
					break;
				default:
					posfija.push(*(infija.getPila() + i));
					break;
			}
			evaluar(++i, size, n);
		}
	}
	
};

/*
	void evaluar(int i, int size, int n){
		if (i == size){
			return;
		}else{
			switch ( *(infija.getPila() + i) ){
				case 'A':
					pila.push(*(infija.getPila() + i));
					break;
				default:
					break;
			}
			evaluar(++i, size, n);
		}
	}

*/
