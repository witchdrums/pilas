#include <iostream>
#include <cmath>
#include "Stack.h"
#include "Evaluador.h"
#include <string>
#include <stdlib.h>
using namespace std;

void llenarStack_iterativa(string&);
void llenarStack(string&, string, int, int);


Stack stack;
Stack postfija;
Evaluador evaluador;

int main(){
	/*STACK WORKING
	cout<<" > ";
	for (int i = 0; i<5; i++){
		stack.push("asdf" + to_string(i));
	}
	cout<<"STACK: ";
	stack.deploy(stack.getSize(0));*/
	
	//string infija;
	//cout<<"infija >>";
	//cin>>infija;
	//infija = "1.432-(22^2*14)/(12+37/21^2)";
	//llenarStack(infija, "", infija.size(), 0);
	
	
	string infijas[5] = {
		"1.432-(22^2*14)/(12+37/21^2)",
		"(1/2)^3+4*(5-6)",
		"1+3"
	};

	
	
	evaluador.inicializar(infijas[2]);
	//evaluador.inicializar(infijas[1]);
	//evaluador.inicializar(infijas[2]);
}

void llenarStack(string &infija, string str, int size, int i){
	if (i == size){
		stack.push(str);
		stack.deploy(stack.getSize(0));
		return;
	}else{
		switch (infija[i]){
			case '(':
			case ')':
			case '^':
			case '/':
			case '*':
			case '+':
			case '-':
				if (str != "") stack.push(str);
				str = infija[i];
				stack.push(str);
				str = "";
				break;
			default:
				str += infija[i];
				break;
		}
		llenarStack(infija, str, size, ++i);
	}
}


