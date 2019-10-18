//ALL BASIC LINKED LIST OPERATIONS

/*

1. BUBBLE SORT
2. COUNTING NODES
3. CHECKING IF IT IS CIRCULAR
4. PUSHING: A - BEGINNING
                          B -  AFTER NODE
                          C -  BEFORE NODE

*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* previous;
};


void push(struct Node **head_ref , int item)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->previous = NULL;
    new_node ->next = (*head_ref);
    if(  (*head_ref) !=NULL )
    {
        (*head_ref)->previous = new_node;
    }

    (*head_ref) = new_node;

}

void push_after_node(struct Node *prev_node  ,  int item)
{
    struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
     if(prev_node==NULL)
     {
        printf("PREVIOUS NODE CANNOT BE EMPTY");
        return;
     }
    new_node ->previous = prev_node;
    new_node ->data = item;
    new_node ->next = prev_node ->next;
    prev_node ->next = new_node;
    if(new_node->next != NULL )
        new_node->next->previous = new_node;
}


void push_before_node(struct Node** head_ref , struct Node *next_node  ,  int item)
{
    if(next_node==NULL)
    {
        printf("NEXT NODE CANNOT BE EMPTY");
        return;
    }


    struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));

    new_node ->previous = next_node ->previous;
    new_node ->next = next_node;
    if(new_node ->previous!=NULL)
        new_node ->previous->next = new_node;
    else
        (*head_ref) = new_node;
}

void push_last(struct Node** head_ref , int item)
{
    struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));

    struct Node* last= (*head_ref);

    new_node->data= item;
    new_node->next = NULL;

    if((*head_ref) == NULL)
    {
        new_node->previous = NULL;
        (*head_ref) = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last ->next;
    }

    last->next = new_node;
    new_node->previous = last;
}

void printList(struct Node* node )
{
    struct Node* last;
    printf("PRINTING IN FORWARD DIRECTION: \n");
    while(node!=NULL)
    {
        printf("%2d" , node->data);
        last = node;
        node = node->next;
    }

     printf("\nPRINTING IN BACKWARD DIRECTION: \n");
     while(last!=NULL)
    {
        printf("%2d" , last->data);
        last = last->previous;
    }

}

/* Bubble sort the given linked list */
void sort(struct Node* head)
{
    int swapped ;
    struct Node* ptr ;
    struct Node* lptr = NULL;

    if(head == NULL)
        return ;

    do
    {
        swapped = 0;
        ptr = head;

        while(ptr->next!=lptr)
        {
            if(ptr->data >ptr->next->data)
            {
                swap(ptr , ptr->next);
                swapped = 1;
            }
            ptr = ptr ->next;
        }
        lptr = ptr;
    }
    while(swapped);
}

void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

//CHECKING IF IT IS CIRCULAR

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

int main()
{
    /* Start with the empty list */
   struct Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    push_last(&head, 6);

    // Insert 7 at the beginning. So
    // linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning. So
    // linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So linked
    // list becomes 1->7->6->4->NULL
    push_last(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    push_after_node(head->next, 8);

   printList(head);

   sort(head);

   printf("\n\nAfter Sorting: \n");
   printList(head);

    printf("\n\nIS IT CIRCULAR? : ");
    isCircular(head)? printf("Yes\n") :	printf("No\n") ;

    return 0;
}



