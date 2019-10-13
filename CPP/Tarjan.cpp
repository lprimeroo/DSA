#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int kNmax = 100005;

class Tarjan {
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

    void tarjan(int v, vector<bool>& viz, vector<int>& idx, \
                vector<int>& lowlink, int& index, vector<int>& s,\
                 vector<vector<int>>& sol) {
        
        idx[v] = index;
        lowlink[v] = index;
        index++;
        s.push_back(v);
        viz[v] = true;
        
        vector<int>::iterator it;
		for (it = adj[v].begin(); it != adj[v].end(); it++) {
            printf("idx for node %d: %d\n", *it, idx[*it]);
            
            if (!idx[*it]) {
                tarjan(*it, viz, idx, lowlink, index, s, sol);
                lowlink[v] = min(lowlink[v], lowlink[*it]);
            } else {
                if (viz[*it] == true) {
                    lowlink[v] = min(lowlink[v], idx[*it]);
                }
            }
		}
        
        std::vector<int> strong_connected;
        if (lowlink[v] == idx[v]) {
            int u;
            do {
                u = s.back();
                s.pop_back();
                viz[u] = false;
                strong_connected.push_back(u);
            } while (u != v);
            sol.push_back(strong_connected);
        }
    }

    void ctc_tarjan(vector<vector<int>>& sol) {
        int index = 1;
        
        vector<int> s;
        vector<int> idx(n + 1);
		vector<int> lowlink(n + 1);
		vector<bool> viz(n + 1);
        for (int i = 1; i <= n; i++) {
            if (idx[i] == 0) {
                tarjan(i, viz, idx, lowlink, index, s, sol);
            }
        }
    }

	vector<vector<int>> get_result() {
		/*
		Strongly connected components using Tarjan
		*/
		vector<vector<int>> sol;
        ctc_tarjan(sol);
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

	Tarjan *tarjan = new Tarjan();
	tarjan->solve();
	delete tarjan;
	return 0;
}