//string to string[]
#include <iostream>
#include "StrStack.h"
using namespace std;

StrStack stack;

int main(){
	string str = "32+65/(32-67)";

	
	string str1 = "";
	for (int i = 0; i<str.size(); i++){
		if (str[i] > 47 && str[i] < 58){
			str1 += str[i];
		}else{
			stack.push(str1);
			cout<<"\nsuma: "<<stack.getCima();
			cout<<"\nstackSize: "<<stack.getSize(0);
			str1 = str[i];
			stack.push(str1);
			cout<<"\noperador: "<<stack.getCima();
			cout<<"\nstackSize: "<<stack.getSize(0);
			str1 = "";
		}
	}
	cout<<"\n\nstr: "<<str<<endl;
	cout<<"stack: ";
	stack.desplegar(stack.getSize(0));
	cout<<"\nstack size: "<<stack.getSize(0);
	cout<<endl;
	cout<<stack.getPila()[0]<<endl;
	cout<<stack.getPila()[1]<<endl;
	cout<<stack.getPila()[2]<<endl;
	cout<<stack.getPila()[3]<<endl;
}

/*
for (int i = 0; i<str.size(); i++){
		switch ( str[i] ){
			case '(':
			case ')':
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
				cout<<"str[i]: "<<str[i]<<endl;
				stack.push( str1 );
				str1 = str[i];
				stack.push( str1 );
				str1 = "";
				break;
			default:
				str1 += str[i];
				break;
		}
		cout<<i<<endl;
		if ( i == str.size() - 1) stack.push( str1 );
	}
*/
