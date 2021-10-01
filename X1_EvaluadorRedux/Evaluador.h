class Evaluador{
private:
	string expresionOriginal;
	string comodin;
	int expresionSize;
	float resultado;
	
	string infija[64];
	Stack postfija;
	Stack pila;

public:
	void reset(){
		postfija.clear();
		pila.clear();
		resultado = 0.0;
		clearInfija();
		comodin = "";
		expresionOriginal = "";
	}
	void clearInfija(){
		if (expresionSize == 0){
			return;
		}else{
			infija[--expresionSize] == "\0";
			clearInfija();
		}
	}
	void inicializar(string expresion){
		expresionOriginal = expresion;
		comodin = "";
		llenarInfija(0,0,expresion.size());
		cout<<"infija = ";
		for (int i = 0; i<expresionSize; i++){
			cout<<infija[i]<<", ";
		}
		cout<<endl;
		
		convertir(0);
		
	
		cout<<"\nPOST = ";
		postfija.deploy(postfija.getSize(0));
		
		invertirPostfija();
		cout<<"\nPILA = ";
		pila.deploy(pila.getSize(0));
		
		evaluar();
		reset();
		cout<<endl;
	}
	void evaluar(){
		if ( pila.isEmpty() ){
			resultado = stof( postfija.getCima() );
			cout<<"\nResultado = "<<resultado<<endl;
			return;
		}else{
			switch ( pila.getCima()[0] ){
				case '^':
				case '/':
				case '*':
				case '+':
				case '-':
					postfija.push( to_string( operar( ) ) );
					break;
				default:
					postfija.push(pila.getCima());
			}
			pila.pop();
			evaluar();
		}
	}
	float operar(){
		float a = stof( postfija.getCima() );
		postfija.pop();
		float b = stof( postfija.getCima() );
		postfija.pop();

		switch ( pila.getCima()[0] ){
			case '^': return pow(b,a);
			case '/': return b/a;
			case '*': return b*a;
			case '+': return b+a;
			case '-': return b-a;
		}
	}
	void invertirPostfija(){
		if (postfija.isEmpty()){
			return;
		}else{
			pila.push(postfija.getCima());
			postfija.pop();
			invertirPostfija();
		}
	}
	void llenarInfija(int i, int j, int size ){
		cout<<"i: "<<i<<", j: "<<j<<", size: "<<size<<endl;
		if (i > size){
			expresionSize = j;
			return;
		}else{
			switch (expresionOriginal[i]){
				case '(':
				case ')':
				case '^':
				case '/':
				case '*':
				case '+':
				case '-':
					if (comodin != "") {
						infija[j] = comodin;
						j++;
					}
					cout<<infija[j-1]<<endl;
					comodin = expresionOriginal[i];
					infija[j] = comodin;
					j++;
					cout<<infija[j-1]<<endl;
					comodin = "";
				default:
					comodin += expresionOriginal[i++];
			}
			llenarInfija(i, j, size);
		}
	}
	void paso4(){ // pasar contenidos de pila a posfija
		if (pila.isEmpty()){
			return;
		}else{
			if ( pila.getCima()[0] == '(' ){
				pila.pop();
			}else{
				postfija.push(pila.getCima());
				pila.pop();	
			}
			paso4();
		}
	}
	void convertir(int i){
		if (i == expresionSize){
			paso4();
			return;
		}else{
			/*
			switch ( infija[i][0] ){
				case '(':
				case '^':
				case '*':
				case '/':	
				case '+':
				case '-':
				case ')':
				default:
					if		
			}*/
			if ( isNum(infija[i][0])  ){	// PASO 1
				postfija.push( infija[i] );
				//cout<<"isNum: "<<postfija.getCima()<<endl;
			}else if (pila.isEmpty()){	//PASO 2.a
				pila.push( infija[i] );

			}else{  //PASO 2.b
				switch ( infija[i][0] ){
					case '(':
					case '^':
						pila.push( infija[i]);
						break;
					case '*':
					case '/':
						if ( pila.getCima()[0] != '^' && pila.getCima()[0] != '*' && pila.getCima()[0] != '/' ){
							pila.push( infija[i] );
						}else{
							postfija.push( pila.getCima() );
							pila.pop();
							--i;
						}
						break;
					case '+':
					case '-':
						if ( pila.getCima()[0] == '('){
							pila.push( infija[i] );
						}else{
							postfija.push( pila.getCima() );
							pila.pop();
							--i;
						}
						break;
					case ')':
						paso3();
						break;
				}
			}
			convertir(++i);
		}
	}
	void paso3(){ // pasar contenido de pila hasta topar con (
		if (pila.getCima()[0] == '('){
			pila.pop();
			return;
		}else{
			postfija.push(pila.getCima());
			pila.pop();
			paso3();
		}
	}
	bool isNum(char c){
		switch (c){
			case '(':
			case ')':
			case '^':
			case '/':
			case '*':
			case '+':
			case '-':
				return false;
			default:
				return true;
		}
	}


};


