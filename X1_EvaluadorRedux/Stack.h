#include <iostream>
using namespace std;

class Stack{
private:
	int bottom = -1;
	int top = bottom;
	int stop;
	string pila[64];
	
public:
	bool isEmpty(){
		if ( top != bottom ){ return false; }
		else { return true; }
	}
	bool isFull(){
		if (top == getSize()-1){ return true; }
		else { return false; }
	}
	bool push(string n){
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
			*(pila + top) = "\0";
			--top;
			return true;
		}else{
			return false;
		}
	}
	string getCima(){
		if (!isEmpty()){
			return *(pila + top);
		}else{
			return "e";
		}
	}
	bool clear(){
		if ( !isEmpty()){
			if (top > bottom){
				pop();
				clear();
			}else{
				return true;
			}
		}else{
			return false;
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
		if ( *(pila + i) ==  "\0"){
			return i;
		}else{
			getSize(++i);
		}
	}
	
	string* getPila(){
		return pila;
	}
	
	void deploy(int i){
		if (i == 0){
			return;
		}else{
			deploy(--i);
			cout<<*(pila + i)<<", ";
		}
	}
	



};
