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

int nodes , parent;

bool bfs(int rgraph[nodes][nodes], int source, int sink) {
  bool visited[nodes] ;
  memset(visited,false, sizeof(visited)) ;
  queue<int> q ;
  q.push(source) ;
  visited[source] = true ;
  parent[source] = -1 ;
  while(!q.empty()) {
    int u = q.front() ;
    q.pop() ;
    for(int i=0;i<nodes;i++) {
      if(visited[i]==false && rgraph[u][i] > 0){
        q.push(i) ;
        parent[i] = u ;
        visited[i] = true ;
      }
    }
  }
  return (visited[sink]==true) ;
}


void FFA(int graph[nodes][nodes], int source, int sink) {
  int rgraph[nodes][nodes], u ;

  for(int i=0;i<nodes,i++) {
    for(int j=0;j<nodes;j++) {
      rgraph[i][j] =  graph[i][j] ;  //initialising Residual Graph
    }
  }

  int maxflow = 0 ; //parent used by bfs to store parent
  parent = new int[nodes] ;
  while (bfs(rgraph, source, sink)) {
      int parentflow = INT_MAX ;
      for(int i=sink;i!=source;i=parent[i]) { //finding min capacity for a path
          u = parent[i] ;
          parentflow = min(parentflow, rgraph[u][i]) ;
      }

      for(int i=sink;i!=source;i=parent[i]) {
        u = parent[i] ;
        rgraph[u][i] -= parentflow ;
        rgraph[i][u] += parentflow ; //adding to the reverse edge
      }
      maxflow += parentflow ;
  }
  return maxflow ;
}


int main(int argc, char const *argv[]) {
  cin >> nodes ;
  int graph[nodes][nodes] ;
  for(int i=0;i<nodes;i++) {
    for(int j=0;j<nodes;j++) {
      cin >> graph[i][j] ;
    }
  }
  cin >> start >> sink ;
  FFA(graph, source, sink) ;
  return 0;
}
