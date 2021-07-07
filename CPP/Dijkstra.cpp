#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
using namespace std;

const int kNmax = 50005;

class Dijkstra {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	int source;
	vector<pair<int, int> > adj[kNmax];

	void read_input() {
		cin >> n >> m >> source;
		for (int i = 1, x, y, w; i <= m; i++) {
			cin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
		}
	}


	vector<int> get_result() {
		/*
			Dijkstra on oriented graph
		*/
		vector<int> d(n + 1, (1 << 30));
		vector<bool> s(n + 1, false);
		vector<int> p(n + 1, -1);
		priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q; 
		
		d[source] = 0;
		q.push(make_pair(d[source], source));

		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
			if (s[u] == true) {
				continue;
			}
			s[u] = true;
			for (auto node : adj[u]) {
				if (!s[node.first] && d[node.first] > (d[u] + node.second) ) {
					d[node.first] = d[u] + node.second;
					p[node.first] = u;
					q.push({d[node.first], node.first});
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (d[i] == (1 << 30)) {
				d[i] = -1;
			}
		}
		
		return d;
	}

	void print_output(vector<int> result) {
		for (int i = 1; i <= n; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
};

int main() {
	Dijkstra *dijkstra = new Dijkstra();
	dijkstra->solve();
	delete dijkstra;
	return 0;
}
