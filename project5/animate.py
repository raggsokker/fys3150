import pyarma as pa
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


#load matrices

U = pa.cx_cube()
U.load("U_double_slit.bin")

#make as array and compute probability from real and imaginary part
U = np.asarray(U)
P = np.conj(U)*U
#make it as real dtype
P = P.real


# Array of time points
dt = 2.5e-5
t_points = np.arange(0, 1+dt, dt)

# animate it!


# Some settings
fontsize = 12
t_min = t_points[0]


# Create figure
fig = plt.figure()
ax = plt.gca()

# Create a colour scale normalization according to the max z value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=np.max(P[0]))

# Plot the first frame
img = ax.imshow(P[0], extent=[0,1,0,1], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("y", fontsize=fontsize)
plt.ylabel("x", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("U(x,y,t)", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = {:.3e}".format(t_min), color="white",
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

# Function that takes care of updating the z data and other things for each frame
def animation(i):
    # Normalize the colour scale to the current frame?
    norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=np.max(P[i]))
    img.set_norm(norm)

    # Update z data
    img.set_data(P[i])

    # Update the time label
    current_time = t_min + i * dt
    time_txt.set_text("t = {:.3e}".format(current_time))

    return img

# Use matplotlib.animation.FuncAnimation to put it all together
anim = FuncAnimation(fig, animation, interval=1, frames=np.arange(0, len(P), 2), repeat=False, blit=0)

# Run the animation!
plt.show()

# # Save the animation
#anim.save('./circular2.mp4', writer="ffmpeg", bitrate=-1, fps=30)

