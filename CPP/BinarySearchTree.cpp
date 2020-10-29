#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node *newNode(int data){
	 node *n = new node;
	 n->data = data;
	 n->left = n->right = NULL;
	 return n;
}

void printInorder(node *root){
	 if(root == NULL)
	     return;
	 printInorder(root->left);
	 cout<<root->data<<" ";
	 printInorder(root->right);
}

void insert(node **root, int data){
     if(*root == NULL)
 		  *root = newNode(data);
    else{
		 if((*root)->data > data){
		     insert(&(*root)->left, data);		  	 
   		 }
   		 else
   		 	 insert(&(*root)->right, data);
    }
}
node *deleteNode(node *root, int key){
	if(root == NULL)
		return NULL;
	if(key < root->data){
		root->left = deleteNode(root->left, key);
	}
	else if(key > root->data){
		root->right = deleteNode(root->right, key);
	}
	else {
		if(root->left == NULL){
			node *res = root->right;
			delete(root);
			return res;
		}
		else if(root->right == NULL){
			node *res = root->left;
			delete(root);
			return res;
		}
		else {
			node *ptr = root->right;
			while(ptr->left){
				ptr = ptr->left;
			}
			root->data = ptr->data;
			root->right = deleteNode(root->right, ptr->data);
		}
	}
	return root;
}

int main(){
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
  
    // print inoder traversal of the BST
    printInorder(root);
    getchar();
}
