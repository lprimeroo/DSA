#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
// A structure to represent a stack
struct StackNode
{
    int data;
    struct StackNode* next;
};
 
struct StackNode* newNode(int data)
{
    struct StackNode* stackNode =
              (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

//To check if stack is empty 
int isEmpty(struct StackNode *root)
{
    return !root;
}
 
//Adding element to stack
void push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}
 
//Deleting element from stack
int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}
 
//Viewing topmost element
int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
 
int main()
{
    
 
	cout<<"Enter size of stack:";
	int n,tmp;
	cin>>n;
	
	//Creation of stack
	struct StackNode* root = NULL;	
	
	cout<<"Enter elements of stack:";
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		push(&root,tmp);
	}
	
    	printf("%d popped from stack\n", pop(&root));

    	printf("Top element is %d\n", peek(root));
 
    return 0;
}
