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

void make_set(int v, int parent[], int Size[]) {
    parent[v] = v;
    Size[v] = 1;
}
int find_set(int v, int parent[]) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}
void union_sets(int a, int b, int parent[], int Size[]) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main() {
	int n, m;
	cout << "Enter number of vertices and edges in the graph respectively\n";
	cin >> n >> m;
	int parent[n], Size[n];
	for(int i = 1; i <= n; i++){
		make_set(i, parent, Size);
	}
	cout << "Enter edges: \n";
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		union_sets(u, v, parent, Size);
	}
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(parent[i] == i) {
			count++;
		}
	}
	cout << "Number of connected components = " << count << "\n";
}

