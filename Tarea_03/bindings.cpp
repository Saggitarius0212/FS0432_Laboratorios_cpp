#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

namespace py = pybind11;

std::vector<double> lorenz(const std::vector<double>& r, double sigma,
				double rho, double beta);
				
std::vector<std::vector<double>> euler(double h, double t0, double tf,
					double x0, double y0, double z0);
					
std::vector<std::vector<double>> rk2(double h, double t0, double tf,
					double x0, double y0, double z0);
					
std::vector<std::vector<double>> rk4(double h, double t0, double tf,
					double x0, double y0, double z0);
					
PYBIND11_MODULE(lorenz_methods, m){
	m.doc() = "Módulo Python para métodos de Lorenz usando pybind11";
	m.def("lorenz", &lorenz, "Función lorenz desde C++");
	m.def("euler", &euler, "Función euler desde C++");
	m.def("rk2", &rk2, "Función rk2 desde C++");
	m.def("rk4", &rk4, "Función rk4 desde C++");
}
