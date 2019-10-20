//WAP TO CHECK WHETHER THE LINKED LIST IS CIRCULAR OR NOT

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};


bool isCircular(struct Node *head)
{
    struct Node* temp = head;
	// An empty linked list is circular
	if (head == NULL)
	return true;

	while(temp->next !=NULL)
    {
        if(temp->next==head)
        {
            return true;
        }
//        return (bool)(temp->next==head);
        temp=temp->next;
    }
}

//bool isCircular(struct Node *head)
//{
//
//	// An empty linked list is circular
//	if (head == NULL)
//	return true;
//
//    for(  struct Node* temp = head ; temp->next!=NULL && temp->next!=head ; temp = temp->next )
//    {
//            return (bool) (temp == head);
//    }
//}

//	// Next of head
//	struct Node *node = head->next;
//
//	// This loop would stop in both cases (1) If
//	// Circular (2) Not circular
//	while (node != NULL && node != head)
//	node = node->next;
//
//	// If loop stopped because of circular
//	// condition
//	return (node == head);
//}

// Utility function to create a new node.
struct Node *newNode(int data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

//	printf("%s" , isCircular(head));

	// Making linked list circular
	head->next->next->next->next = head;

	isCircular(head)? printf("Yes\n") :	printf("No\n") ;

	return 0;
}
