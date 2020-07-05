import pandas as pd
import matplotlib.pyplot as plt
import os
import sys
import filetype

#Function to return Mean Lifetime and Std. Deviations
def mean(a):
    df = pd.read_csv(a)
    #df.columns=["1","2","3","4","5","6"]
    df = pd.DataFrame(df)
    obj1 = df.mean(axis=0)
    #added this to return the Std. Deviation March 17 2020
    obj2 = df.std(axis=0)
    return[obj1, obj2]

def Mean(b):
    files=[ os.path.join("MeanVals", i) for i in os.listdir("MeanVals/") ]

    z = [mean(i) for i in files]
#    print(z)
    m = [i[0].values.tolist() for i in z]
    n = [j[1].values.tolist() for j in  z]
#    print(m)

    filename="MeanValuesTimeOne.txt"
    file_=open(filename, "w")
    for i in range(len(m)):
        #Need to generalize this check to cover a range around the energy
        if float(m[i][0]) - float(b) >= 0 and float(m[i][0]) - float(b) < float(b):
            file_.write(f"{m[i]}\n")
            file_.write(f"{n[i]}\n")
        else:
            continue
    file_.close()

    return filename

if __name__ == "__main__":
    #takes energy and produces doc with lists of energies and std dev
    print(Mean(sys.argv[1]))
