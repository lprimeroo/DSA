#include<bits/stdc++.h>

using namespace std;

struct Res_gcd{
    int gcd,x,y;
    Res_gcd(int gcd, int x, int y){
        this -> gcd = gcd;
        this -> x   = x;
        this -> y   = y;
    }
};

/*
 * return object of Res_gcd
 * Res_gcd.gcd ==> gcd of a,b
 * Res_gcd.x and Res_gcd.y ==> x and y such that ax + by = gcd(a,b)
 * NOTE : a must not be 0 ==> if so ans is b,0,1
 */
Res_gcd gcd_extended(int a,int b){
    if(b%a==0)
        return Res_gcd(a,1,0);    //coz 1*a + 0*b = a { == gcd(a,b)}

    Res_gcd temp = gcd_extended(b%a,a);
    return Res_gcd( temp.gcd , temp.y - (b/a)*temp.x , temp.x );
}

/*
 * return multiplicative mod inverse of a under molulo m
 */
int mod_inverse(int a,int m){
    Res_gcd temp = gcd_extended(a,m);
    if(temp.gcd != 1)
        return -1;
    else
        return (temp.x%m + m)%m;
}

int main(){
	int t=1;
	cin>>t;
	while(t--){
        int a,m;
        cin>>a>>m;
        cout<<mod_inverse(a,m)<<endl;
	}
}
