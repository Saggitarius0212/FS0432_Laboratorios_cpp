#include <cmath>
#include "funcion.h"

double f(double x, double t){

	double f = -x + std::sin(t);
	return f;
}

double exacta(double t){

	double x = (1/2)*(std::sin(t) - std::cos(t)) + (3/2)*std::exp(-t);
	return x;
}
