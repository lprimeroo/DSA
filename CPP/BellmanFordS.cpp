#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

const int kNmax = 50005;

class BellmanFord {
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
			BellmanFord algorithm
		*/

		vector<int> d(n + 1, (1 << 30));
		vector<bool> s(n + 1, false);
		vector<int> p(n + 1, -1);

		d[source] = 0;

		for (int i = 1; i <= n - 2; ++i) {
			for (int j = 1; j <= n; j++) {
				for (auto node : adj[j]) {
					if (d[node.first] > d[j] + node.second) {
						d[node.first] = d[j] + node.second;
						p[node.first] = j;
					}
				}
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (auto node : adj[i]) {
				if (d[node.first] > d[i] + node.second) {
					return vector<int>();
				}
			}
		}
		return d;
	}

	void print_output(vector<int> result) {
		if (result.size() == 0) {
			cout << "Negative cycle!\n";
		} else {
			for (int i = 1; i <= n; i++) {
				cout << result[i] << ' ';
			}
			cout << '\n';
		}
	}
};

int main() {
	BellmanFord *sol = new BellmanFord();
	sol->solve();
	delete sol;
	return 0;
}
