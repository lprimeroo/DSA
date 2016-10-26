#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <string>
typedef long long          ll;
using namespace std;
 
int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll mod;
 
inline ll multiply(ll a,ll b)   // O(1) for (a*b)%m
{  
    a %= mod;
    b %= mod;
    long double res = a;
    res *= b;
    ll c = ll(res / mod);
    a *= b;
    a -= c * mod;
    a %= mod;
    if (a < 0) a += mod;
    return a;
}
 
inline ll power(ll a,ll b) 
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=multiply(ans,a);
        }
        a=multiply(a,a);
        b>>=1;
    }
    return ans;
}
 
inline bool Miller(ll p) 
{
    if(p<2)  return false;
    if(p!=2 && !(p&1)) return false;
    for(int i=0;i<25;i++)
    {
        if(p==b[i])return true;
        else if(p%b[i]==0)return false;
    }
    int count = 0;
    long long s=p-1;
    while(!(s&1)) 
    {
        s/=2;
        count++;
    }
    ll accuracy=2;
    for(int i=0;i<accuracy;i++)
    {
        long long a=rand()%(p-1)+1;
        mod = p;
        long long x=power(a,s);
        if(x == 1 || x == p-1) continue;
        int flag = 0;
        for(int i = 1; i < count; i++) 
        {
            x = multiply(x,x);
            if(x == 1) return false;
            if(x == p-1) 
            {
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        return false;
    }
    return true;
}
//Main
int main()
{
    if(Miller(17)) cout<<"yes\n";
else cout<<"No";
}

