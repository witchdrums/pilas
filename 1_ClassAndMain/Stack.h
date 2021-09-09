#include <iostream>
using namespace std;

class Stack{
private:
	int bottom = -1;
	int top = bottom;
	int array[5];
	string toString;
	
public:
	void initialize(){
		for (int i = 0; i<5; i++){
			array[i] = i+1;
			++top;
		}
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
		if (!isFull()){
			++top;
			array[top] = n;
			toString = deploy();
			return true;
		}else {
			return false;
		}
	}
	bool pop(){
		if (!isEmpty()){
			array[top] = NULL;
			--top;
			toString = deploy();
			return true;
		}else{
			return false;
		}
	}
	int getTop(){
		if (!isEmpty()){
			return array[top];
		}else{
			return -1;
		}
	}
	bool clear(){
		if ( !isEmpty() ){
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
	string deploy(){
		if ( !isEmpty() ){
			toString = " Stack = {";
			makeToString(0);
			toString += "}";
			return toString;
		}else {
			toString = " Stack is empty";
			return toString;
		}
	}
	void makeToString(int i){
		if ( i == getSize()){
			return;
		}else{
			if (array[i] != NULL)
				toString += to_string(array[i]) + ", ";
			makeToString(++i);
		}
	}
};
