/*
TO DO:
		- hay un problema con la creacion de la infija, en la que se incluyen NULLs
*/



#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Evaluador{
private:
	int infijaSize = 0; // tamaño de ese arreglo
	Stack pila;	//pilas
	Stack postfija;
	string operacion;
	float resultado = 0;
	
	
	
public:
	
	void setPostfija(Stack p){
		postfija = p;
		invertirPostfija();
		//cout<<"evaluador.postfija: ";
		//postfija.desplegar(postfija.getSize(0));
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
			cout<<"evaluar.return.pila.getCima: "<<pila.getCima()<<endl;
			resultado = stof( pila.getCima() );
			cout<<"evaluar.return.resultado: "<<resultado<<endl;
			pila.pop();
			return;
		}else{
			if ( isNum( postfija.getCima(), 0, postfija.getCima().size() ) ){
				pila.push( postfija.getCima() );
			}else{
				operacion += postfija.getCima();
				pila.push(to_string(operar())) ;
				++i;
			}
			operacion = "";
			postfija.pop();
			evaluar(i, numOperaciones);
		}
	}
	float operar(){
		cout<<"operar.operacion: "<<operacion<<endl;
		float b = stof(pila.getCima());
		
		pila.pop();
		float a = stof(pila.getCima());
		pila.pop();
		cout<<"operar.a: "<<a<<endl;
		cout<<"operar.b: "<<b<<endl;
		if ( operacion == "^"){
			cout<<"evaluador.operar:"<<pow(a,b)<<endl;
			return pow(a,b);
		}else if ( operacion == "/" ){
			cout<<"evaluador.operar:"<<a/b<<endl;
			return a/b;
		}else if ( operacion == "*" ){
			cout<<"evaluador.operar:"<<a*b<<endl;
			return a*b;
		}else if ( operacion == "+" ){
			cout<<"evaluador.operar:"<<a+b<<endl;
			return a+b;
		}else if ( operacion == "-" ){
			cout<<"evaluador.operar:"<<a-b<<endl;
			return a-b;
		}else{
			cout<<"Error: mala operacion"<<endl;
			return -999;
		}
	}
	
	float getResultado(){
		return resultado;
	}
	
	bool isNum(string str, int j, int size){
		string str3 = "";
		for (int i = 0; i<size; i++){
			if (str[i] > 47 && str[i] < 58 || str[i] == 46){
				str3 += str[i];
				++j;
			}
		}
		if (size == j){
			return true; 
		}
		else{ return false; }
	}
	
	Stack getPostfija(){
		return postfija;
	}
	
	Stack getPila(){
		return pila;
	}
};

//infija: 3+2/(3-1)
//3+2/(2)
//3+1
//4

//post: 3231-/+

/*
analiza, caracter por caracter, a la postfija invertida
si un caracter es operando: pasalo a la pila
si no: 
	saca un numero de la pila; 
	saca el operador; 
	saca otro numero de la pila; 
	has la operacion; 
	mete resultado a pila

postfija invertida:		pila:	operacion:
 +/-1323				
 +/-132					3
 +/-13					32
 +/-1					323
 +/-					3231	3-1 = [2]
 +/						32[2]	2/2 = 1
 +						3[1]	3+1 = 4
 						[4]


*/
