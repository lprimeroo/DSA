//saru95
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <math.h>
#include <utility>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cctype>
#include <queue>
#include <stdio.h>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <numeric>
#include <memory.h>
 
#define all(a) (a).begin(),(a).end()
#define gcd __gcd
#define bitcount __builtin_popcount
 
using namespace std;
 
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::pair<int, int> pii;
typedef std::set<int> si;
typedef std::map<std::string, int> msi; 

void Sieve(int n){
	bool checkArray[n+1] ;
	memset(checkArray, true, sizeof(checkArray)) ;
	checkArray[0] = false ;
	checkArray[1] = false ;
	for(int i=2;i<n+1;i++){
		for(int j=i+i;j<n+1;j+=i){
			checkArray[j] = false ;
		}
	}
	for(int i=0;i<n+1;i++){
		if(checkArray[i]!=false)
			cout << i << endl;
	}
}

int main(int argc, char const *argv[]){
	int n ;
	cin >> n ;
	Sieve(n) ;
	return 0 ;
}