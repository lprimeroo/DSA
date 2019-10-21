c = [0] * 100; 
  
# function to calculate the  
# coefficients of (x - 1)^n -  
# (x^n - 1) with the help 
# of Pascal's triangle . 
def coef(n): 
    c[0] = 1; 
    for i in range(n): 
        c[1 + i] = 1; 
        for j in range(i, 0, -1): 
            c[j] = c[j - 1] - c[j]; 
        c[0] = -c[0]; 
          
# function to check whether 
# the number is prime or not 
def isPrime(n): 
      
    # Calculating all the coefficients 
    # by the function coef and storing 
    # all the coefficients in c array . 
    coef(n); 
      
    # subtracting c[n] and adding  
    # c[0] by 1 as ( x - 1 )^n -  
    # ( x^n - 1), here we are  
    # subtracting c[n] by 1 and  
    # adding 1 in expression. 
    c[0] = c[0] + 1; 
    c[n] = c[n] - 1; 
      
    # checking all the coefficients  
    # whether they are divisible by  
    # n or not. if n is not prime,  
    # then loop breaks and (i > 0). 
    i = n; 
    while (i > -1 and c[i] % n == 0): 
        i = i - 1; 
      
    # Return true if all coefficients  
    # are divisible by n. 
    return True if i < 0 else False; 
  
# Driver Code 
n = 37; 
if (isPrime(n)): 
    print("Prime"); 
else: 
    print("Not Prime"); 