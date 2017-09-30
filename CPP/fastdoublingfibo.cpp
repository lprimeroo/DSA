// C++ implementation for finding the nth fibonacci number using the fast doubling method
#include<iostream>

using namespace std;
long long int a,b,c,d;

long long int* fib(long long int n) //returns {f(n),f(n+1)}
{
    long long int fibs[2], *half_fib;
    half_fib = new long long int[2];
    if(n==0)
    {
        fibs[0]=0;
        fibs[1]=1;
        return fibs;
    }
    half_fib = fib(n/2);
    c = half_fib[0];
    d = half_fib[1];
    a = (2*d - c)*c;
    b = (c*c + d*d);

    if(n%2 == 0)
    {
        fibs[0]= a;
        fibs[1]= b;
    }
    else
    {
        fibs[0]= b;
        fibs[1]= a+b;
    }
    return fibs;
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)[0];
    return 0;
}
