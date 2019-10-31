#include <algorithm>
#include <iostream>

#define INF 100000000

using namespace std;

typedef struct edge {
	int u, v, w;
} edge;

vector<edge> edges;
vector<int> dis;
bool has_negative_cycle;
int n_nodes;

void bellmanford(int src) {
	dis[src] = 0;
	has_negative_cycle = false;
	edge e;
	for(int i = 1;i < n_nodes;i++) {
		for(vector<edge>::iterator it = edges.begin();it != edges.end();it++) {
			e = *it;
			if(dis[e.u] != INF) {
				dis[e.v] = min(dis[e.u] + e.w, dis[e.v]);
			}
		}
	}
	// detect negative cycle
	for(vector<edge>::iterator it = edges.begin();it != edges.end() && !has_negative_cycle;it++) {
		e = *it;
		if(dis[e.u] != INF && dis[e.u] + e.w < dis[e.v]) {
			has_negative_cycle = true;
		}
	}
}

int main(int argc, char const *argv[]) {
	int n_edges, u, v, w;
	cin >> n_nodes;
	dis.assign(n_nodes, INF);
	cin >> n_edges;
	while(n_edges--) {
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	// input source node
	cin >> u;
	bellmanford(u);
	if(has_negative_cycle) {
		cout << "Negative cycle detected" << endl;
	}
	else {
		cout << "No negative cycle detected" << endl;
		for(int i = 0;i < n_nodes;i++) {
			cout << i << ": " << dis[i] << endl;
		}
	}

	return 0;
}
