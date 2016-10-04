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
#include <functional>
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

vector< pair<int , int > > *adj ;
bool *visited ;
int d[1024] ;  // distance array

void dij(int source,int nodes) {
	priority_queue< pii , vector< pii > , greater<pii> > q ;
	int u, cost ,v , w;
	q.push(0,source) ;
	d[source] = 0 ;
	while(!q.empty()) {
		cost = q.top().first ;
		u = q.top().second ;
		q.pop() ;
		if(d[u]<cost) continue ;

		for(int i=0;i<nodes;i++) {
			v = adj[u][i].first ;
			w = adj[u][i].second ;
			if(d[v] > d[u]+w) {
				d[v] = d[u] + w ;
				q.push(make_pair (d[v], v)) ;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int nodes, edges, sourcenode ,u , v, w;
	memset(d,0,sizeof(d)) ;
	cin >> nodes ;
	visited = new bool[nodes] ;
	adj = new vector< pair<int ,int > >[nodes] ;

	cin >> edges ;
	for(int i=0;i<edges;i++){
		cin >> u >> v >> w;
		adj[u].push_back(make_pair (v,w)) ;
	}

	cin >> sourcenode ;
	dij(sourcenode,nodes) ;
	return 0;
}