#include<stdio.h>
#include<stdlib.h>

typedef struct binarysearchtree
{
	int value;
	struct binarysearchtree *left;
	struct binarysearchtree *right; 
}bst;

bst *insert(bst *root, int val)
{
	if(root == NULL)
	{
		root = (bst*)malloc(sizeof(bst));
		root->value = val;
		root->left = NULL;
		root->right = NULL;
	}
	else if(val > root->value)
	{	
		root->right = insert(root->right, val);
	}
	else
	{	
		root->left = insert(root->left, val);
	}
	return root;
}

bst *minValue(bst *node)
{
    bst *current = node;
    while(current->left != NULL)
	{
        current = current->left;
	}
    return current;
}

bst* delete(bst* root, int value)
{
    if(root == NULL)
	{
		return root;
	}
    if(value < root->value)
	{
        root->left = delete(root->left, value);
	}
    else if(value > root->value)
	{
        root->right = delete(root->right, value);
	}
    else
    {
        if (root->left == NULL)
        {
            bst* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            bst *temp = root->left;
            free(root);
            return temp;
        }
        bst *temp = minValue(root->right);
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }
    return root;
}

void printinorder(bst *root)
{
	if(root == NULL)
	{
		return;
	}
	printinorder(root->left);
	printf("%d ", root->value);
	printinorder(root->right);
}

void printpreorder(bst *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d ", root->value);
	printpreorder(root->left);
	printpreorder(root->right);
}

void printpostorder(bst *root)
{
	if(root == NULL)
	{
		return;
	}
	printpostorder(root->left);
	printpostorder(root->right);
	printf("%d ", root->value);
}

int main()
{
	int n, k, i, x;
	bst *root;
	root = (bst *)malloc(sizeof(bst));
	root = NULL;
	scanf("%d", &n);
	for(i=0 ;i < n; i++)
	{	
		scanf("%d", &x);
		root = insert(root, x);
	}
	printinorder(root);
	printf("\n");
	int del;
	scanf("%d", &del);
	delete(root, del);
	printinorder(root);
	printf("\n");
	//printpreorder(root);
	//printf("\n");
	//printpostorder(root);
	//printf("\n");
	return 0;	
}
