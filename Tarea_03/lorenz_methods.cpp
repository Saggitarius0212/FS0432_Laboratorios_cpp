#include <iostream>
#include <vector>

std::vector<double> lorenz(const std::vector<double>& r, double sigma,
				double rho, double beta){

	double x = r[0];
	double y = r[1];
	double z = r[2];
	
	std::vector<double> L = {sigma*(y-x), x*(rho-z)-y, x*y - beta*z};
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
	
	std::vector<std::vector<double>> rk4;
	std::vector<double> r = {x0, y0, z0};
	rk4.push_back(r);
	
	std::vector<double> r_aux = {x0, y0, z0};
	
	int N = ((tf-t0)/h)+1;
		
	std::vector<double> k1;
	std::vector<double> k2;
	std::vector<double> k3;
	std::vector<double> k4;
	
	for (int i = 0; i < N; i++){
	
		k1 = lorenz(r, 10, 28, 8/3);
		
		r_aux[0] = r[0] + (h/2)*k1[0];
		r_aux[1] = r[1] + (h/2)*k1[1];
		r_aux[2] = r[2] + (h/2)*k1[2];
		
		k2 = lorenz(r_aux, 10, 28, 8/3);
		
		r_aux[0] = r[0] + (h/2)*k2[0];
		r_aux[1] = r[1] + (h/2)*k2[1];
		r_aux[2] = r[2] + (h/2)*k2[2];
		
		k3 = lorenz(r_aux, 10, 28, 8/3);
		
		r_aux[0] = r[0] + h*k3[0];
		r_aux[1] = r[1] + h*k3[1];
		r_aux[2] = r[2] + h*k3[2];

		k4 = lorenz(r_aux, 10, 28, 8/3);

		r_aux[0] = r[0] + (h/6)*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
		r_aux[1] = r[1] + (h/6)*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);
		r_aux[2] = r[2] + (h/6)*(k1[2] + 2*k2[2] + 2*k3[2] + k4[2]);

		r = r_aux;
		
		rk4.push_back(r);
		
	}
	
	return rk4;
}
