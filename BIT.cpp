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

int getSum(int BITree[],int j,int n){
	int sum = 0 ;
	j = j + 1 ;
	while(j>0){
		sum = sum + BITree[j] ;
		j = j - (j&(-j)) ;
	}
	return sum ;
}

int updateTree(int BITree[], int i, int value, int n) {
	i = i + 1 ;
	while(i<=n){
		BITree[i] = BITree[i] + value ;
		i = i + ( i & ( -i ) ) ;
	}
}

int main(int argc, char const *argv[]) {
  int freq[] = {2,1,1,3,2,3,4,5,6,7,8,9} ;
  int n = sizeof(freq) / sizeof(freq[0]) ;
  int BITree[n+1] ;
  memset(BITree,0,sizeof(BITree)) ;
  for(int i=0;i<n;i++) //construction phase
  	updateTree(BITree,i, freq[i],n) ;
  cout << "Sum before Update : " << getSum(BITree,5,n) ;
  freq[3] = freq[3] + 6 ;
  updateTree(BITree,3,6,n) ;
  cout << "\nSum after update : " << getSum(BITree,5,n) ;
  return 0;
}
