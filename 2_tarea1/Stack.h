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
	void initialize(){
		top = bottom;
		stop = getSize()-1;
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
		if (i == getElementNumber(0,0)){
			return n;
		}else{
			if (*(array + i)%2==0){
				++n;
			}
			countEven(++i,n);
		}
	}
	
	int countOdd(int i, int n){
		if (i == getElementNumber(0,0)){
			return n;
		}else{
			if (*(array + i)%2!=0){
				++n;
			}
			countOdd(++i,n);
		}
	}
	
	int addAll(int i, int n){
		if (i == getSize()){
			return n;
		}else{
			if (*(array + i) != NULL){
				n += *(array + i);
			}
			addAll(++i,n);
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

/*
	string deploy(int i, int e){
		if ( !isEmpty() ){
			makeToString(i, e);
			cout<<" /nStacks deploy is returning here"<<endl;
			return toString;
		}else {
			toString = "empty";
			return toString;
		}
	}
	void makeToString(int i, int e){
		if (i == e){
			cout<<toString<<endl; //DOES NOT WORK
			return;
		}else{
			cout<<"array: "<<array[i]<<endl;
			toString += to_string(array[i]) + ", ";
			makeToString(++i, e);
		}
	}	
	
*/
