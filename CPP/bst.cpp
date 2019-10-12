#include <iostream>

using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

struct node *newN(int k) {
	node* aux = new node;
	aux->key = k;
	aux->left = NULL;
	aux->right = NULL;
	return aux;
}

struct node* insert(struct node* node, int k) {
	if (node == NULL || k == node->key) {
		return newN(k);
	}
	if (k < node->key) {
		node->left = insert(node->left, k);
	} else if (k > node->key) {
		node->right = insert(node->right, k);
	}

	return node;
}

void print(struct node* root) {
	if (root != NULL) {
		print(root->left);
		cout << root->key << " ";
		print(root->right);
	}
}

int main() {
	struct node *root = NULL;
	int n, k;

	cout << "Dati numarul de noduri:";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		if (root == NULL) {
			root = insert(root, k);
		} else {
			insert(root, k);
		}
	}

	print(root);


	return 0;
}
