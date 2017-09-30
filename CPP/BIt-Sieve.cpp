#include <bits/stdc++.h>
#define MAX 5000000
using namespace std;
 
 
long long int BIT[MAX+2];
bool prime[MAX+1];
 
void update(int index, int val){
    //arr+=val;
    ++index;
    while(index<=MAX+1){
        BIT[index]+=val;
        index+=(index&-index);
    }
 
}
long long int getsum(int index){
    ++index;
    long long int sum=0;
    while(index>0){
        sum+=BIT[index];
        index-=(index&-index);
    }
    return sum;
}
 
 
 
void SieveOfEratosthenes(int n)
{
 
 
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
 
        if (prime[p] == true)
        {
 
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }  
 
}
void filler(){
    fill(BIT,BIT+MAX+1,0);
    SieveOfEratosthenes(MAX);
    for(int i=2;i<=MAX;++i){
        if(prime[i]) update(i,i);
    }
 
}
 
 
 
 
 
int main()
{
    //int n =5000000;
    filler();
    long long int test,n,m;
 
    //cout<<getsum(7)<<endl;
    // for(int i=0;i<12;++i){
    //     cout<<BIT[i]<<" ";
    // }
    cin>>test;
    for(int i=0;i<test;++i){
        cin>>n>>m;
        cout<<getsum(m)-getsum(n-1)<<endl;
    }
 
    return 0;
}

