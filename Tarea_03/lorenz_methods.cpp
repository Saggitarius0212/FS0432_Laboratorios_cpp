#include <iostream>
#include <vector>

std::vector<double> lorenz(const std::vector<double>& r, double sigma,
				double rho, double beta){

	double x = r[0];
	double y = r[1];
	double z = r[2];
	
	std::vector L = {sigma*(y-x), x*(rho-z)-y, x*y - beta*z};
	return L;
}

std::vector<std::vector<double>> euler(double h, double t0, double tf,
					double x0, double y0, double z0){

	std::vector<std::vector<double>> euler;
	std::vector<double> r = {x0, y0, z0};
	euler.push_back(r);
	
	std::vector<double> r_aux = {x0, y0, z0};
	
	int N = ((tf-t0)/h)+1;
	
	// double tn;
	// double i = 0;
	
	// while (tn != tf){
		
		// tn = t0 + i*h;
		
	for (int i = 0; i < N; i++){
	
		r_aux[0] = r[0] + h*lorenz(r, 10, 28, 8/3)[0];
		r_aux[1] = r[1] + h*lorenz(r, 10, 28, 8/3)[1];
		r_aux[2] = r[2] + h*lorenz(r, 10, 28, 8/3)[2];
		
		r = r_aux;
		
		euler.push_back(r);
		
	}
	
	return euler;
}

std::vector<std::vector<double>> rk2(double h, double t0, double tf,
					double x0, double y0, double z0){
	
	std::vector<std::vector<double>> rk2;
	std::vector<double> r = {x0, y0, z0};
	rk2.push_back(r);
	
	std::vector<double> r_aux = {x0, y0, z0};
	
	int N = ((tf-t0)/h)+1;
		
	std::vector<double> k1;
	std::vector<double> k2;
	
	for (int i = 0; i < N; i++){
	
		k1 = lorenz(r, 10, 28, 8/3);
		
		r_aux[0] = r[0] + (h/2)*k1[0];
		r_aux[1] = r[1] + (h/2)*k1[1];
		r_aux[2] = r[2] + (h/2)*k1[2];
		
		k2 = lorenz(r_aux, 10, 28, 8/3);
		
		r_aux[0] = r[0] + h*k2[0];
		r_aux[1] = r[1] + h*k2[1];
		r_aux[2] = r[2] + h*k2[2];
		
		r = r_aux;
		
		rk2.push_back(r);
		
	}
	
	return rk2;
	
}

std::vector<std::vector<double>> rk4(double h, double t0, double tf,
					double x0, double y0, double z0){
	std::vector<std::vector<double>> resultado;
	return resultado;
}

int main(){

	double sigma = 10;
	double rho = 28;
	double beta = 8/3;

	double t0 = 0;
	double tf = 40;
	double x0 = 1;
	double y0 = 2;
	double z0 = 3;
	
	std::vector<std::vector<double>> metodo_euler;
	
	std::vector<double> r_final;
	
	metodo_euler = rk2(0.01, 0, 40, x0, y0, z0);
	
	for (int i = 0; i < metodo_euler.size(); i++){
	std::cout << metodo_euler[i][2] << std::endl;
	}
	
	return 0;
}
