import lorenz_methods
import matplotlib.pyplot as plt
import numpy as np

ti = 0
tf = 40

h = 0.01
e = 1e-8

xi = 1
yi = 1
zi = 1

x_euler = []
y_euler = []
z_euler = []

x_rk2 = []
y_rk2 = []
z_rk2 = []

x_rk4 = []
y_rk4 = []
z_rk4 = []

x2_rk4 = []
y2_rk4 = []
z2_rk4 = []

d = []

N = int(((tf-ti)/h) + 1)
t = np.linspace(ti, tf, int(N))

sol_euler = lorenz_methods.euler(h, ti, tf, xi, yi, zi)
sol_rk2 = lorenz_methods.rk2(h, ti, tf, xi, yi, zi)
sol_rk4 = lorenz_methods.rk4(h, ti, tf, xi, yi, zi)
sol2_rk4 = lorenz_methods.rk4(h, ti, tf, xi+e , yi, zi)

for euler in sol_euler:
	x_euler.append(euler[0])
	y_euler.append(euler[1])
	z_euler.append(euler[2])
	
for rk2 in sol_rk2:
	x_rk2.append(rk2[0])
	y_rk2.append(rk2[1])
	z_rk2.append(rk2[2])
	
for rk4 in sol_rk4:
	x_rk4.append(rk4[0])
	y_rk4.append(rk4[1])
	z_rk4.append(rk4[2])

for rk4 in sol2_rk4:
	x2_rk4.append(rk4[0])
	y2_rk4.append(rk4[1])
	z2_rk4.append(rk4[2])

# Calcular separación

for i in range(0, len(x_rk4)):
	dx = np.abs(x_rk4[i] - x2_rk4[i])
	dy = np.abs(y_rk4[i] - y2_rk4[i])
	dz = np.abs(z_rk4[i] - z2_rk4[i])

	d.append(np.sqrt(dx*dx + dy*dy + dz*dz))

print("Separación Inicial:", d[0])
print("Separación Final:", d[-1])

# Gráfica Método Euler

fig = plt.figure(figsize=(10,10), dpi=130)
ax = fig.add_subplot(111, projection="3d")

ax.plot(x_euler, y_euler, z_euler, label="Euler", linewidth=0.7, color="blue")

ax.set_title("Trayectoria Euler en función del tiempo")
ax.set_xlabel("Eje X")
ax.set_ylabel("Eje Y")
ax.set_zlabel("Eje Z")

plt.legend()
plt.savefig("trayectoria_3d_euler.png")
print("trayectoria_3d_euler.png descargado...")

# Gráfica Método RK2

fig = plt.figure(figsize=(10,10), dpi=130)
ax = fig.add_subplot(111, projection="3d")

ax.plot(x_rk2, y_rk2, z_rk2, label="RK2", linewidth=0.7, color="orange")

ax.set_title("Trayectoria RK2 en función del tiempo")
ax.set_xlabel("Eje X")
ax.set_ylabel("Eje Y")
ax.set_zlabel("Eje Z")

plt.legend()
plt.savefig("trayectoria_3d_rk2.png")
print("trayectoria_3d_rk2.png descargado...")

# Gráfica Método RK2

fig = plt.figure(figsize=(10,10), dpi=130)
ax = fig.add_subplot(111, projection="3d")

ax.plot(x_rk4, y_rk4, z_rk4, label="RK4", linewidth=0.7, color="red")
ax.plot(x2_rk4, y2_rk4, z2_rk4, label="RK4_E", linewidth=0.7, color="green")

ax.set_title("Trayectorias RK4 y RK4_E en función del tiempo")
ax.set_xlabel("Eje X")
ax.set_ylabel("Eje Y")
ax.set_zlabel("Eje Z")

plt.legend()
plt.savefig("trayectoria_3d_rk4.png")
print("trayectoria_3d_rk4.png descargado...")

#Gráfico de sensibilidad

fig = plt.figure(figsize=(10,10), dpi=130)

plt.plot(d, label="Separación")

plt.title("Separación entre RK4 y RK4_E en función del tiempo")
plt.xlabel("Tiempo")
plt.ylabel("Separación")
plt.grid("True")

plt.legend()
plt.savefig("sensibilidad.png")
print("sensibilidad.png descargado...")

plt.show()

