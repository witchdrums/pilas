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
	Stack pilaDeNumeros;	//pilaDeNumeross
	Stack postfija;
	Stack postfijaInvertida;
	char operacion;
	
public:
	
	void setPostfija(Stack p){
		postfija = p;
		invertirPostfija();
	}
	
	void invertirPostfija(){
		if (postfija.getCima() == "e"){
			cout<<"postfijaInvertida: ";
			postfijaInvertida.desplegar(postfijaInvertida.getSize(0));
			cout<<endl;
			return;
		}else{
			postfijaInvertida.push(postfija.getCima());
			postfija.pop();
			invertirPostfija();
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
			cout<<"\nRestultado: "<< pilaDeNumeros.getCima()<<endl;
			pilaDeNumeros.pop();
			return;
		}else{
			if ( esNumero( postfijaInvertida.getCima(), 0, postfijaInvertida.getCima().size() ) ){
			//if ( esNumero2( postfija.getCima(), 0, 0, postfija.getCima().size() ) ){
				pilaDeNumeros.push( postfijaInvertida.getCima() );
			}else{
				operacion = postfijaInvertida.getCima()[0]; //guardar operador en variable
				pilaDeNumeros.push(to_string( operar() )) ; //meter resultado de operacion en pilaDeNumeros
				++i; // incrementar numero de operaciones realizadas
				operacion = '/0'; // limpiar variable
			}
			postfijaInvertida.pop(); // remover cima de la postfija
			evaluar(i, numOperaciones); // repetir hasta que i == numOperaciones
		}
	}
	float operar(){
		cout<<"operar.operacion: "<<operacion<<endl;
		
		float b = stof(pilaDeNumeros.getCima());
		pilaDeNumeros.pop();
		float a = stof(pilaDeNumeros.getCima());
		pilaDeNumeros.pop();
		
		cout<<"operar.a: "<<a<<endl;
		cout<<"operar.b: "<<b<<endl;	
		switch (operacion){
			case '^': cout<<"evaluador.operar:"<<pow(a,b)<<endl;
				return pow(a,b);
			case '/': cout<<"evaluador.operar:"<<a/b<<endl;
				return a/b;
			case '*': cout<<"evaluador.operar:"<<a*b<<endl;
				return a*b;
			case '+': cout<<"evaluador.operar:"<<a+b<<endl; 
				return a+b;
			case '-': cout<<"evaluador.operar:"<<a-b<<endl;
				return a-b;
		}
	}
	

	
	bool esNumero(string str, int j, int size){
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
	/*
	
	bool esNumero2(string element, int i, int j, int size){
		cout<<"esNumero2"<<endl;
		if ( i == size-1 && size == j){
			cout<<"esNumero2.return >> i: "<<i<<", j:"<<j<<", size:"<<size<<endl;
			return true;
			
		}else if (i == size-1 && j < size){
			return false;
		}else{
			cout<<"esNumero2.else >> i: "<<i<<", j:"<<j<<", size:"<<size<<endl;
			string str = "";
			if (element[i] > 47 && element[i] < 58 || element[i] == 46){
				cout<<"esNumero2.element[i]: "<<element[i]<<endl;
				str += element[i];
				++j;
			}
			esNumero2(element, ++i, j, size);
		}
	}*/
	
	Stack getPostfija(){
		return postfija;
	}
	
	Stack getPila(){
		return pilaDeNumeros;
	}
	
	void reiniciar(){
		infijaSize = 0;
		pilaDeNumeros.clear();
		postfija.clear();
		postfijaInvertida.clear();
		operacion = '/0';
	}
};


/*



Infija:   1.432-(22^2*14)/(12+37/21^2)
postfija: 1.432 22 2 ^ 14 * 12 37 21 2 ^ / + / -

postfija									pila operadores		operacion
1.432 22 2 ^ 14 * 12 37 21 2 ^ / + / -		-
1.432 22 2 ^ 14 * 12 37 21 2 ^ / + /		-/
1.432 22 2 ^ 14 * 12 37 21 2 ^ / +			-/+
1.432 22 2 ^ 14 * 12 37 21 2 ^ /			-/+/
1.432 22 2 ^ 14 * 12 37 21 2				-/+/^
1.432 22 2 ^ 14 * 12 37 [21 2]				-/+/[^]				21 ^ 2 = 441
1.432 22 2 ^ 14 * 12 [37 441]				-/+[/]				37 / 441 = 0.0839
1.432 22 2 ^ 14 * [12 0.0839]				-/[+]				12 + 0.0839	= 12.0839
1.432 22 2 ^ 14	* 12.0839					-/*

analiza, caracter por caracter, a la postfija invertida
si un caracter es operando: pasalo a la pilaDeNumeros
si no: 
	saca un numero de la pilaDeNumeros; 
	saca el operador; 
	saca otro numero de la pilaDeNumeros; 
	has la operacion; 
	mete resultado a pilaDeNumeros

https://www.youtube.com/watch?v=84BsI5VJPq4
postfija invertida								pilaDeNumeros				operacion
- / + / ^ 2 21 37 12 * 14 ^ 2 22 1.432			1.432
- / + / ^ 2 21 37 12 * 14 ^ 2 22				1.432 22
- / + / ^ 2 21 37 12 * 14 ^ 2					1.432 22 2
- / + / ^ 2 21 37 12 * 14 ^						1.432 [22 2]				22^2 = 484
- / + / ^ 2 21 37 12 * 14 						1.432 484 14
- / + / ^ 2 21 37 12 *							1.432 [484 14]				484*14 = 6776
- / + / ^ 2 21 37 12							1.432 6776 12
- / + / ^ 2 21 37 								1.432 6776 12 37
- / + / ^ 2 21 									1.432 6776 12 37 21
- / + / ^ 2 									1.432 6776 12 37 21 2
- / + / ^										1.432 6776 12 37 [21 2]		21 ^ 2 = 441
- / + /											1.432 6776 12 [37 441]		37/441 = 0.0839
- / +											1.432 6776 [12 0.0839]		12 + 0.0839
- / 											1.432 [6776 12.0839]		6776 / 12.0839 = 560.746
-												[1.432 560.746]				1.432 - 560.746 = -559.314
												-559.314
	
	void invertirPostfija(){
		int j = postfija.getSize(0);
		int k = j-1;
		for (int i = 0; i<j/2; i++){
			string help = postfija.getPila()[i];
			postfija.getPila()[i] = postfija.getPila()[k];
			postfija.getPila()[k] = help;
			--k;
		}
		cout<<"invertida: ";
		postfija.desplegar(j);
		cout<<endl;
	}




#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Evaluador{
private:
	int infijaSize = 0; // tamaño de ese arreglo
	Stack pilaDeNumeros;	//pilaDeNumeross
	Stack postfija;
	Stack postfijaInvertida;
	string operacion;
	float resultado = 0;
	
	
	
public:
	
	void setPostfija(Stack p){
		postfija = p;
		//invertirPostfija();
		
		int j = postfija.getSize(0);
		int k = j-1;
		invertirPostfija2(0, j, k);
		//cout<<"evaluador.postfija: ";
		//postfija.desplegar(postfija.getSize(0));
	}
	
	void invertirPostfija2(int i, int j, int k){
		if (i == ((j/2)+1)){
			cout<<"invertida: ";
			postfija.desplegar(j);
			cout<<endl;
			return;
		}else{
			string help = postfija.getPila()[i];
			postfija.getPila()[i] = postfija.getPila()[k];
			postfija.getPila()[k] = help;
			invertirPostfija2(++i, j, --k);
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
			//cout<<"evaluar.return.pilaDeNumeros.getCima: "<<pilaDeNumeros.getCima()<<endl;
			resultado = stof( pilaDeNumeros.getCima() );
			cout<<"\nRestultado: "<<resultado<<endl;
			pilaDeNumeros.pop();
			return;
		}else{
			if ( esNumero( postfija.getCima(), 0, postfija.getCima().size() ) ){
			//if ( esNumero2( postfija.getCima(), 0, 0, postfija.getCima().size() ) ){
				pilaDeNumeros.push( postfija.getCima() );
			}else{
				operacion += postfija.getCima(); //guardar operador en variable
				pilaDeNumeros.push(to_string( operar() )) ; //meter resultado de operacion en pilaDeNumeros
				++i; // incrementar numero de operaciones realizadas
				operacion = ""; // limpiar variable
			}
			postfija.pop(); // remover cima de la postfija
			evaluar(i, numOperaciones); // repetir hasta que i == numOperaciones
		}
	}
	float operar(){
		cout<<"operar.operacion: "<<operacion<<endl;
		
		float b = stof(pilaDeNumeros.getCima());
		pilaDeNumeros.pop();
		float a = stof(pilaDeNumeros.getCima());
		pilaDeNumeros.pop();
		
		cout<<"operar.a: "<<a<<endl;
		cout<<"operar.b: "<<b<<endl;
		if ( operacion == "^" ){
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
	
	bool esNumero(string str, int j, int size){
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
	
	
	bool esNumero2(string element, int i, int j, int size){
		cout<<"esNumero2"<<endl;
		if ( i == size-1 && size == j){
			cout<<"esNumero2.return >> i: "<<i<<", j:"<<j<<", size:"<<size<<endl;
			return true;
			
		}else if (i == size-1 && j < size){
			return false;
		}else{
			cout<<"esNumero2.else >> i: "<<i<<", j:"<<j<<", size:"<<size<<endl;
			string str = "";
			if (element[i] > 47 && element[i] < 58 || element[i] == 46){
				cout<<"esNumero2.element[i]: "<<element[i]<<endl;
				str += element[i];
				++j;
			}
			esNumero2(element, ++i, j, size);
		}
	}
	
	Stack getPostfija(){
		return postfija;
	}
	
	Stack getPila(){
		return pilaDeNumeros;
	}
};


*/
