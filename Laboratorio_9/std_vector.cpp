#include <iostream>
#include <vector>

int main(){

	int N = 100;
	
	std::vector<double> v1(N);
	std::vector<double> v2;
	
	for (int i = 0; i < v1.size(); i++){
	
		v1[i] = i * 10;
	}
	
	for (int i = 0; i < N; i++){
	
		v2.push_back(i*2);
	}
	
	for (int i = 0; i < v1.size(); i++){
	
		std::cout << v2[i] << std::endl;
	}
}
