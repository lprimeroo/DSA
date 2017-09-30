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

int v ;
int graph[50][50];

void FW() {
  int dis[v][v] ;

  for(int i =0;i<v;i++) { //initializing the distance array with input array
    for(int j=0;j<v;j++) {
      dis[i][j] = graph[i][j] ;
    }
  }
  for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++){
            for (int j = 0; j < v; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j] ;
            }
        }
    }
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if (dis[i][j] == 9999)
                cout << "INF " ;
            else
                cout << dis[i][j] << "\t" ;
        }
        cout << endl ;
    }


}

int main(int argc, char const *argv[]) {
  cin >> v ; //number of vertices
  for(int i =0;i<v;i++) {
    for(int j=0;j<v;j++) {
      cin >> graph[i][j] ;  //enter 9999 for no edge
    }
  }
  FW() ;
  return 0;
}
