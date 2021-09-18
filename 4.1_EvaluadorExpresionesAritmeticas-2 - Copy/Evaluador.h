/*
TO DO:
		- hay un problema con la creacion de la infija, en la que se incluyen NULLs
*/



#include <iostream>
#include <string>
using namespace std;
class Evaluador{
private:
	int infijaSize = 0; // tamaño de ese arreglo
	Stack pila;	//pilas
	Stack postfija;
	string operacion;
	int resultado = 0;
	
	
	
public:
	
	void setPostfija(Stack p){
		postfija = p;
		invertirPostfija();
		cout<<"evaluador.postfija: ";
		postfija.desplegar(postfija.getSize(0));
	}
	
	void invertirPostfija(){
		int j = postfija.getSize(0);
		int k = j-1;
		for (int i = 0; i<j/2; i++){
			string help = postfija.getPila()[i];
			postfija.getPila()[i] = postfija.getPila()[k];
			postfija.getPila()[k] = help;
			--k;
		}
	}
	
	void desplegarPostfija(){
		desplegarPostfija2( postfija.getSize(0) );
	}
	
	void desplegarPostfija2(int size){
		if (size == 0){
			return;
		}else{
			desplegarPostfija2(--size);
			cout<<*(postfija.getPila() + size);
		}
	}
	
	void evaluar(int i, int numOperaciones){
		if (i == numOperaciones){
			return;
		}else{
			if ( isInt( postfija.getCima(), 0, postfija.getCima().size() ) ){
				pila.push( postfija.getCima() );
			}else{
				operacion += postfija.getCima();
				resultado += operar();
				++i;
			}
			operacion = "";
			postfija.pop();
		}
	}
	
	int operar(){
		cout<<"operar.operacion: "<<operacion<<endl;
		int a = stoi(pila.getCima());
		int b = stoi(pila.getCima());
		cout<<"operar.a: "<<a<<endl;
		cout<<"operar.b: "<<b<<endl;
		if ( operacion == "^"){
			return a^b;
		}else if ( operacion == "/" ){
			return a/b;
		}else if ( operacion == "*" ){
			return a*b;
		}else if ( operacion == "+" ){
			return a+b;
		}else if ( operacion == "-" ){
			return a-b;
		}else{
			cout<<"Error: mala operacion"<<endl;
			return -999;
		}

	}
	
	int getResultado(){
		return resultado;
	}
	
	bool isInt(string str, int j, int size){
		string str3 = "";
		for (int i = 0; i<size; i++){
			if (str[i] > 47 && str[i] < 58){
				str3 += str[i];
				++j;
			}
		}
		if (size == j){
			return true; 
		}
		else{ return false; }
	}
};

//infija: 3+2/(3-1)
//3+2/(2)
//3+1
//4

//post: 3231-/+

/*
postfija invertida:		pila:	operacion:
 +/-1323				
 +/-132					3
 +/-13					32
 +/-1					323
 +/-					3231	3-1 = 2
 +/						322		2/2 = 1
 +						31		3+1 = 4


*/
