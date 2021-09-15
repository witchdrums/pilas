#include <iostream>
#include "Stack.h"
using namespace std;
class Evaluador{
private:
	char *infija;
	int infijaSize = 0;
	Stack pila;
	Stack posfija;
	char operadores[6][3] = {
		{'^', '4', '3'},
		{'*', '2', '2'},
		{'/', '2', '2'},
		{'+', '1', '1'},
		{'-', '1', '1'},
		{'(', '5', '0'},
	};
	
public:

	void setInfija(char* expresion){
		infija = expresion;
		infijaSize = getSize(0);
		toUpper(0, infijaSize);
		deploy(infijaSize);
		cout<<"\ninfijaSize = "<<infijaSize<<endl;
		
		evaluar(0);
		
		cout<<"\nPILA: ";
		pila.deploy(pila.getSize(0));
		cout<<"\nPOSFIJA: ";
		posfija.deploy(posfija.getSize(0));
		return;
	}
	void evaluar(int i){
		if (i == infijaSize){
			return;
		}else{
			if ( *(infija + i) > 64 && *(infija + i) < 91){
				posfija.push(*(infija + i));
			}else if (pila.isEmpty()){
				pila.push(*(infija + i));
			}//else if () //USAR ASCII PARA LAS PRIORIDADES?????????????????????????????????????????
			evaluar(++i);
		}
	}
	void deploy(int size){
		if (size == 0){
			return;
		}else{
			deploy(--size);
			cout<<*(infija + size);
		}
	}
	int getSize(int i){ // 0
		if ( *(infija + i) ==  '\0'){
			return i;
		}else{
			getSize(++i);
		}
	}
	void toUpper(int i, int size){
		if ( i == size ) {
			//cout<<"return: "<<str<<endl;
			return;
		}else{
			if (infija[i] > 96 && infija[i] < 123 ){
				infija[i] -= 32;
			}
			toUpper(++i, size);
		}
	}
	
};

	/*WORKS
	void evaluar(int i){
		if (i == infijaSize){
			return;
		}else{
			switch ( *(infija + i) ){
				case 'A':
					pila.push(*(infija + i));
					break;
				case 'B':
					posfija.push(*(infija + i));
					break;
				default:
					cout<<"FUCK"<<endl;
			}
			evaluar(++i);
		}
	}*/

