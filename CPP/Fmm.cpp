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
#define bitcount __builtin_popcount

using namespace std;

typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::pair<int, int> pii;
typedef std::set<int> si;
typedef std::map<std::string, int> msi;

long long int FastMultiplication(long long base, long long power, long long modulo) {
  long long result = 1 ;
  while(power>0) {
    if(!power%2)
      result = (result * base) % modulo ;
    base = (base * base) % modulo ;
    power = power / 2 ;
  }
  return result ;
}

int main(int argc, char const *argv[]) {
  long long int base, power, modulo ;

  cin >> base >> power >> modulo ;
  cout << FastMultiplication(base, power, modulo) ;
  return 0;
}
