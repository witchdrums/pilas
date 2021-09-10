class Pila {
	private:
		//declara el tipo de arreglo de datos (int, float, varchar, bool)
		int cima;
		int fondo = -1;
		int array[5];
		int tope;
		
		bool PilaLlena() {
			if(cima <= tope)
				return false;
			else
				return true;
		}
		
		bool PilaVacia() {
			if(cima == fondo)
				return true;
			else
				return false;
		}
		
	public:
		void Inicializar() { //sirve para inicializar los contadores y topes
			cima = 0;
			tope = (SizePila()) - 1;
		}
		
		int Push(int dato){
			if(!PilaLlena()) {
				array[cima] = dato;
				cima++;
				return 0; // se inserto elemento
			}
			else
				return -1; //indicar si la pila esta llena
		}
		
		int Pop(){
			if(!PilaVacia()){
				array[cima] = NULL;
				cima--;
				return 0; //elemento eliminado correctamente
			}
			else 
				return -1; //mandar msj no se puede sacar elementos
		}
		//5
		//1|2|3|4|5
		int Cima() {
			if(!PilaVacia())
				return array[cima]; //el valor de la cima
			else
				return -1; //pila vacia
		}
		
		void LimpiarPila() {
			if(PilaVacia()) { //caso base
				Inicializar();
				return;
			}
			else { // caso general
				Pop();
				LimpiarPila();
			}
		}
		
		int SizePila() {
			return sizeof(array)/sizeof(*array); //devolverá el tamaño de la pila declarada
		}
		
};
