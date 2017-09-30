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
int lazy[100] ; //0 for updated, !=0 for to be updated

void buildTree(int top, int l, int r) {
	if(l>r)
		return;
	if(l==r) {
		tree[top] = a[l] ;
		return ;
	}
		buildTree(top*2+1,l,(l+r)/2) ;
		buildTree(top*2+2,(l+r)/2+1,r) ;
		tree[top] = max(tree[top*2+1], tree[top*2+2]) ;

}

void updateTree(int l, int r, int i, int j, int top, int value) {
	if (l>j || r<i) return ;  //do not forget this 

	if(lazy[top]!=0) {
		tree[top] += lazy[top] ;

		if(l!=r){
			lazy[2*top+1] += lazy[top] ;
			lazy[2*top+2] += lazy[top] ;
		}
		lazy[top] = 0 ;
	}

	if(l>=i && r<=j){
		tree[top] += value ;

		if(l!=r){
			lazy[2*top+1] += value ;
			lazy[2*top+2] += value ;
		}
		return;
	}

	updateTree(l,(l+r)/2,i,j,top*2+1,value) ;
	updateTree((l+r)/2+1,r,i,j,top*2+2,value) ;

	tree[top] = max(tree[top*2+1],tree[top*2+2]) ;

}

int queryTree(int top, int l, int r, int i, int j) {
	if(i>r&&j<l) {
		return MAXN ;
	}

	if(lazy[top]!=0){  //checking whether something needs to be updated
		tree[top] += lazy[top] ;

		if(l!=r) {
			lazy[2*top+1] += lazy[top] ;
			lazy[2*top+2] += lazy[top] ;
                              
		}
		lazy[top] = 0 ;
	}

	if(i<=l&&j>=r) {
		return tree[top] ;
	}
	
	int mid = (l+r)/2 ;
	return (max(queryTree(top*2+1,l,mid,i,j),queryTree(top*2+2,mid+1,r,i,j))) ;
}

int main(int argc, char const *argv[]) {
	for(int i =0;i<20;i++)
		a[i] = 1 ;

	buildTree(0,0,19) ;
	memset(lazy,0,sizeof(lazy)) ;
	updateTree(0, 19, 0, 6,0, 5) ; 
	updateTree(0, 19,7, 10, 0, 12) ; 
	updateTree(0,19, 10, 19,0, 100) ; 

	cout << queryTree(0, 0, 19, 0, 19) << endl; 
	return 0;
}
