#include <iostream>
#include <mpi.h>
#include <vector>
#include <cmath>
#include <iomanip>

double f(double x){

	return std::sin(x);
}

int main(int argc, char **argv) {

	// Iniciar MPI
	MPI_Init(&argc, &argv);

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	// Definir Matrices Completas
	const int N = 128000;

	std::vector<double> A(N);
	std::vector<double> B(N);

	// Definir Matrices locales
	int local_N = N / size;

	std::vector<double> local_A(local_N);
	std::vector<double> local_B(local_N);

	if (rank == 0) {
	
		// Dar valores para A y B
		for (int i = 0; i < N; i++) {
			A[i] = f((double)i);
			B[i] = 2 * f((double)i);
		}

		// Dar valores para A y B locales
		for (int i = 0; i < local_N; i++) {
			local_A[i] = A[i];
			local_B[i] = B[i];
		}
		
		// Distribuir los indices de las listas
		for (int p = 1; p < size; p++) {
		
			int start = p * local_N;

			MPI_Send(&A[start], local_N, MPI_DOUBLE, p, 0, MPI_COMM_WORLD);
			MPI_Send(&B[start], local_N, MPI_DOUBLE, p, 1, MPI_COMM_WORLD);
		}
	}
	else {
		// Recibir Información de las listas locales
		MPI_Recv(&local_A[0], local_N, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(&local_B[0], local_N, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}

// Sincronizar procesos

MPI_Barrier(MPI_COMM_WORLD);

double t0 = MPI_Wtime();

double local_producto = 0.0;	
	
// Realizar producto punto local
for (int i = 0; i < local_N; i++) {
		
    	local_producto += local_A[i]*local_B[i];
}

double tf = MPI_Wtime();

double local_time = tf - t0;

double tiempo_maximo = 0.0;

double global_producto = 0.0;

MPI_Reduce(&local_producto,
		&global_producto,
		1,
		MPI_DOUBLE,
		MPI_SUM,
		0,
		MPI_COMM_WORLD
);

MPI_Reduce(&local_time,
		&tiempo_maximo,
		1,
		MPI_DOUBLE,
		MPI_MAX,
		0,
		MPI_COMM_WORLD
);

// Imprimir resultado desde proceso 0
if (rank == 0) {
	
	std::cout << std::setprecision(10);
	std::cout << "Producto Punto: " << global_producto << std::endl;
	std::cout << "Cantidad de procesos: " << size << std::endl;
	std::cout << "Tiempo de proceso: " << tiempo_maximo << std::endl;
  }

  MPI_Finalize();

  return 0;
}

