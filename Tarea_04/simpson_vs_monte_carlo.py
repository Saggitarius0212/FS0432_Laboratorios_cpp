"""
Compara integración por Simpson vs Monte Carlo.

I = int_0^1 ... int_0^1 prod_i sin(pi x_i) dx_1 ... dx_d
"""

import numpy as np
from scipy.integrate import simpson
import time
import matplotlib.pyplot as plt

# d = 10  # dimensión del problema


dim = []
t_mc =[]
t_s = []
err_mc = []
err_s = []

for d in range(1,100):

	valor_analitico = (2.0 / np.pi)**d


	print(f"--- Integración en d={d} ---")
	print(f"Analítico:   {valor_analitico:.15f}")
# ---------------------------------------------------------
# MÉTODO DE MONTE CARLO
# ---------------------------------------------------------

	N_total_mc = 10**5

	t0_mc = time.time()
	
	productoria:float = 1
	sumatoria:float = 0

	for i in range(0,N_total_mc):

		x = np.random.uniform(0,1,d)

		productoria = np.prod(np.sin(np.pi*x))

		sumatoria += productoria


	integral_mc = (1/N_total_mc)*sumatoria

	t1_mc = time.time()
	
	diferencia_tmc = t1_mc - t0_mc
	
	error_mc = abs(integral_mc - valor_analitico)   

	print(
		f"Monte Carlo: {integral_mc:.15f} "
		f"(Error: {error_mc:.15f}, Tiempo: {diferencia_tmc:.4f}s)"
	)
	
	t_mc.append(diferencia_tmc)
	err_mc.append(error_mc)
	
# ---------------------------------------------------------
# MÉTODO DE SIMPSON
# ---------------------------------------------------------

	#N_simpson = 10
	#N_total_simpson = N_simpson**d

	#t0_simpson = time.time()

	#x_1d = np.linspace(0, 1, N_simpson)
	#malla = np.meshgrid(*[x_1d] * d, indexing="ij")

	#Z = np.prod([np.sin(np.pi * m) for m in malla], axis=0)

	#integral_simpson = Z
	#for _ in range(d):
		#integral_simpson = simpson(integral_simpson, x=x_1d, axis=0)

	#t1_simpson = time.time()
	
	#diferencia_ts = t1_simpson - t0_simpson
	
	#error_simpson = abs(integral_simpson - valor_analitico)

	#t_s.append(diferencia_ts)
	#err_s.append(error_simpson)
	
	#print(
		#f"Simpson:     {integral_simpson:.8f} "
		#f"(Error: {error_simpson:.8f}, Tiempo: {diferencia_ts:.4f}s)"
	#)
	
	dim.append(d)
	
plt.figure()

#plt.plot(dim, t_s ,label="Tiempos Simpson")
plt.plot(dim, t_mc,label="Tiempos Monte Carlo")

plt.legend()
plt.show()
