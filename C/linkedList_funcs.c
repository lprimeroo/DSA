//git username->DravitLochan

#include<stdio.h>
#include<stdlib.h>
/*
	In this cpp file, all the basic functions of a linked list have been implemented.
	make a call according to your needs.
	
	cheers!
*/
struct node{
	int data;
	struct node *next;
}*head,*ptr,*t,*temp;


struct node *init()
{
	return (struct node *)(malloc(sizeof(struct node)));
}

struct node *create_node()
{
	return (struct node *)(malloc(sizeof(struct node)));
}


//to push a node in a LL

void push(struct node *t,int n)
{
	while(t->next!=NULL)
	{
		t=t->next;
	}
	struct node *ptr=create_node();
	ptr->data=n;
	ptr->next=NULL;
	t->next=ptr;
}


//print a list

print_list(struct node *t)
{
	printf("the final list is \n\n\t");
	t=t->next;
	while(t!=NULL)
	{
		printf("%d->",t->data);
		t=t->next;
	}
		printf("NULL\n");
}

int count(struct node *t)		//counts and returns the number of nodes in the linked list
{
	int ctr=0;
	t=t->next;
	while(t!=NULL)
	{
		++ctr;
		t=t->next;
	}
	return ctr;
}

//deletes the first element from the list

struct node * del_first(struct node *t)
{
	t=t->next->next;
	return t;
}


//deletes the last element from the list

int del_last(struct node *t)
{
	
	t=t->next;
	if(t->next->next==NULL)
	{
		t=NULL;
		printf("The only node in the list deleted successfully\n");
		return 0;
	}
	while(t->next->next!=NULL)
	{
		t=t->next;
	}
	free(t->next);
	printf("The last node in the list deleted successfully\n");
	return 0;
}

//prints the linked list in the reverse order(using recursive calls).
void print_reverse(struct node *t)
{
	if(t->next!=NULL)
	print_reverse(t->next);
	
	printf("%d->",t->data);
}
//sorts a given list
void sort_list(struct node *head)
{
	struct node *t=(struct node *)malloc(sizeof(struct node));
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	int tempint;
	t=head->next;
	while(t!=NULL)
	{
		temp=t->next;
		while(temp!=NULL)
		{
			if(t->data>temp->data)
			{
				tempint=t->data;
				t->data=temp->data;
				temp->data=tempint;
			}
			temp=temp->next;
		}
		t=t->next;
	}
	print_list(head);
}

//merges 2 sorted linked lists
struct node* merge_2_lists(struct node *head1,struct node *head2)
{
	struct node *mllhead=init();
	temp=head1->next;
	t=head2->next;
	while(temp!=NULL&&t!=NULL)
	{
		if(temp->data<t->data)
		{
			push(mllhead,temp->data);
			temp=temp->next;
		}
		else if(temp->data>t->data)
		{
			push(mllhead,t->data);
			t=t->next;
		}
		else
		{
			push(mllhead,t->data);
			push(mllhead,temp->data);
			temp=temp->next;
			t=t->next;
		}
	}
	while(t!=NULL)
	{
		push(mllhead,t->data);
		t=t->next;
	}
	while(temp!=NULL)
	{
		push(mllhead,temp->data);
		temp=temp->next;
	}
	printf("\n\n\nThe final merged list is :\n");
	print_list(mllhead);
	return mllhead;
}

/*
	In the main function, only one linked list has been created.
	to use any thing else, make the function calls suitably.
*/

main()									
{
	int ctr,i,n,*freq;
	struct node *head=init();
	printf("\t\t\tWELCOME\n\n\nHead created successfully...!!\n");	//head does not have data value. It just points to the first node containing the data value
	printf("\nEnter the number of nodes in the list : ");
	scanf("%d",&ctr);
	struct node *ptr=create_node();
	head->next=ptr;
	printf("\n\nEnter the data for node 1\n");
	scanf("%d",&(ptr->data));
	ptr->next=NULL;
	--ctr; 
	for(i=0;i<ctr;++i)
	{
		printf("Enter the data for node %d\n",i+2);
		scanf("%d",&n);
		push(head,n);
	}
	print_list(head);
	printf("\n");
}
