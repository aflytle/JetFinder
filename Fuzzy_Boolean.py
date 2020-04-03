#Script to take 2d array of means and their std devs to output fuzzy boolean
#Aidan Lytle

def Matching(a, z):
    net = 1.0
    l = len(z)
    for i in range(l):
        if z[i] > a[i][0] + a[i][1]:
            net = net - (1.0/l)
        elif z[i] < a[i][0] - a[i][1]:
            net = net - (1.0/l)
        else: continue
    return net

if __name__ == "__main__":
    print(Matching(sys.argv[1],sys.argv[2]))
