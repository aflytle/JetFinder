#Script to pull the top 5 lifetimes in the 0th homology
#Aidan Lytle
import sys



#Pull top five persistence values
def puller(a, z):
    file_ = open(f"{z}mean_points.txt", "a")
    b = open(a)
    c = b.readlines()
    d = reversed(c[100:])
    e = []
    for line in d:
        f = line.split(",")
        g = f[1]
        h = str(g)[:5]
        e.append(float(h))
    file_.write(f"{z},{e[1]},{e[2]},{e[3]},{e[4]},{e[5]}\n")
    file_.close()
    return e[1:7]





if __name__ == "__main__":
    #arguments are, in order:
    #energy (given in BashEvent),
    #and the file it will be reading
    puller(sys.argv[2], sys.argv[1])
    
