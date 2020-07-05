#Script to pull the top 5 lifetimes in the 0th homology
#Aidan Lytle
import sys
import re


#Pull top five persistence values
def puller(a, z):
    filename = "TestFivePoint.txt"
    file_=open(filename,"w")
    b = open(a)
    c = b.readlines()
    d = (reversed(c))
    e = []
    for line in d:
        f = line.split(",")
        nu = f[::-1]
        if re.match(r'^-?\d+(?:\.\d+)?$', nu[0]) is None:
            pass
        else:
            g = nu[0]
            h = str(g)[:5]
            e.append(float(h))
    #file_.write(f"{z},{e[1]},{e[2]},{e[3]},{e[4]},{e[5]}\n")
    file_.write(f"{e[1]}\n,{e[2]}\n,{e[3]}\n,{e[4]}\n,{e[5]}\n")
    file_.close()
    return filename





if __name__ == "__main__":
    #arguments are, in order:
    #energy (given in BashEvent),
    #and the file it will be reading
    e = puller(sys.argv[1], sys.argv[2])
    #file_ = open(f"{sys.argv[1][0]}mean_points.txt", "w+")
    #file_.write(f"{sys.argv[1]},{e[1]},{e[2]},{e[3]},{e[4]},{e[5]}\n")
    #file_.write(f"{e[1]},{e[2]},{e[3]},{e[4]},{e[5]}\n")
    #file_.close()
    puller(sys.argv[1], sys.argv[2])

