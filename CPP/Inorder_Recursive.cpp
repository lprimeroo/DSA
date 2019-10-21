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
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
}

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
}

int main() {
	TreeNode* root = new TreeNode(5);
	TreeNode* nd1 = new TreeNode(6);
	TreeNode* nd2 = new TreeNode(3);
	root -> left = nd2;
	root -> right = nd1;
	TreeNode* nd3 = new TreeNode(2);
	TreeNode* nd4 = new TreeNode(4);
	nd2 -> left = nd3;
	nd2 -> right = nd4;
	TreeNode* nd5 = new TreeNode(1);
	nd3 -> left = nd5;
	vector<int> in = inorderTraversal(root);
	cout << "Inorder traversal: ";
	for(int i = 0; i < in.size(); i++) {
		cout << in[i] << " ";
	}
	return 0;
}
