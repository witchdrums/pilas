//inverted
#include <iostream>
#include "Stack.h"

using namespace std;

Stack stack;

int main(){
	
	for (int i = 0; i<9; i++){
		stack.push(to_string(i+1));
	}
	int j = stack.getSize(0);
	cout<<"stack: ";
	stack.desplegar(j);
	
	
	cout<<endl;
	cout<<"j: "<<j<<endl;
	

	int k = j-1;
	//if (j%2 == 0){
		for (int i = 0; i<j/2; i++){
			string help = stack.getPila()[i];
			stack.getPila()[i] = stack.getPila()[k];
			stack.getPila()[k] = help;
			--k;
		}
	//}
	cout<<"inverted: ";
	stack.desplegar(j);
	
}

//123456789
//987654321
