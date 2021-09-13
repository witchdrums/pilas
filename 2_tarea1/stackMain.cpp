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
		"\n Decisi"<<char(162)<<"n > ";
		cin>>choice;
		readChoice(choice);
		
	} while (choice != 11);
}
void readChoice(int &choice){
	cout<<"--------------------------------"<<endl;
	switch (choice) {
		case 1: inicializar();
			break;
		case 2: 
			if (stack.init) push();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 3:
			if (stack.init) pop();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 4:
			if (stack.init) getTop();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 5:
			if (stack.init) deploy();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 6:
			
			if (stack.init) countEven();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 7:
			if (stack.init) countOdd();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 8: 
		
			if (stack.init) addAll();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 9:
			
			if (stack.init) sortUp();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 10: 
		
			if (stack.init) clear();
			else cout<<"ERROR: La pila no se ha inicializado"<<endl;
			break;
		case 11: break;
		default: cout<<"DEFAULT"<<endl;
	}
	system("pause");
}
void push(){
	int p;
	cout<<"\nDato > ";
	cin>>p;
	if (stack.push(p)){
		cout<<"\nEl dato "<<stack.getTop()<<" ha sido ingresado a la pila\n"<<endl;
	}
	else cout<<"ERROR: La pila ya esta llena (OVERFLOW)\n"<<endl;
	return;
}
void pop(){
	int popped = stack.getTop();
	if (popped != -1){
		if (stack.pop()) {
			cout<<"\nEl dato "<<popped<<" ha salido de la pila\n"<<endl;
		}	
	}else cout<<"\nERROR: La pila ya esta vacia (UNDERFLOW)\n"<<endl;
}
void getTop(){	
	int top = stack.getTop();
	if (top != -1) {
		cout<<" \nLa cima de la pila es: "<<top<<"\n"<<endl;
	}
	else {
		cout<<"\nERROR: La pila esta vacia\n"<<endl;	
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
	if (stack.getTop() != -1){
		stack.clear();
		cout<<"La pila ha sido vaciada"<<endl;
	}else {
		cout<<"ERROR: La pila ya estaba vacia"<<endl;
	}
}
void countEven(){
	int count = stack.countEven(0,0);
	if (count != -1){
		cout<<"Pares en pila: "<<count<<endl;
	}else{
		cout<<"ERROR: La pila esta vacia"<<endl;
	}
}
void countOdd(){
	int count = stack.countOdd(0,0);
	if (count != -1){
		cout<<"Impares  en pila: "<<count<<endl;
	}else{
		cout<<"ERROR: La pila esta vacia"<<endl;
	}
}

void addAll(){
	int sum = stack.addAll(0,0);
	if (sum>-1){
		cout<<"Sumatoria de datos en pila: "<<stack.addAll(0,0)<<endl;	
	}else{
		cout<<"ERROR: La pila esta vacia"<<endl;
	}
}

void sortUp(){
	cout<<"Pila en orden ascendente: ";
	sorter.bubbleSort(stack.getArray(), stack.getElementNumber(0,0)-1);
	deploy();
	return;
}


/*

*/
