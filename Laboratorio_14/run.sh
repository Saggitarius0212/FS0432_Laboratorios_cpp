g++ -fopenmp matrix_multiplication.cpp -o matrix_multiplication.x

touch tiempos.txt

> tiempos.txt

for i in {1,2,4,8,16,32,64}
do

OMP_NUM_THREADS=$i ./matrix_multiplication.x >> tiempos.txt

done
