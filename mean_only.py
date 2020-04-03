import pandas as pd
import matplotlib.pyplot as plt
import os
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

def Mean():
    files=[ os.path.join("MeanVals", i) for i in os.listdir("MeanVals/") ]

    z = [mean(i) for i in files]
    m = [i[0].values.tolist for i in z]
    n = [j[1].values.tolist for j in  z]
                        
    return z

if __name__ == "__main__":
    Mean()
