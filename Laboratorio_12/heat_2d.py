import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


# -----------------------------
# Parametros fisicos y numericos
# -----------------------------

Lx = 1.0
Ly = 1.0

Nx = 100
Ny = 100

kappa = 1.0

h = Lx / Nx

r = 0.20
t_final = 0.1
snapshot_interval = 20

# TODO:
# calcular 
# dt
# num_steps

dt = (r*h*h)/kappa

# -----------------------------
# Condicion inicial
# -----------------------------

u = np.zeros((Nx + 1, Ny + 1))

# -----------------------------
# Condiciones de frontera
# -----------------------------

def aplicar_frontera(u,t):
	# TODO:
	# implementar las condiciones de frontera
    	
	for i in range(1,Nx+1):
		u[0][i] = np.abs(np.sin(100*np.pi*t))
		u[Ny][i] = np.abs(np.cos(100*np.pi*t))
		u[i][0] = 0
		u[i][Nx] = 0


# -----------------------------
# Evolucion temporal
# -----------------------------

snapshots = []
tiempos = []

u_new = np.copy(u)

for n in range(int(t_final/dt) + 1):

	# TODO:
	# guardar snapshots y tiempos
	#
	# cuidado con copias superficiales

	aplicar_frontera(u,n*dt)

	if n % snapshot_interval == 0 :
		snapshots.append(np.copy(u))
		tiempos.append(n*dt)

	# TODO:
	# completar la actualización
	#
	# aplicar condiciones de frontera
	#
	# preparar arreglos u y u_new para siguiente iteración

	for j in range(1,Ny):
		for i in range(1,Nx):
			u_new[j][i] = (1-4*r)*u[j][i] + r*(u[j][i+1] + u[j][i-1]
			+ u[j+1][i] + u [j-1][i])
	
	u = u_new
	
# -----------------------------
# Animacion
# -----------------------------

fig, ax = plt.subplots(figsize=(6, 5))

im = ax.imshow(
	snapshots[0].T,
	origin="lower",
	extent=[0, Lx, 0, Ly],
	cmap="hot",
	vmin=0.0,
	vmax=np.max(snapshots[0])
)

cbar = plt.colorbar(im, ax=ax)
cbar.set_label("Temperatura")

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_title("Ecuacion de calor 2D")

time_text = ax.text(
	0.02,
	0.95,
	"",
	transform=ax.transAxes,
	color="white",
	fontsize=11,
	verticalalignment="top"
)


def actualizar(frame):

	im.set_data(snapshots[frame].T)
	
	im.set_clim(vmin=0.0, vmax=np.max(snapshots[0]))
	
	time_text.set_text(f"t = {tiempos[frame]:.4f}")
	
	return im, time_text


anim = FuncAnimation(
	fig,
	actualizar,
	frames=len(snapshots),
	interval=80,
	blit=True
)

anim.save("calor_2d.gif", writer="pillow", fps=15)

plt.show()
