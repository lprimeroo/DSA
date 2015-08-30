//saru95
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
#define MAXN 100000
 
using namespace std;
 
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::pair<int, int> pii;
typedef std::set<int> si;
typedef std::map<std::string, int> msi;

int tree[100] ;
int a[20] ;

void buildTree(int top, int l, int r) {
	if(l==r)
		tree[top] = a[l] ;
	else {
		int mid = (l + r) / 2 ;
		buildTree(top*2+1,l,mid) ;
		buildTree(top*2+2 ,mid+1,r) ;
		tree[top] = max(tree[top*2+1],tree[top*2+2]) ;
	}
}

int rangeMaxQuery(int qlow, int qhigh, int l, int r, int top) {
	if(qlow<=l && qhigh>=r)
		return tree[top] ;
	if(qlow>r || qhigh<l)
		return MAXN ;
	int mid = (l + r) / 2 ;
	return (max(rangeMaxQuery(qlow, qhigh,l,mid,2*top+1),rangeMaxQuery(qlow, qhigh,mid+1,r,2*top+2))) ;
	
}

void updateTree(int l,int r, int qlow, int qhigh, int top, int value) {
	if(l > r || l >qhigh || r < qlow) {
		return;
	}
	if(l==r){
		tree[top] += value ;
		return ;
	}
	updateTree(l,(l+r)/2,qlow,qhigh,top*2+1,value) ;
	updateTree((l+r)/2+1,r,qlow,qhigh,top*2+2,value) ;
	tree[top] = max(tree[top*2+1],tree[top*2+2]) ;
}

int main(int argc, char const *argv[]) {
	for(int i =0;i<20;i++)
		a[i] = 1 ;
	buildTree(0,0,19) ;
	updateTree(0, 19, 0, 6,0, 5) ; 
	updateTree(0, 19,7, 10, 0, 12) ; 
	updateTree(0,19, 10, 19,0, 100) ; 

	cout << rangeMaxQuery(0, 19, 0, 19, 0) << endl; 
	return 0;
}