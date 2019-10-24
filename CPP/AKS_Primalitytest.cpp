
// C++ code to check if number is prime. This 
// program demonstrates concept behind AKS 
// algorithm and doesn't implement the actual 
// algorithm (This works only till n = 64) 
#include <bits/stdc++.h> 
using namespace std; 
  
// array used to store coefficients . 
long long c[100]; 
  
// function to calculate the coefficients 
// of (x - 1)^n - (x^n - 1) with the help 
// of Pascal's triangle . 
void coef(int n) 
{ 
    c[0] = 1; 
    for (int i = 0; i < n; c[0] = -c[0], i++) { 
        c[1 + i] = 1; 
  
        for (int j = i; j > 0; j--) 
            c[j] = c[j - 1] - c[j]; 
    } 
} 
  
// function to check whether 
// the number is prime or not 
bool isPrime(int n) 
{ 
    // Calculating all the coefficients by 
    // the function coef and storing all 
    // the coefficients in c array . 
    coef(n); 
  
    // subtracting c[n] and adding c[0] by 1 
    // as ( x - 1 )^n - ( x^n - 1), here we 
    // are subtracting c[n] by 1 and adding 
    // 1 in expression. 
    c[0]++, c[n]--; 
  
    // checking all the coefficients whether 
    // they are divisible by n or not. 
    // if n is not prime, then loop breaks 
    // and (i > 0). 
    int i = n; 
    while (i-- && c[i] % n == 0) 
        ; 
  
    // Return true if all coefficients are 
    // divisible by n. 
    return i < 0; 
} 
  
// driver program 
int main() 
{ 
    int n = 37; 
    if (isPrime(n)) 
        cout << "Prime" << endl; 
    else
        cout << "Not Prime" << endl; 
    return 0; 
} 
