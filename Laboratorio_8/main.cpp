#include <iostream>
#include <cmath>
#include <iomanip>
#include "funciones.h"
#include "integracion.h"

int main(){

	// Asignar valores de variables
	
	int n;
	
	std::cout << "Ingrese el número de subintervalos. " << std::endl;
	std::cin >> n;
	
	if (n % 2 != 0){
		
		std::cout << "El valor de subintervalos debe ser par. " << std::endl;
		return 0;
	}
	
	const double a = 0;
	const double b = 1;
	const double h = (b-a)/n;
	const double pi = std::acos(-1);
	double aprox_trapecio;
	double aprox_simpson;
	double error_trapecio;
	double error_simpson;
	
	// Arreglos dinámicos

	double* xi = new double[n+1];
	double* fi = new double[n+1];
	
	for (int i = 0; i <= n; i++){
	
		xi[i] = a + i*h;
		fi[i] = funcion(xi[i]);
	}
	
	// Cálculos realizados
	
	aprox_trapecio = trapecio(fi, n, h);
	aprox_simpson = simpson(fi, n, h);
	
	error_trapecio = std::abs(pi - aprox_trapecio);
	error_simpson = std::abs(pi - aprox_simpson);
	
	// Impresión de resultados
	
	std::cout << "Resultados... " << std::endl;
	std::cout << std::endl;
	std::cout << "Integral de 4/(1+x²) en [0,1]" << std::endl;
	std::cout << std::endl;
	std::cout << "Trapecio compuesto: " << std::setprecision(20) << aprox_trapecio << std::endl;
	std::cout << "Simpson compuesto: " << std::setprecision(20) << aprox_simpson << std::endl;
	std::cout << "Valor Exacto: " << std::setprecision(20) << pi << std::endl;
	std::cout << std::endl;
	std::cout << "Error Trapecio: " << std::setprecision(4) << error_trapecio << std::endl;
	std::cout << "Error Simpson: " << std::setprecision(4) << error_simpson << std::endl;
	std::cout << std::endl;
	std::cout << "Fin de programa... " << std::endl;
	
	
	// Libreación de memoria
	
	delete[] xi;
	delete[] fi;
	
	return 0;
}
