#include <iostream>
#include "Pila.h"
using namespace std;

Pila pila;

void readChoice(int&);
void gestionSalida(int&, int);

int main(){
	int choice;
	do{
		system("CLS");
		cout<<
		"[1] Init\n"<<
		"[2] Push\n"<<
		"[3] Pop\n"<<
		"[4] Show\n"<<
		"[5] Clear\n"<<
		"[6] Exit\n\n"<<
		" Choice > ";
		cin>>choice;
		readChoice(choice);
	}while (choice != 6);
	return 0;	
}

void readChoice(int &choice){
	cout<<"\n--------------------------------\n";
	int num, salida, cima = 0;
	switch(choice){
		case 1: pila.inicializar();
			cout<<"\nPila inicializada correctamente"<<endl;
			break;
		case 2:
			cout<<"Numero > ";
			cin>>num;
			salida = pila.push(num); 
			break;
		case 3:
			cima = pila.getCima();
			salida = pila.pop();
			break;
		case 4:
			salida = pila.getCima();
			break;
		case 5:
			salida = pila.limpiar();
			break;
		case 6: cout<<"Ejecucion terminada"<<endl;
			break;
		default: cout<<"Opcion "<<choice<<" no existe"<<endl;
	}
	gestionSalida(salida, cima);
	cout<<"\n--------------------------------\n";
	system("pause");
}

void gestionSalida(int &salida, int cima){
	if ( salida < 0 ){
		switch (salida){
			case -1: cout<<"\nERROR: La pila no se inicializo"<<endl;
				break;
			case -2: cout<<"\nERROR: La pila esta llena (OVERFLOW)"<<endl;
				break;
			case -3: cout<<"\nERROR: La pila esta vacia (UNDERFLOW)"<<endl;
				break;
		}
	}else{
		switch (salida){
			case 2: cout<<"Numero "<<pila.getCima()<<" ha ingresado a la pila"<<endl;
				break;
			case 3: cout<<"Numero "<<cima<<" ha salido de la pila"<<endl;
				break;
			case 4: cout<<""<<endl;
				break;
			case 5: cout<<"\nLa pila se ha limpiado"<<endl;
				break;
		}
		pila.desplegar();	
	}
	return;
}

