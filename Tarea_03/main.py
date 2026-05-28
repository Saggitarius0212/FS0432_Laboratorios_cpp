import lorenz_methods
import matplotlib.pyplot as plt
import numpy as np

ti = 0
tf = 40

h = 0.001

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

N = int(((tf-ti)/h) + 1)
t = np.linspace(ti, tf, int(N))

sol_euler = lorenz_methods.euler(h, ti, tf, xi, yi, zi)
sol_rk2 = lorenz_methods.rk2(h, ti, tf, xi, yi, zi)
sol_rk4 = lorenz_methods.rk4(h, ti, tf, xi, yi, zi)

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
	
fig = plt.figure(figsize=(10,10), dpi=130)
ax = fig.add_subplot(111, projection="3d")

ax.plot(x_euler, y_euler, z_euler, label="Euler", linewidth=0.7, color="blue")
ax.plot(x_rk2, y_rk2, z_rk2, label="RK2", linewidth=0.7, color="orange")
ax.plot(x_rk4, y_rk4, z_rk4, label="RK4", linewidth=0.7, color="red")


ax.set_xlabel("Eje X")
ax.set_ylabel("Eje Y")
ax.set_zlabel("Eje Z")

plt.legend()
plt.show()

