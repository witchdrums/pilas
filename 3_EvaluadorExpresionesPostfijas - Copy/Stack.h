#include <iostream>
using namespace std;

class Stack{
private:
	int bottom = -1;
	int top = bottom;
	int stop;
	char pila[64];
	
public:
	/*
	void setPila(char *array){
		pila = array;
		toUpper(0, getSize(0));
		
	}*/
	
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
	char pop2(){
		if ( !isEmpty() ){
			char c = *(pila + top); 
			*(pila + top) = '\0';
			--top;
			return c;
		}else{
			return '\0';
		}
	}
	char getTop(){
		if (!isEmpty()){
			return *(pila + top);
		}else{
			return -1;
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
	int getElementNumber(int i, int n){
		if (i == getSize()){
			return n;
		}else{
			if (*(pila + i) != '\0'){
				++n;
			}
			getElementNumber(++i, n);
		}
	}
	
	void deploy(int size){
		if (size == 0){
			return;
		}else{
			deploy(--size);
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

	/*
	string deploy(int i, int e){
		if ( !isEmpty() ){
			toString = "";
			makeToString(i, e);
			return toString;
		}else {
			toString = "La pila está vacía";
			return toString;
		}
	}
	void makeToString(int i, int e){
		if (i == e){
			return;
		}else{
			toString += to_string( *(pila + i) ) + ", ";
			makeToString(++i, e);
		}
	}*/
};

	/*
	^ - 94
	/ - 47
	* - 42
	+ - 43
	- - 45
	( - 40
	) - 41
	*/
