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

int phi(int n) {
  int result = n ;
  for(int i=2;i*i<=n;++i) {
    if(n%i==0){
      while(n%i==0){
        n = n / i ;
      }
      result = result - (result/i) ;
    }
  }
  if(n>1)
      result = result - (result/n) ;
  return result ;
}

int main(int argc, char const *argv[]) {
  int n , result ;
  cin >> n ;
  result = phi(n) ;
  cout << result << endl ;
  return 0;
}
