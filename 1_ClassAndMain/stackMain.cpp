#include <iostream>
#include "Stack.h"
using namespace std;

void showMenu();
void readChoice(int&);

Stack stack;

int main(){
	showMenu();
	return 0;
}

void showMenu(){
	int choice;
	do{
		system("CLS");
		cout<<stack.deploy()<<endl;
		cout<<
		"[1] New array\n"<<
		"[2] Push\n"<<
		"[3] Pop\n"<<
		"[4] Top\n"<<
		"[5] Clear\n"<<
		"[6] EXIT\n"<<
		"\n > ";
		cin>>choice;
		readChoice(choice);
		
	} while (choice != 6);
}

void readChoice(int &choice){
	switch (choice) {
		case 1: stack.initialize();
		case 2:
			int p;
			cout<<"PUSH > ";
			cin>>p;
			if (stack.push(p)) cout<<"PUSHED"<<endl;
			else cout<<"OVERFLOW"<<endl;
			break;
		case 3:
			if (stack.pop()) cout<<"PULLED"<<endl;
			else cout<<"UNDERFLOW"<<endl;
			break;
		case 4:
			if (stack.getTop() != -1) {
				cout<<"TOP: "<<stack.getTop()<<endl;
			}
			else {
				cout<<"EMPTY"<<endl;	
			}
			break;
		case 5:
			if (stack.clear()){
				cout<<"STACK CLEARED"<<endl;
			}
			else {
				cout<<"EMPTY"<<endl;
			}
			break;
		case 6:
			break;
		default:
			cout<<"DEFAULT"<<endl;
	}
	system("pause");
}
