#include <iostream>
#include <string>
using namespace std;

string nums(string &a, int i);
string text(string a);

int main(){
	string a = "";
	cout<<nums(a,0);
	//cout<<text("a");
	return 0;
}

string text(string a){
	return a + "1";	
}

string nums(string &a, int i){
	if (i == 10){
		return a;
	}else{
		a += "a";
		nums(a, ++i);
	}
}
