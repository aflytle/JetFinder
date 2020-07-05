#Script to take 2d array of means and their std devs to output fuzzy boolean
#Aidan Lytle
import sys
import ast

def Matching(a, z):
    net = 1.0
    l = len(z)
    #compare each mean
    for i in range(l):
        if float(z[i]) > float(a[0][i]) + float(a[1][i]):
            net = net - (1.0/l)
        elif float(z[i]) < float(a[0][i]) - float(a[1][i]):
            net = net - (1.0/l)
        else: continue
    return net

if __name__ == "__main__":
    file1=open(sys.argv[1], "r")
    file2=open(sys.argv[2], "r")
    a = file1.readlines()
    z = file2.readlines()
    a = [i.strip(",") for i in a]
    a = [i.strip() for i in a]
    a = [float(i) for i in a]
    z = [ast.literal_eval(n) for n in z]
    print(Matching(z,a))
