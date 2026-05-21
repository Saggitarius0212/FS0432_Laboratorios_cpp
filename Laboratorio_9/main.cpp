#include <iostream>
#include "funcion.h"
#include <vector>

int main(){

std::vector<double> t;
std::vector<double> xn;
std::vector<double> xa;
std::vector<double> error;

double ti = 0;
double tf = 10;
double tn = 0;

double xi = exacta(ti);
double h = 0.1;

t.push_back(ti);

int i = 1;

while (tn != 10){

	tn = ti + i*h;
	t.push_back(tn);
	i++;
}













return 0;
}
