from fractions import gcd
from random import randint

def pollardRho(n):
    if n%2 is 0:
        return 2
    (x,y,g) = (randint(1, n), randint(1, n), 1)
    while g is 1:
        x = (x**2 + 1) % n
        y = ((y**2 + 1) % n)**2 + 1 % n
        g = gcd(abs(y-x), n)
        # Failure, restart with different values
        if g is n:
            (x,y,g) = (randint(1, n), randint(1, n), 1)
    return g

if __name__ == "__main__":
    n = int(input("Enter a number to factorize: "))
    print (pollardRho(n))
