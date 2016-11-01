#this is karatsuba's multiplication method of 2 n-digit integers
# This is a divide and conquer algorithm implemented in Python

__author__ = "Anirudh Swaminathan"

import math

def main():
    x = int(raw_input("Enter 1st integer\n"))
    y = int(raw_input("Enter 2nd integer\n"))
    x = list(str(x))
    y = list(str(y))
    result = int(kmult(x,y))
    print "The product is "+str(result)

# Recursive function for computation of @param x, and @param y
def kmult(x,y):
    n = len(x) if len(x)>len(y) else len(y)
    if n==1:
        return int(x[0])*int(y[0])

    # Make the integers to multiplied equal length
    for _ in range(len(x),n):
        x.insert(0,'0')
    for _ in range(len(y),n):
        y.insert(0,'0')
    a = []
    b = []
    c = []
    d = []
    for i in range(n):
        if i<n/2:
            a.append(x[i])
            c.append(y[i])
        else:
            b.append(x[i])
            d.append(y[i])

    # Divide the input integers each into two halves
    ac = kmult(a,c)
    bd = kmult(b,d)
    a = int(''.join(a))
    b = int(''.join(b))
    c = int(''.join(c))
    d = int(''.join(d))
    apb = list(str(a+b))
    cpd = list(str(c+d))
    sums = kmult(apb,cpd)
    if n%2 != 0:
        p = n+1
    else:
        p = n
    return (10**p)*ac + bd + (10**math.ceil(n/2.0))*(sums - ac -bd)

if __name__ == '__main__':
    main()
