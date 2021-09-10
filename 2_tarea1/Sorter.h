#include <iostream>
using namespace std;

class Sorter{
private:
	int* array;
	void bubble1(int size){
		if (size == 0) { 
			return; 
		}
		else{ bubble2(0, size); }
	}
	void bubble2(int i, int size){
		if (i == size) { bubble1(size-1); }
		else{
			if ( array[i] != NULL && array[i] > array[i + 1] ){
				int help = array[i];
				array[i] = array[i + 1];
				array[i + 1] = help;
			}
			bubble2(i+1, size);
		}
	}
		
public:
	void bubbleSort(int* a, int size){
		array = a;
		//deploy();
		bubble1(size);
	}
	void deploy(){
		cout<<"\nsorted: ";
		for (int i = 0 ; i<5; i++){
			cout<<array[i]<<", ";
		}
	}


};
