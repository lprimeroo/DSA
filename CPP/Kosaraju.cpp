#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
using namespace std;

const int kNmax = 100005;

class Kosaraju {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<int> adj[kNmax];
	vector<int> adjt[kNmax];

	void read_input() {
		cin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adjt[y].push_back(x);
		}
	}

	/* 0 white, 1 grey, 2 black */
	void dfs(int v, vector<int> &color, vector<int> &s) {
		color[v] = 1;
		vector<int>::iterator it;
		for (it = adj[v].begin(); it != adj[v].end(); it++) {
			if (color[*it] == 0) {
				dfs(*it, color, s);
			}
		}
		s.push_back(v);
		color[v] = 2;
	}

	void dfsT(int v, vector<int> &color, vector<int> &strong_connected) {
		strong_connected.push_back(v);
		color[v] = 1;
		vector<int>::iterator it;
		for (it = adjt[v].begin(); it != adjt[v].end(); it++) {
			if (color[*it] == 0) {
				dfsT(*it, color, strong_connected);
			}
		}
		color[v] = 2;
	}

	void ctc(vector<vector<int>> &sol) {
		vector<int> s;
		std::vector<int> color(n + 1);
		for (int i = 1; i <= n; i++) {
			color[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int ok = 0;
			if (color[i] == 0) {
				dfs(i, color, s);
			}
		}

		for (int i = 1; i <= n; i++) {
			color[i] = 0;
		}

		while (!s.empty()) {
			int v = s.back();
			s.pop_back();
			vector<int> strong_connected;
			if (color[v] == 0) {
				dfsT (v, color, strong_connected);
				sol.push_back(strong_connected);
			}
		}
	}

	vector<vector<int>> get_result() {
		/* Strongly connected components using Kosaraju */
		vector<vector<int>> sol;
		ctc(sol);
		return sol;
	}

	void print_output(vector<vector<int>> result) {
		cout << result.size() << '\n';
		for (const auto& ctc : result) {
			for (int nod : ctc) {
				cout << nod << ' ';
			}
			cout << '\n';
		}
	}
};

int main() {
	Kosaraju *kosaraju = new Kosaraju();
	kosaraju->solve();
	delete kosaraju;
	return 0;
}

