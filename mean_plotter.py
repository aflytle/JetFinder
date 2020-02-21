import pandas as pd
import matplotlib.pyplot as plt
import os
import filetype

def mean(a):
    df = pd.read_csv(a)
#    df.columns=["1","2","3","4","5","6"]
    df = pd.DataFrame(df)
    obj = df.mean(axis=0)
    return obj

if __name__ == "__main__":
    files=[ os.path.join("MeanVals", i) for i in os.listdir("MeanVals/") ]
    z = [mean(i) for i in files]
    z = [i.values.tolist() for i in z]
    
       
#    for i in z:
#        i = i.values.tolist()
    print(z)
    x = [i[0] for i in z]
    y1 = [i[1] for i in z]
    y2 = [i[2] for i in z]
    y3 = [i[3] for i in z]
    y4 = [i[4] for i in z]
    y5 = [i[5] for i in z]

    plt.plot(x, y1, "rs", x, y2, "bs", x, y3, "gs", x, y4, "r^", x, y5, "g^")
    plt.show()


#def plotter():
#    for root, dirs, files in os.walk(".", topdown=False):
#        for name in files
    
