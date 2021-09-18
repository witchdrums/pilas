#include <iostream>
using namespace std;

class Stack{
private:
	int bottom = -1;
	int top = bottom;
	int stop;
	char pila[64];
	
public:
	bool isEmpty(){
		if ( top != bottom ){ return false; }
		else { return true; }
	}
	bool isFull(){
		if (top == getSize()-1){ return true; }
		else { return false; }
	}
	bool push(char n){
		if ( !isFull() ){
			++top;
			*(pila + top) = n;
			return true;
		}else {
			return false;
		}
	}
	bool pop(){
		if ( !isEmpty() ){
			*(pila + top) = '\0';
			--top;
			return true;
		}else{
			return false;
		}
	}
	char getCima(){
		if (!isEmpty()){
			return *(pila + top);
		}else{
			return 'e';
		}
	}
	bool clear(){

			if (top > bottom){
				cout<<"clear"<<endl;
				pop();
				clear();
			}else{
				return true;
			}

	}
	int getSize(){
		return sizeof(pila)/sizeof(*pila);
	}
	void desplegar(int size){
		if (size == 0){
			return;
		}else{
			desplegar(--size);
			cout<<*(pila + size);
		}
	}

	int getSize(int i){ // 0
		if ( *(pila + i) ==  '\0'){
			return i;
		}else{
			getSize(++i);
		}
	}
	
	char* getPila(){
		return pila;
	}
	
	void toUpper(int i, int size){ //0 y size
	if ( i == size ) {
		//cout<<"return: "<<str<<endl;
		return;
	}else{
		if (pila[i] > 96 && pila[i] < 123 ){
			pila[i] -= 32;
		}
		toUpper(++i, size);
	}
}

};
