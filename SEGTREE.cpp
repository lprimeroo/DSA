#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <map>
#include <climits>
#include <set>
using namespace std;

struct node {
	int ans, sum, suf, pref;
	node() {}
};

node tree[200000];
int n;

node make_node(int v) {
	node ret;
	
	ret.ans = ret.sum = ret.suf = ret.pref = v;
	
	return ret;
}

node combineSegments(node left, node right) {
	node ret;
	
	ret.sum = left.sum+right.sum;
	ret.pref = max(left.pref, left.sum+right.pref); // prefix sum max in left child or right child
	ret.suf = max(right.suf, right.sum+left.suf); // max suffix sum
	ret.ans = max(max(left.ans, right.ans), left.suf+right.pref); //max subvector sum
	//as max subvector sum can be in both , right or left .
	return ret;
}

void buildTree(int a[], int x, int l, int r) {
	if(l == r)
		tree[x] = make_node(a[l]);
	else {
		int mid = (l+r)/2;
		buildTree(a, x*2, l, mid);
		buildTree(a, x*2+1, mid+1, r);
		tree[x] = combineSegments(tree[x*2], tree[x*2+1]);
	}
}

node queryTree(int x, int a, int b, int i, int j) {
	int mid = (a+b)/2;
	
	if(a >= i && b <= j) return tree[x];
	
	if(j <= mid) return queryTree(x*2, a, mid, i, j);
	else if(i > mid) return queryTree(x*2+1, mid+1, b, i, j);
	
	node left = queryTree(x*2, a, mid, i, mid);
	node right = queryTree(x*2+1, mid+1, b, mid+1, j);
	
	return combineSegments(left, right);
}

int main() {
	
	scanf("%d", &n);
	
	int nums[n+1];
	for(int i = 1; i <= n; i++) scanf("%d", &nums[i]);

	buildTree(nums, 1, 1, n);
	
	int m, x, y;
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", queryTree(1, 1, n, x, y).ans);
	}
	
	return 0;
}