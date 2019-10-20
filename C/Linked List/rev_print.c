/*
 * Recursive C program to reverse nodes of a linked list and display
 * them
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} ;

struct node *head;

//Recursive Reverse
void print_reverse_recursive (struct node *head)
{
    if (head == NULL)
          return;

    print_reverse_recursive (head -> next);

    printf ("%d ", head -> data);

}

//Print the linkedlist normal
void print (struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    printf ("%d ", head -> data);
    print (head -> next);
}

//New data added in the start
void insert_new_node (struct node ** head_ref, int new_data)
{
    struct node * new_node = (struct node *) malloc (sizeof (struct node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}


int main ()
{

    struct node* temp;
    insert_new_node (&head, 1);
    insert_new_node (&head, 2);
    insert_new_node (&head, 3);
    insert_new_node (&head, 4);
    printf ("LinkedList : ");
    print (head);
    printf ("\nLinkedList in reverse order : ");


    print_reverse_recursive (head);


    printf ("\n");
    return 0;
}


















