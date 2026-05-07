#include "integracion.h"

double trapecio(double* fx, int n, double h){
	
	double sumatoria = 0;
	
	for (int i = 1; i < n; i++){
	
		sumatoria += fx[i];
	}
	
	double aproximacion = (h/2)*(fx[0] + 2*sumatoria + fx[n]);
	
	return aproximacion;	
}

double simpson(double* fx, int n, double h){

	double suma_impar = 0;
	double suma_par = 0;
	
	for (int i = 1; i < n; i += 2){
	
		suma_impar += fx[i];
	}
	
	for (int i = 2; i < n; i += 2){
	
		suma_par += fx[i];
	}
	
	double aproximacion = (h/3)*(fx[0] + 4*suma_impar + 2*suma_par + fx[n]);
	
	return aproximacion;
}
