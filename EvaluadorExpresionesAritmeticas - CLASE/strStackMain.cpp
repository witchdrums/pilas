//string to string[]

#include <iostream>
#include <string> 
#include "StrStack.h"
bool checkInt(string str, int size, int stop);
using namespace std;

StrStack stack;

int main(){
	/*
	string str = "32+65/(32-67)";
	string array[20];
	
	string str1 = "";
	for (int i = 0; i<str.size(); i++){
		switch ( str[i] ){
			case '(':
			case ')':
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
				if (str1 != "") stack.push( str1 );
				//problema: siempre habia un caso en el que "" se insertaba en stack; "" es nulo, por lo que 
				//afectaba el conteo del numero de elementos 
				str1 = str[i];
				stack.push( str1 );
				str1 = "";
				break;
			default:
				str1 += str[i];
				break;
		}
		if ( i == str.size() - 1) stack.push( str1 );
	}
	cout<<"desplegar: ";
	stack.desplegar(stack.getSize(0));
	cout<<endl;
	cout<<"size: "<<stack.getSize(0);
	*/
	cout<<endl;
	string str2 = "53231234";
	cout<<checkInt(str2, str2.size(), str2.size());

}

bool checkInt(string str, int size, int stop){
	for (int i = 0; i<stop; i++){
		if (str[i] > 47 && str[i] < 58){
			--size;
		}
	}
	if (size == 0){ return true; }
	else{ return false; }
}

/*
--------------------------------
Algorithm works if used on local array:
	string array[20];
	
	string str1 = "";
	int j = 0;
	for (int i = 0; i<str.size(); i++){
		switch ( str[i] ){
			case '(':
			case ')':
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
				array[j] = str1;
				++j;
				str1 = str[i];
				array[j] = str1;
				++j;
				str1 = "";
				break;
			default:
				str1 += str[i];
				break;
		}
		if ( i == str.size() - 1) array[j] = str1;
	}
	for (int i = 0; i<j+1; i++){
		cout<<array[i];
	}

--------------------------------
Stack works if you push each item one by one:
	stack.push("32");
	stack.push("+");
	stack.push("65");
	stack.push("/");
	stack.push("(");
	stack.push("32");
	stack.push("-");
	stack.push("67");
	stack.push(")");
So the problem is not the stack, but something within the algorithm to parse numbers and operators

--------------------------------
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

--------------------------------
string str1 = "";
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
