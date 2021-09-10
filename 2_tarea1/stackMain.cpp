/*
TODO:
	> fix clear() - returns false everytime
	> Añadir validaciones para todo we (isempty etc)
	> sortUp
	> quitar el contador de elementos -> es innecesario
*/

#include <iostream>
#include "Stack.h"
#include "Sorter.h"
using namespace std;

void showMenu();
void readChoice(int&);

void inicializar();
void push();
void pop();
void getTop();
void deploy();
void clear();
void countEven();
void countOdd();
void addAll();
void sortUp();

Stack stack;
Sorter sorter;

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
void deploy(){
	int nums = stack.getElementNumber(0,0);
	cout<<" Elementos: "<<stack.deploy(0, nums)<<endl;
}
void clear(){
	if (stack.clear()){
		cout<<"La pila ha sido vaciada"<<endl;
	}
	else {
		cout<<"La pila ya estaba vacia"<<endl;
	}
}
void countEven(){
	cout<<" Pares en pila: "<<stack.countEven(0,0)<<endl;
}
void countOdd(){
	cout<<" Impares en pila: "<<stack.countOdd(0,0)<<endl;
}

void addAll(){
	cout<<" Sumatoria de datos en pila: "<<stack.addAll(0,0)<<endl;
}

void sortUp(){
	cout<<" Pila en orden ascendente: ";
	sorter.bubbleSort(stack.getArray(), stack.getSize());
	deploy();
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
			deploy();
			break;
		case 6:
			countEven();
			break;
		case 7:
			countOdd();
			break;
		case 8:
			addAll();
			break;
		case 9:
			sortUp();
			break;
		case 10:
			clear();
			break;
		case 11:
			break;
		default:
			cout<<"DEFAULT"<<endl;
	}
	system("pause");
}

/*

*/
