#include <iostream>
using namespace std;

class Stack{
private:
	int bottom = -1;
	int top;
	int stop;
	int array[5];
	string toString;
public:
	bool init = false;
	void initialize(){
		top = bottom;
		stop = getSize()-1;
		init = true;
	}
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
			//toString = deploy();
			return true;
		}else {
			return false;
		}
	}
	bool pop(){
		if ( !isEmpty() ){
			*(array + top) = NULL;
			--top;
			//toString = deploy();
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
	int countEven(int i, int n){
		if (!isEmpty()){
			if (i == getElementNumber(0,0)){
				return n;
			}else{
				if (*(array + i)%2==0){
					++n;
				}
				countEven(++i,n);
			}	
		}else {
			return -1;
		}
	}
	
	int countOdd(int i, int n)	{
		if (!isEmpty()){
			if (i == getElementNumber(0,0)){
				return n;
			}else{
				if (*(array + i)%2!=0){
					++n;
				}
				countEven(++i,n);
			}	
		}else {
			return -1;
		}
	}
	
	int addAll(int i, int n){
		if (!isEmpty()){
			if (i == getSize()){
				return n;
			}else{
				if (*(array + i) != NULL){
					n += *(array + i);
				}
				addAll(++i,n);
			}			
		}else{
			return -1;
		}
	}
	
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
