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
#include <time.h>
#include <stdlib.h>
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

int pollardRho(int n) {
  if(n%2==0)
    return 2 ;
  srand (time(NULL)) ; // equation used here is f(x) = (x*x + a) mod n
  int x, y , g=1 , a;
  x = rand() % n + 1 ;
  y = x ;
  a = rand() % n + 1 ;
  while(g==1) {
    x = ((x*x) + a)%n ;  // x =f(x)
    y = ((y*y) + a)%n ;
    y = ((y*y) + a)%n ;  // y =f(f(y))
    g = gcd(abs(x - y), n) ;
  }
  return g ;
}

int main(int argc, char const *argv[]) {
  int n , result ;
  cin >> n ;
  result = pollardRho(n) ;
  cout << result << endl << n/result;
  return 0;
}
