# Github username : yatingupta10
# Website : http://www.yatingupta.me/

# Function to return gcd of a and b
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)

# A simple method to evaluate Euler Totient Function
def phi(n):
    result = 1
    for i in range(2, n):
        if gcd(i, n) == 1:
            result = result + 1
    return result

# Driver program to test above function
if __name__ == "__main__":
    for n in range(1, 11):
      print ("phi({f}) = {f1}\n".format(f = n, f1 = phi(n)))
