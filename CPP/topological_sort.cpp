/*
The input graph should be a DAG. The program returns the topological order of the vertices.
*/

// monera
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f(i,a,b) for(int i =a; i <=b ; i++)
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define sqr(x) ((x)*(x))
#define sz(x) (int)(x.size())
#define EPS 1e-9
#define db(var) cout<<#var<<": "<<var<<" ";
#define el cout<<endl;
#define p(A,a,b)  f(i,a,b) cout<<A[i]<<" ";
#define sj  cout<<"OK"<<endl;
#define ll long long int 


//functions
#define count_1(n)    __builtin_popcountll(n)
#define gcd(a,b) __gcd(a,b)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define lcm(_1,_2)           ((_1/gcd(_1,_2))*(_2))

#define MOD 1000000007
#define PI acos(-1.0)
#define e exp(1.0)
#define EPS 1e-9
#define INF    2047483647
#define INFLL  9023372036854775807LL
const int MX=100005;

using namespace std;

vector<int> g[MX];
int deg[MX];

int main() 
{
	int n,m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v); // edge from u to v
		deg[v]++;
	}

	deque<int> qq;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			qq.push_back(i);
		}
	}

	vector<int> topoSortOrder;
	while(!qq.empty()) {
		int nod = qq.front();
		qq.pop_front();
		topoSortOrder.pb(nod);

		for(int i = 0; i < sz(g[nod]); i++) {
			int nnod = g[nod][i];
			deg[nnod]--;
			if (deg[nnod] == 0) {
				qq.push_back(nnod);
			}
		}
	}

	for (int i = 0; i < sz(topoSortOrder); i++) {
		cout << topoSortOrder[i] << " ";
	}
   
  return 0;
}
