/*

matplotlib-cpp
--------------

Repositorio oficial
https://github.com/lava/matplotlib-cpp

Compilar como:

g++ plot.cpp -o plot.x \
	-I$CONDA_PREFIX/include/python3.11 \
	-I$(python -c "import numpy; print(numpy.get_include())") \
	-L$CONDA_PREFIX/lib \
	-lpython3.11 \
	-Wl,-rpath,$CONDA_PREFIX/lib

*/

#include "matplotlibcpp.h"
#include <vector>
#include <cmath>

namespace plt = matplotlibcpp;

int main(){

	std::vector<double> x;
	std::vector<double> y1;
	std::vector<double> y2;
	
	double PI = std::acos(-1);
	
	// Generar datos
	
	for (double t = 0; t <= 2*PI; t += 1){
	
		x.push_back(t);
		y1.push_back(std::sin(t));
		y2.push_back(std::cos(t));
	}
	
	plt::plot(x, y1, {{"label","sin(x)"}});
	plt::plot(x, y2, {{"label","cos(x)"}});
	
	plt::title("Funciones trigonométricas");
	plt::xlabel("x");
	plt::ylabel("y");

	plt::legend();
	plt::grid(true);
	
	plt::show();
	
	return 0;










}
