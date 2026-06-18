import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt("tiempos.txt")

hilos = datos[:, 0]
tiempos = datos[:, 1]

plt.figure()

plt.plot(hilos, tiempos, marker="*")

plt.xlabel("Hilos")
plt.ylabel("Tiempos")
plt.title("Tiempo vs Hilos")

plt.grid(True)
plt.savefig("tiempo_vs_hilos.png")
print("tiempo_vs_hilos.png descargado...")

plt.show()
