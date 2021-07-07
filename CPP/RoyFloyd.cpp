#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int kNmax = 105;

class RoyFloyd {
 public:
	void solve() {
		read_input();
		compute();
		print_output();
	}

 private:
	int n;
	int d[kNmax][kNmax];
	int a[kNmax][kNmax];

	void read_input() {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
	}

	void compute() {
		/*
			RoyFloyd algorithm
		*/
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = a[i][j];
				if (d[i][j] == 0) {
					d[i][j] = INT16_MAX;
				}
			}
			d[i][i] = 0;
		}

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] == INT16_MAX) {
					d[i][j] = 0;
				}
			}
		}

	}

	void print_output() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << d[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};

int main() {
	RoyFloyd *sol = new RoyFloyd();
	sol->solve();
	delete sol;
	return 0;
}
