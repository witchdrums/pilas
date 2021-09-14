#include <iostream>
using namespace std;

class Stack{
private:
	int bottom = -1;
	int top = bottom;
	int stop;

	
public:
	string expresion;
	int pila[128];
	string postfija;
	bool isEmpty(){
		if ( top != bottom ){ return false; }
		else { return true; }
	}
	bool isFull(){
		if (top == getSize()-1){ return true; }
		else { return false; }
	}
	bool push(int n){
		if ( !isFull() ){
			++top;
			*(array + top) = n;
			return true;
		}else {
			return false;
		}
	}
	bool pop(){
		if ( !isEmpty() ){
			*(array + top) = NULL;
			--top;
			return true;
		}else{
			return false;
		}
	}
	int getTop(){
		if (!isEmpty()){
			return *(array + top);
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
		return sizeof(array)/sizeof(*array);
	}
	int getElementNumber(int i, int n){
		if (i == getSize()){
			return n;
		}else{
			if (*(array + i) != NULL){
				++n;
			}
			getElementNumber(++i, n);
		}
	}
	
	void recorrerExpresion(int i){ // expresion.size();
		if (i == expresion.size()){
			cout<<postfija;
			return;
		}else{
			switch (expresion[i]){
				case '^':
					cout<<"^"<<endl;
					break;
				default:
					cout<<"eh"<<endl;
			}
		}
	}
	
	/*
	^ - 94
	/ - 47
	* - 42
	+ - 43
	- - 45
	( - 40
	) - 41
	*/
	
	int* getArray(){
		return array;
	}
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
			toString += to_string( *(array + i) ) + ", ";
			makeToString(++i, e);
		}
	}
};

/*
PILA con postfija y operadores
*/
