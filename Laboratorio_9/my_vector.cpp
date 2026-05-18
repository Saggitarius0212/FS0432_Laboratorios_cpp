#include <iostream>

class Vector{
	
	// Indica que estos miembros son accesibles solo dentro de la clase
	// Sirve para asegurar consistencia conceptual de lo que representa la clase
	
	private:	
		double* elem;
		int _size;


	// Public significa que estos miembros se pueden accesar desde fuera de la clase
	public:
		 // Un constructor es una función especial que se llama automáticamente cuando
		 // se crea un objeto de una clase
		 Vector(const int size){
		 
		 	if (size > 0){
		 	
		 		_size = size;
		 	}
		 	else{
		 	
		 		std::cout << "El tamaño de un vector debe ser entero positivo" << std::endl;
		 	}
		 
		 	elem = new double[_size];
		 
		 }
		
		// Un destructor es una función especial que se llama automáticamente cuando
		// un objeto deja de existir. Se usa para liberar memoria, para guardar o cerrar
		// archivos, cerrar sockets de red y cerrar conexiones a bases de datos, etc...
		~Vector(){
		
			delete[] elem;
		}
		
		int size(){
		
			return _size;
		}
		
		double& operator[](const int i){
		
			return elem[i];
		}




};


int main(){
	
	Vector v{10};
	
	for (int i = 0; i < v.size(); i++){
	
		v[i] = i;
	}
	
	
	for (int i = 0; i < v.size(); i++){
	
		std::cout << v[i] << std::endl;
	}
	
	return 0;
}








































