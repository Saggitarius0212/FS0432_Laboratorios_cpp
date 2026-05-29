/*
matplotlib-cpp, es una biblioteca de gráficos para C++ que 
utiliza Matplotlib a través de Python. Permite crear gráficos de
alta calidad en C++ utilizando la sintaxis familiar de Matplotlib.

Repositorio oficial
https://github.com/lava/matplotlib-cpp

Compilar como:

g++ main.cpp funcion.cpp -o main \
  -I/home/andre_hernandez/miniconda3/envs/Fis-Comp/include/python3.11 \
  -I/home/andre_hernandez/miniconda3/envs/Fis-Comp/lib/python3.11/site-packages/numpy/_core/include \
  -L/home/andre_hernandez/miniconda3/envs/Fis-Comp/lib \
  -lpython3.11 \
  -Wl,-rpath,/home/andre_hernandez/miniconda3/envs/Fis-Comp/lib

*/

#include <iostream>
#include "matplotlibcpp.h"
#include "funcion.h"
#include <vector>
#include <algorithm>
#include <iomanip>

namespace plt = matplotlibcpp;

void euler(std::vector<double>& x, std::vector<double>& t, double xi,
		double ti, double tf, double h){
	
	int N = static_cast<int>((tf-ti)/h);
	double tn;
	double xn = xi;
	
	for (int i = 0; i < N; i++){
	
		tn = ti + i*h;
		t.push_back(tn);
		
		xn = xn + h*f(xn, tn);
		x.push_back(xn);		
	}
}

void analitico(std::vector<double>& x, double ti,
		double tf, double h){
	
	int N = static_cast<int>((tf-ti)/h);
	double tn;
	double xn;
	
	for (int i = 0; i <= N; i++){
	
		tn = ti + i*h;
		
		xn = exacta(tn);
		x.push_back(xn);
	}
}

int main(){

std::vector<double> t;
std::vector<double> xe;
std::vector<double> xa;
std::vector<double> error;

double ti = 0;
double tf = 10;
double tn = 0;

double xi = 1;
xe.push_back(xi);

double h = 0.1;

euler(xe, t, xi, ti, tf, h);
analitico(xa, ti, tf, h);

t.push_back(tf);

double err_aux = 0;
double error_max;
double diferencia;

for (int i = 0; i < xe.size(); i++){

	diferencia = std::abs(xe[i] - xa[i]);	
	
	if (err_aux < diferencia){
	
		error_max = diferencia;
	}
	
	err_aux = diferencia;
	error.push_back(err_aux);
}

std::cout << std::left
	<< std::setw(15) << "t"
	<< std::setw(15) << "Euler"
	<< std::setw(15) << "Exacta"
	<< std::setw(15) << "Error"
	<< std::endl;

for (int i = 0; i < t.size(); i++){
	
	std::cout << std::left
		<< std::setw(15) << t[i]
		<< std::setw(15) << xe[i]
		<< std::setw(15) << xa[i]
		<< std::setw(15) << error[i]
		<< std::endl;
}

plt::figure();

plt::named_plot("Solución Aproximada", t, xe);
plt::named_plot("Solución Exacta", t, xa);

plt::xlabel("t");
plt::ylabel("x(t)");
plt::title("Soluciones en función del tiempo.");

plt::legend();
plt::grid(true);

plt::save("solucion_euler.png");
std::cout << "Archivo solucion_euler.png descargado..." << std::endl;

plt::figure();

plt::named_plot("Error Absoluto", t, error);

plt::xlabel("t");
plt::ylabel("Error");
plt::title("Error absoluto en función del tiempo.");

plt::legend();
plt::grid(true);

plt::save("error_local.png");
std::cout << "Archivo error_local.png descargado..." << std::endl;

return 0;
}
