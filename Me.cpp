//saru95
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <math.h>
#include <utility>
#include <cmath>
#include <limits.h>
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
#include <time.h>
#include <stdlib.h>
#include <numeric>
#include <memory.h>

#define all(a) (a).begin(),(a).end()
#define gcd __gcd
#define bitcount(a) __builtin_popcount(a)

using namespace std;

typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::pair<int, int> pii;
typedef std::set<int> si;
typedef std::map<std::string, int> msi;

void matmul(long long a[][2], long long b[][2], long long c[][2], long long modulo) {
  for(int i=0;i<2;i++) {
    for(int j=0;j<2;j++) {
      c[i][j] = 0 ;
      for(int k=0;k<2;k++) {
        c[i][j] = c[i][j] + (a[i][k]*b[k][j]) ;
        c[i][j] = c[i][j] % modulo ;
      }
    }
  }

}

void mat(long long z[][2],long long n, long long result[][2], long long modulo) {
  result[0][0] = 1 ;
  result[0][1] = 0 ;
  result[1][0] = 0 ;
  result[1][1] = 1 ;
  long long temp[2][2] ;
  while(n>0) {
    matmul(result,z,temp,modulo) ;
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        result[i][j] = temp[i][j] ;
      }
    }
    matmul(z,z,temp,modulo) ;
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        z[i][j] = temp[i][j] ;
      }
    }
    n = n / 2 ;
  }
  return ;
}

long long fibo(long long n, long long modulo) {
  long long f ;
  long long z[2][2] = {{1,1},{1,0}}, result[2][2] ; //result is the modified matrix
  if(n>2) {
    mat(z,n-2,result, modulo) ;
    f = result[0][0]*1 + result[0][1]*0 ;
  }
  else
    f = n - 1 ;
  return f ;
}

int main(int argc, char const *argv[]) {
  long long n, modulo ;
  cin >> n >> modulo ;
  cout << fibo(n,modulo) ;
  return 0;
}
