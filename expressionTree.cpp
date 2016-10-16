/*
	expression binary tree is an extension of binary tree which can be used
	for various cool purposes like encryption of data and storing it.
	
	
*/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#define max 100
using namespace std;

 struct t_node{
	char value;
	t_node *left,*right;
};


class exp_t{
	t_node *root;
	
	public:
	exp_t(t_node *h): root(h){ }
	t_node* get_root()
	{
		return root;
	}
	void put_root(t_node *p)
	{
		root=p;
	}
	
	void inOrder(t_node *r)
	{
		if(r->left)
		inOrder(r->left);
		cout<<r->value;
		if(r->right)
		inOrder(r->right);
	}
	
	void preOrder(t_node *r)
	{
		cout<<r->value;
		if(r->left)
		preOrder(r->left);
		if(r->right)
		preOrder(r->right);
	}
	
	t_node* create_n(char v)				//creates a node for the tree and returns it after initalizing the default values.
	{
		t_node *n= new t_node;
		n->left=NULL;
		n->right=NULL;
		n->value=v;
		return n;
	}
	
	t_node* create_t(string ex)					//on receiving an expression, creates the tree and returns the root pointer.
	{
		t_node *stack[max];						
		int top = -1;

		int i,len=ex.length();
		for(i=0;i<len;++i)
		{
			//cout<<ex[i];
			t_node *ptr=create_n(ex[i]);
			if(isdigit(ex[i]))							//if a digit(operand) is found push the node created in the stack
			{
				if(top<max-1)
				stack[++top]=ptr;
				else
				cout<<"overflow\n\t\tExiting!";
			}
			else									//as soon as an operator(sign) is found, store and remove the top 2 elements(if  possible)
			{										// and attach them as the leaf nodes for the encountered operator. now push the operator node in
				if(top>0)							//the stack. at the end, only one node will be left and that will be our root for the expression binary tree	
				{
					t_node *t1=stack[top--];
					t_node *t2=stack[top--];
					ptr->right=t1;
					ptr->left=t2;
					stack[++top]=ptr;
				}
			}
		}
		return stack[0];
	}
};


int main()
{
	string exp;
	t_node *head=new t_node;
	head->left=NULL;
	head->right=NULL;
	exp_t tree(head);
	//cout<<"Enter the post fix expression\n";
	//cin>>exp;
	exp="12+34/*";
	tree.put_root(tree.create_t(exp));
	cout<<"the inorder traversal is: \n";
	tree.inOrder(tree.get_root());
	cout<<"\n";
	cout<<"the preorder traversal is: \n";
	tree.preOrder(tree.get_root());
	cout<<"\n";
	return 0;
}
