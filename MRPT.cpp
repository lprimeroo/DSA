#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

//Fast Exponential returns a^b%mod
long long expo(long long a , long long b , long long mod)
{
    if(b==0)
        return 1;
    else if(b%2==0)
        return expo(((a%mod)*(a%mod))%mod,b/2,mod);
    else
        return ((a%mod)*(expo(((a%mod)*(a%mod))%mod,b/2,mod)%mod)%mod);
}

//As miller rabin is probabalistic so this function returns 1 if number is probably prime
int test(int m,int n)
{
    long long r=rand()%(n-4) + 2; //Taking any random number
    long long p=expo(r,m,n);
    if(p==1 || p==n-1)
        return 1;
    while(m!=n-1)
    {
        p=expo(p,2,n);
        m*=2;
 
        if (p == 1)      
            return 0;
        if (p == n-1)    
            return 1;
    }
    return 0;
}

//This function will do iterations on the number it times on test function
int checkPrime(int n,int it)
{
    if(n==2||n==3)
        return 1;
    if(n<=4)
        return 0;
    int d=n-1;
    while(!(d%2))
    {
        d/=2;
    }
    while(it--)
    {
        if(!test(d,n))
            return 0;
    }
    return 1;
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int it,n;
    cout<<"Enter the number of iterations and number "<<endl;
    cin>>it>>n;
    if(checkPrime(n,it))
        cout<<"prime"<<endl;
    else
        cout<<"Not prime";
    return 0;
}