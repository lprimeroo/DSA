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

bool *visited ;
list<int> *adj ;

void DFS(int sourcenode,int nodes) {
  stack<int> s;
  visited[sourcenode] = true ;
  cout << sourcenode << endl ;
  s.push(sourcenode) ;
  int flag ;
  while(!s.empty()) {
    sourcenode = s.top() ;
    flag = 0 ;
    list<int>::iterator i ;
    for(i=adj[sourcenode].begin(); i!=adj[sourcenode].end(); ++i) {
      if(!visited[*i]){
        cout << *i << endl ;
        visited[*i] = true ;
        s.push(*i) ;
        sourcenode = s.top() ;
        flag =1 ;
        break ;
      }
    }
    if(flag==0){
      s.pop() ;
    }
  }
}

int main() {
  int nodes, edges, sourcenode ,u , v;
  cin >> nodes ;

  visited = new bool[nodes] ;
  adj = new list<int>[nodes] ;
  memset(visited,false,sizeof(visited)) ;
  cin >> edges ;

  for(int i=0;i<edges;i++){
    cin >> u >> v ;
    adj[u].push_back(v) ;
  }

  cin >> sourcenode ;
  DFS(sourcenode,nodes) ;
  return 0 ;
}
