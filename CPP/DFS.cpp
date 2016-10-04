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

list<int> *adj ;
bool *visited ;


void DFS(int sourcenode, int nodes) {
	visited[sourcenode] = true ;
	cout << sourcenode << endl ;
	list<int>::iterator i ;
	for(i = adj[sourcenode].begin(); i!=adj[sourcenode].end(); ++i) {
		if(!visited[*i]) {
			DFS(*i,nodes) ;
		}
	}
}

int main(int argc, char const *argv[]) {
	int nodes, edges, sourcenode ,u , v;
	cin >> nodes ;
	visited = new bool[nodes] ;
	adj = new list<int>[nodes] ;

	cin >> edges ;
	for(int i=0;i<edges;i++){
		cin >> u >> v ;
		adj[u].push_back(v) ;
	}

	cin >> sourcenode ;
	DFS(sourcenode,nodes) ;
	return 0;
}