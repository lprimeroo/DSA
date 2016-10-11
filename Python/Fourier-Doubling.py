mem = dict()
 
def fib(n):
    if n <= 2:
        return 1
    if n in mem:
        return mem[n]
    k = n/2
    a = fib(k + 1)
    b = fib(k)
    ans = 0
    if n % 2 == 1:
        ans = a*a + b*b
    else:
        ans = b*(2*a - b)
    mem[n] = ans
    return ans
 
if __name__ == "__main__":
    n = int(raw_input("Enter n(0 to quit) : "))
    while n:
        print fib(n)
        n = int(raw_input("Enter n(0 to quit) : "))
