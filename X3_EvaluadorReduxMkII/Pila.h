#include <iostream>
using namespace std;
class Pila{
	private:
		string pila[64];
		int tope,fondo,cima;
		bool inicializada = false;


		bool estaLlena(){
			if ( cima == tope) {
				return true;
			}else return false;
		}
		
		void limpiarR(){
			if ( estaVacia() ){
				inicializar();
				return;
			}else{
				pop();
				limpiarR();
			}
		}

		void desplegarR(int i){
			if (i > cima){
				return;
			}else{
				cout<<pila[i];
				if ( i < cima) cout<<", ";
				desplegarR(++i);
			}
		}
		
	public:
		bool estaVacia(){
			if ( cima < fondo ) {
				return true;
			}else return false;
		}
		void inicializar(){
			fondo = 0;
			cima = -1;
			tope = sizeof(pila)/sizeof(*pila) - 1;
			inicializada = true;
		}
		
		int push(string dato){
			if (!inicializada){
				return -1;
			}else if (estaLlena()){
				return -2;
			}else{
				pila[++cima] = dato;
				return 2;
			}
		}
		
		int pop(){
			if (!inicializada){
				return -1;
			}else if (estaVacia()){
				return -3;
			}else{
				//int popped = pila[cima];
				//pila[cima--] = NULL;
				--cima;
				return 3;
			}
		}
		
		int desplegar(){
			if (!inicializada){
				return -1;
			}else{
				cout<<"Pila = [";
				desplegarR(0);
				cout<<"]"<<endl;
				return 4;
			}	
		}
		
		int limpiar(){
			if (!inicializada){
				return -1;
			}else if (estaVacia()){
				return -3;
			}else{
				limpiarR();
				return 5;
			}	
		}
		
		string getCima(){
			if (!inicializada){
				return "-1";
			}else if (estaVacia()){
				return "-3";
			}else{
				return pila[cima];
			}
		}
		
		int getSize(){
			return cima+1;
		}
		
		
};


/*
#include <iostream>
using namespace std;
class Pila{
	private:
		int pila[5];
		int tope,fondo,cima;
		bool inicializada = false;

		bool estaVacia(){
			if ( cima < fondo ) {
				return true;
			}else return false;
		}
		bool estaLlena(){
			if ( cima == tope) {
				return true;
			}else return false;
		}
		
		void limpiarR(){
			if ( estaVacia() ){
				inicializar();
				return;
			}else{
				pop();
				limpiarR();
			}
		}

		void desplegarR(int i){
			if (i > cima){
				return;
			}else{
				cout<<pila[i];
				if ( i < cima) cout<<", ";
				desplegarR(++i);
			}
		}
		
	public:
		void inicializar(){
			fondo = 0;
			cima = 0;
			tope = sizeof(pila)/sizeof(*pila) - 1;
			inicializada = true;
		}
		
		int push(int dato){
			if (!inicializada){
				return -1;
			}else if (estaLlena()){
				return -2;
			}else{
				pila[++cima] = dato;
				return 2;
			}
		}
		
		int pop(){
			if (!inicializada){
				return -1;
			}else if (estaVacia()){
				return -3;
			}else{
				int popped = pila[cima];
				//pila[cima--] = NULL;
				--cima;
				return 3;
			}
		}
		
		int desplegar(){
			if (!inicializada){
				return -1;
			}else{
				cout<<"Pila = [";
				desplegarR(0);
				cout<<"]"<<endl;
				return 4;
			}	
		}
		
		int limpiar(){
			if (!inicializada){
				return -1;
			}else if (estaVacia()){
				return -3;
			}else{
				limpiarR();
				return 5;
			}	
		}
		
		int getCima(){
			if (!inicializada){
				return -1;
			}else if (estaVacia()){
				return -3;
			}else{
				return pila[cima];
			}
		}
		
		
		
		
};*/
