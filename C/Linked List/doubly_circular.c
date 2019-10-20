//ALL OPERATIONS IN DOUBLY CIRCULAR LINKED LIST

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    int key;

    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int key , int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->key= key;
    return new_node;
}

bool isEmpty(struct Node* head)
{
    return (bool) head == NULL;
}

int length(struct Node* head)
{
    int length = 0;
    struct Node* current;

    if(!head)
        return length;

    for(current = head ; current->next!=head ; current = current->next)
    {
            length++;
    }
    return length;
}


int main()
{
    struct Node* head = createNode(10,20);
    head->next = createNode(20,30);
    head->next->next = head;

    printf("%d" , length(head));


}
