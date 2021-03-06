#Script to open and display Collisions visually
#Aidan Lytle

from mpl_toolkits.mplot3d import Axes3D

import matplotlib.pyplot as plt
import numpy as np
import datetime

def File_Reader(a):
    b = open(a, "r")
    x = []
    y = []
    z = []
    for line in b:
        queue = line.split()
        x.append(queue[0])
        y.append(queue[1])
        z.append(queue[2])

    
    b.close()

    return [x, y, z]

def Scatter_Plotter(q):

    npa = np.asarray(q, dtype=np.float32)
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(npa[0], npa[1], npa[2], c = 'r', marker = 'o')
    ax.set_xlabel("px")
    ax.set_ylabel("py")
    ax.set_zlabel("pz")

    x = datetime.datetime.now()
    plt.show()
    plt.savefig(f"fig_{x.strftime('%Y')}_{x.strftime('%m')}_{x.strftime('%d')}_{x.strftime('%H')}_{x.strftime('%M')}.png")
    return
    
if __name__ == "__main__":
    Scatter_Plotter(File_Reader(input("Type filename exactly: ")))
    
