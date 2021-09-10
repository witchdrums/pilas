#ifndef Functions
#define Functions

#include "Stack.h"
#include "Sorter.h"
void inicializar(Stack stack);
void push(Stack stack);
void pop(Stack stack);
void getTop(Stack stack);
void deploy(Stack stack);
void clear(Stack stack);
void countEven(Stack stack);
void countOdd(Stack stack);
void addAll(Stack stack);
void sortUp(Stack stack);
void push(Stack stack){
	int p;
	cout<<"\nDato a ingresar > ";
	cin>>p;
	if (stack.push(p)){
		cout<<"\n El dato "<<stack.getTop()<<" ha sido ingresado a la pila\n"<<endl;
	}
	else cout<<"ERROR: La pila ya esta llena (OVERFLOW)\n"<<endl;
	return;
}
void pop(Stack stack){
	int popped = stack.getTop();
	if (popped != -1){
		if (stack.pop()) {
			cout<<"\n El dato "<<popped<<" ha salido de la pila\n"<<endl;
		}	
	}else cout<<"\n ERROR: La pila ya esta vacia (UNDERFLOW)\n"<<endl;
}
void getTop(Stack stack){	
	int top = stack.getTop();
	if (top != -1) {
		cout<<" \nLa cima de la pila es: "<<top<<"\n"<<endl;
	}
	else {
		cout<<"\n ERROR: La pila esta vacia\n"<<endl;	
	}
}
void inicializar(Stack stack){
	stack.initialize();
	cout<<"\nLa pila ha sido inicializada correctamente\n"<<endl;
	return;
}
void deploy(Stack stack){
	int nums = stack.getElementNumber(0,0);
	cout<<" Elementos: "<<stack.deploy(0, nums)<<endl;
}
void clear(Stack stack){
	if (stack.clear()){
		cout<<"La pila ha sido vaciada"<<endl;
	}
	else {
		cout<<"La pila ya estaba vacia"<<endl;
	}
}
void countEven(Stack stack){
	cout<<" Pares en pila: "<<stack.countEven(0,0)<<endl;
}
void countOdd(Stack stack){
	cout<<" Impares en pila: "<<stack.countOdd(0,0)<<endl;
}

void addAll(Stack stack){
	cout<<" Sumatoria de datos en pila: "<<stack.addAll(0,0)<<endl;
}

void sortUp(Stack stack, Sorter sorter){
	cout<<" Pila en orden ascendente: ";
	sorter.bubbleSort(stack.getArray(), stack.getSize());
	deploy();
	return;
}
#endif
