#include <cmath>
#include "funcion.h"

double f_derivada(double x, double t){

	double f = -x + std::sin(t);
	return f;
}

double f(double t){

	double x = (1/2)*(std::sin(t) - std::cos(t)) + (3/2)*std::exp(-t);
	return x
}
