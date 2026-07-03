import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt("tiempos.txt")

num_procesos = datos[:,0]
valor_tiempos = datos[:,1]

plt.figure(figsize=(10,10))

plt.plot(num_procesos, valor_tiempos, marker="o")

plt.xlabel("Número de procesos")
plt.ylabel("Tiempos")
plt.title("Número de procesos vs Tiempo")
plt.grid(True)

plt.savefig("tiempo_vs_procesos.png")
plt.show()
