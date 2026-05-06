#include <iostream>

// Función que imprime las notas válidas ingresadas por el usuario.
// Recibe un puntero al arreglo de las notas y cantidad de notas válidas

void imprimir(double* ptr_notas, int validos){
	
	// Recorre el arreglo desde la posición 0 hasta el número de notas válidas.
	
    	for (int j = 0; j < validos; j++){
    	
    		// Imprime la nota de cada posición que atraviesa el for.
    		
        	std::cout << ptr_notas[j] << std::endl;
    	}
    
}

// Función que clasifica las notas según el rendimiento.
// Recibe lo mismo que la funcion anterior más referencias para modificar las variables directamente.

void clasificar(double* ptr_notas, int validos,
		int &reprobados, int &aprobados, int &sobresalientes){

	for (int j = 0; j < validos; j++){
		
		// Evalúa el valor de cada nota y según como se clasifique, aumenta en 1 la cantidad de datos en esa clasificación.
		
		if (ptr_notas[j] >= 90){
		
			++sobresalientes;
		}
		else if (ptr_notas[j] >= 70){
		
			++aprobados;
		}
		else{
			++reprobados;
		}
		
		
	}
}

// Función que calcula el promedio de las notas.
// Recibe lo mismo que la primera función.
// Retorna un double que sería el valor de la media calculada.

double media(double* ptr_notas, int validos){
	
	double suma = 0;
	
	for (int j = 0; j < validos; j++){
		
		// Realiza la suma de todos los valores recorridos por el for.
		
		suma += ptr_notas[j];
	}
	
	// Calcula el promedio y posterirmente lo retorna.
	
	double promedio = suma / validos;
	
	return promedio;

}

// Función que determina el valor máximo y mínimo de las notas.
// Usa referencias para devolver los dos valores encontrados.

void maximo_minimo(double* ptr_notas, int validos,
	     double &maximo, double &minimo){
	
	for (int j = 0; j < validos; j++){
		
		// Si el valor de la nota es mayor que el máximo actual, se actualiza el máximo, si el valor de la nota es menor que el mínimo actual, se actualiza el mínimo y continúa con el for.
		
		if (maximo < ptr_notas[j]){
			
			maximo = ptr_notas[j];
		}
		
		if (minimo > ptr_notas[j]){
		
			minimo = ptr_notas[j];
		}
	}
		
}

int main(){
	
	// Arreglo estático de 10 elementos para almacenar valores.
	
	double notas[10];
	
	// Variable que contabiliza el número de notas válidas.
	
	int i = 0;
	
	double entrada = -2;
	
	// Contador inicial de la cantidad contabilizada en cada categoría.
	
	int reprobados = 0;
	int aprobados = 0;
	int sobresalientes = 0;
	
	double promedio = 0;
	
	double maximo = 0;
	double minimo = 100;
	
	// Mensaje para informar al usuario.
	
	std::cout << "Ingrese -1 para terminar... " << std::endl;
	
	// Bucle do-while que se ejecuta hasta obtener 10 notas o el usuario ingrese -1.
	do{
	
	// Se reinicia la variable entrada para leer una nueva nota.
	
	entrada = -2;
	
	// Solicitud de nota.
	
	std::cout << "Ingrese nota. " << std::endl;
	std::cin >> entrada;
	
	// Si la entrada es -1 se termina el do-while.
	if (entrada == -1){
		break;
	}
	
	// Si la entrada es inválida continúa el do-while sin contabilizar esa entrada.
	
	else if (entrada < 0 || entrada > 100){
		continue;
	}
	else{
		notas[i] = entrada;
		++i;
	}
	
	} while (i < 10);
	
	// Un if que si no se ingresaron valores válidos devuelve un mensaje y termina el código.
	
	if (i == 0){
	
		std::cout << "No se ingresaron notas válidas." << std::endl;
		return 0;
	}
	
	std::cout << "Resultados: " << std::endl;
	
    	imprimir(notas, i);
    
    	clasificar(notas, i, reprobados, aprobados, sobresalientes);
    	
    	std::cout << "Reprobado(s): " << reprobados << std::endl;
    	std::cout << "Aprobado(s): " << aprobados << std::endl;
    	std::cout << "Sobresaliente(s): " << sobresalientes << std::endl;
    	
    	promedio = media(notas, i);
    	
    	std::cout << "Promedio: " << promedio << std::endl;
    	
    	maximo_minimo(notas, i, maximo, minimo);
    	
    	std::cout << "Máximo: " << maximo << std::endl;
    	std::cout << "Mínimo: " << minimo << std::endl;
    	
	return 0;
}

