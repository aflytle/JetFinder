import numpy as np
import os
from ripser import Rips
from ripser import ripser
from persim import plot_diagrams

rips = Rips()

def Data_Puller_Rips(a):
    b = open(a, "r")
    Data = []
    for line in b:
        line = line.split()
        z = [float(line[0]), float(line[1]), float(line[2])]
        Data.append(z)
    Data = np.array([np.array(i) for i in Data])
    return Data

def Data_Puller_ripser(a):
    b = open(a, "r")
    Data = []
    for line in b:
        line = line.split()
        z = [float(line[0]), float(line[1]), float(line[2])]
        Data.append(z)
    Data = np.array([np.array(i) for i in Data])
    return Data

if __name__ == "__main__":
    for root, dirs, files in os.walk("."):
        for name in files:
            if name.endswith(".txt"):
                #diagrams = rips.fit_transform(Data_Puller(name))
                #rips.plot(diagrams)
                diagrams = ripser(Data_Puller_ripser(name))['dgms']
                plot_diagrams(diagrams, show=True)
