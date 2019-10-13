#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
using namespace std;

const int kNmax = 2e5 + 10;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<tuple<int, int, int> > edges;
	vector<int> parent, size;

	void read_input() {
		cin >> n >> m;
		for (int i = 1, x, y, w; i <= m; i++) {
			cin >> x >> y >> w;
			edges.push_back(make_tuple(w, x, y));
		}
		parent.resize(n + 1);
		size.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int find_root(int node) {
		if (node == parent[node]) {
			return node;
		}
		return parent[node] = find_root(parent[node]);
	}

	void merge_forests(int root1, int root2) {
		if (size[root1] <= size[root2]) {
			size[root2] += size[root1];
			parent[root1] = root2;
		} else {
			size[root1] += size[root2];
			parent[root2] = root1;
		}
	}

	int get_result() {
		/*
			MST using Kruskall
		*/ 
		int cost = 0;
		sort(edges.begin(), edges.end());
		for (auto it = edges.begin(); it != edges.end(); it++) {
			if( find_root( get<1>(*it)) != find_root( get<2>(*it))) {
				cost += get<0>(*it);
				merge_forests(find_root( get<1>(*it)), find_root( get<2>(*it)));
			}
		}
		return cost;
	}

	void print_output(int result) {
		cout << result << "\n";
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
