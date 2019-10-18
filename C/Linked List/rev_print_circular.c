//REVERSE PRINT CIRCULAR SINGLY LINKED list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next ;
};

struct Node* head;

void insert_at_end()
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(!new_node)
    {
        printf("NO MEMORY ALLOCATED");
        return;
    }

    scanf("%d" , &new_node->data);
    new_node ->next = head ;

    if(!head)
    {
        head = new_node;
        return;
    }

    else
    {
        struct Node* temp;
        for(temp = head ; temp->next!= head ; temp = temp->next);
        temp->next = new_node;
        return;
    }
}

void insert_at_beginning()
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(!new_node)
    {
        printf("NO MEMORY ALLOCATED");
        return;
    }

    scanf("%d" , &new_node->data);

    if(!head)
    {
        new_node->next= head;
        head = new_node;
        return;
    }

    else
    {
        struct Node* temp;
        for(temp = head ; temp->next!= head ; temp = temp->next);
        temp->next = new_node;
        new_node->next= head;
        head = new_node;
        return;
    }
}
void rev_print(struct Node* phead)
{
    if(!head)
        return;
    if(phead->next!=head)
    {
        rev_print(phead->next);
        printf("%d" , phead->data);
    }
}

void print()
{
    struct Node* temp;
     for(temp = head ; temp->next!= head ; temp = temp->next)
     {
         printf("%2d" , temp->data);
     }

//    if(!phead)
//        return;
//    else
//    {
//        printf("%d" , phead->data);
//        print(phead->next);
//        return;
//    }
}

int main()
{
    for(int i =1 ; i<=7 ; i++)
    {
        insert_at_beginning();
    }
    print(head);
    return 0;
}

