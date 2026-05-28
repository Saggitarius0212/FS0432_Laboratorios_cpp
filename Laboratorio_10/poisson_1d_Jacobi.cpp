/* poisson_1d_Jacobi.cpp

Repositorio oficial Matplotlib-cpp:
https://github.com/lava/matplotlib-cpp

Recuerde descargar archivo \texttt{matplotlibcpp.h} y 
colocarlo en el mismo directorio que este código.

Compilar como:

g++ poisson_1d_Jacobi.cpp -o poisson_1d_Jacobi.x \
    -I$CONDA_PREFIX/include/python3.11 \
    -I$(python -c "import numpy; print(numpy.get_include())") \
    -L$CONDA_PREFIX/lib \
    -lpython3.11 \
    -Wl,-rpath,$CONDA_PREFIX/lib
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

double fuente(double x) 
{
    return std::sin(M_PI * x);
}

double solucion_exacta(double x) 
{
    return -std::sin(M_PI * x) / (M_PI * M_PI);
}

int main() 
{
    const int N = 10; // numero de subintervalos
    const double a = 0.0;
    const double b = 1.0;
    const double h = (b - a) / N;

    const double alpha = 0.0;       // u(a)
    const double beta = 0.0;        // u(b)

    const int max_iter = 500;
    const double tol = 1e-10;

    std::vector<double> x(N + 1);
    std::vector<double> u(N + 1, 0.0);
    std::vector<double> u_new(N + 1, 0.0); // Vector auxiliar necesario para Jacobi
    std::vector<double> u_exacta(N + 1);

    for (int i = 0; i <= N; i++) 
    {
        x[i] = a + i * h;
        u_exacta[i] = solucion_exacta(x[i]);
    }

    // Condiciones de frontera en ambos vectores
    u[0] = alpha;
    u[N] = beta;
    u_new[0] = alpha;
    u_new[N] = beta;

    int iter = 0;
    double error = 1.0;
    std::vector<double> error_aux;

    while (iter < max_iter && error > tol) 
    {
	
	for (int i = 1; i < N; i++){
		
		u_new[i] = (0.5)*(u[i-1] + u[i+1] - h*h*fuente(x[i]));		
	}
		
	for (int i = 1; i < N; i++){
		
		error_aux.push_back(std::abs(u_new[i] - u[i]));
	}
	
	for (int i = 1; i < N; i++){
		u[i] = u_new[i];
	}
	
	error = *std::max_element(error_aux.begin(), error_aux.end());
	
	iter ++;
	
	std::cout << "Iteraciones: " << iter << std::endl;
    	std::cout << "Error final: " << error << std::endl; 
	
        /* Su código aquí */
        
    }

    std::cout << "Iteraciones: " << iter << std::endl;
    std::cout << "Error final: " << error << std::endl;

    double error_max = 0.0;
    for (int i = 0; i <= N; i++) 
    {
        error_max = std::max(error_max, std::abs(u[i] - u_exacta[i]));
    }

    std::cout << "Error maximo contra solucion exacta: "
              << error_max << std::endl;


    /*
    
    Grafique la solución numérica y 
    la solución  exacta usando matplotlib-cpp.

    */          

    return 0;
}
