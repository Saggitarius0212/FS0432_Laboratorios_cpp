# Laboratorio 10 - Ecuación de Poisson 1D: Jacobi y Gauss-Seidel

Nombre: Jorge André Hernández Villalobos
Carné: C5F981

Curso: FS-0432 Física Computacional

Compilar Jacobi como:

g++ poisson_1d_Jacobi.cpp -o poisson_1d_Jacobi.x \
    -I$CONDA_PREFIX/include/python3.11 \
    -I$(python -c "import numpy; print(numpy.get_include())") \
    -L$CONDA_PREFIX/lib \
    -lpython3.11 \
    -Wl,-rpath,$CONDA_PREFIX/lib
    
Compilar Gauss-Seidel como:

g++ poisson_1d_GaussSeidel.cpp -o poisson_1d_GaussSeidel.x \
    -I$CONDA_PREFIX/include/python3.11 \
    -I$(python -c "import numpy; print(numpy.get_include())") \
    -L$CONDA_PREFIX/lib \
    -lpython3.11 \
    -Wl,-rpath,$CONDA_PREFIX/lib
    
Ejecutar Jacobi como:

./poisson_1d_Jacobi.x

Ejecutar Gauss-Seidel

./poisson_1d_GaussSeidel.x
