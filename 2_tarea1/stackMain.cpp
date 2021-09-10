#include <iostream>
#include "Stack.h"
using namespace std;

void showMenu();
void readChoice(int&);

void inicializar();
void push();
void pop();
void getTop();
void deploy();

Stack stack;

int main(){
	showMenu();
	return 0;
}

void showMenu(){
	int choice;
	do{	
		system("CLS");
		cout<<
		"[1]  Inicializar pila\n"<<
		"[2]  Ingresar dato\n"<<
		"[3]  Eliminar dato\n"<<
		"[4]  Mostrar cima\n"<<
		"[5]  Desplegar pila\n"<<
		"[6]  Contar pares en pila\n"<<
		"[7]  Contar impares en pila\n"<<
		"[8]  Sumatoria de valores\n"<<
		"[9]  Ordenar pila (ascendente)\n"<<
		"[10] Vaciar pila\n"<<
		"[11] Salir\n"<<
		"\n Eliga una opcion> ";
		cin>>choice;
		readChoice(choice);
		
	} while (choice != 11);
}
void push(){
	int p;
	cout<<"\nDato a ingresar > ";
	cin>>p;
	if (stack.push(p)){
		cout<<"\n El dato "<<stack.getTop()<<" ha sido ingresado a la pila\n"<<endl;
	}
	else cout<<"ERROR: La pila ya esta llena (OVERFLOW)\n"<<endl;
	return;
}
void pop(){
	int popped = stack.getTop();
	if (popped != -1){
		if (stack.pop()) {
			cout<<"\n El dato "<<popped<<" ha salido de la pila\n"<<endl;
		}	
	}else cout<<"\n ERROR: La pila ya esta vacia (UNDERFLOW)\n"<<endl;
}
void getTop(){	
	int top = stack.getTop();
	if (top != -1) {
		cout<<" \nLa cima de la pila es: "<<top<<"\n"<<endl;
	}
	else {
		cout<<"\n ERROR: La pila esta vacia\n"<<endl;	
	}
}
void inicializar(){
	stack.initialize();
	cout<<"\nLa pila ha sido inicializada correctamente\n"<<endl;
	return;
}

void readChoice(int &choice){
	switch (choice) {
		case 1: 
			inicializar();
			break;
		case 2:
			push();
			break;
		case 3:
			pop();
			break;
		case 4:
			getTop();
			break;
		case 5:
			if (stack.clear()){
				cout<<"STACK CLEARED"<<endl;
			}
			else {
				cout<<"EMPTY"<<endl;
			}
			break;
		case 6:
			int nums;
			nums = stack.getElementNumber(0,0);
			cout<<" Elementos: "<<stack.deploy(0, nums)<<endl;
			cout<<" Tamaño: "<<stack.getSize()<<endl;
			cout<<" Numero de elementos: "<<nums<<"\n"<<endl;
			break;
		default:
			cout<<"DEFAULT"<<endl;
	}
	system("pause");
}
