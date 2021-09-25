#include <iostream>
#include "Stack.h"
#include "Evaluador.h"
#include <string>
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
	
	string infija;
	//cout<<"infija >>";
	//cin>>infija;
	infija = "123+45/(76-8065)";
	//llenarStack(infija, "", infija.size(), 0);
	evaluador.inicializar(infija);
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


