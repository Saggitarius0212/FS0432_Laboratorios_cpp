#include <iostream>
#include <omp.h>
#include <vector>

int main() {
  int suma = 0;
  const int N = 12800;

  std::vector<double> A(N * N, 1.5);
  std::vector<double> B(N * N, 2.0);
  std::vector<double> C(N * N, 0.0);
  
  double start_time = omp_get_wtime();

// Colapsar ambos bucles en uno solo.
#pragma omp parallel for collapse(3)

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++){
      
        C[i*N + j] += A[i*N + k] * B[k*N + j];
      }
    }
  }

  double end_time = omp_get_wtime();

  std::cout << omp_get_max_threads() << " " << (end_time - start_time)
            << std::endl;

  return 0;
}
