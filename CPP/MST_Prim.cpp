#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <tuple>
#include <queue>
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
	vector<pair<int, int> > adj[kNmax];

	void read_input() {
		cin >> n >> m;
		for (int i = 1, x, y, w; i <= m; i++) {
			cin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
			adj[y].push_back(make_pair(x, w));
		}
	}

	int get_result() {
		/*
		MST using Prim
		*/
		int cost = 0;
		bool viz[kNmax] = {0};
		viz[1] = 1;
		priority_queue<int, vector<pair<int, int>>, std::greater<pair<int, int>>> q;
		for (auto &x : adj[1]) {
			q.push(make_pair(x.second, x.first));
		}

		int visitednodes = 1;
		int done = 0;
		do {
			pair<int, int> top = q.top();
			q.pop();
			if (viz[top.second] == 0) {
				viz[top.second] = 1;
				visitednodes++;
				cost += top.first;
				for (auto &x : adj[top.second]) {
					if (viz[x.first] == 0) {
						q.push({x.second, x.first});
					}
				}
			}
		} while (visitednodes < n);
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
