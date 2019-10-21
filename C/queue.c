A queue is a useful data structure in programming. It is similar to the ticket queue outside a cinema hall, where the first person entering the queue is the first person who gets the ticket.
Queue follows the First In First Out(FIFO) rule - the item that goes in first is the item that comes out first too.
	
Queue Specifications-

A queue is an object or more specifically an abstract data structure(ADT) that allows the following operations:

    Enqueue: Add element to end of queue
    Dequeue: Remove element from front of queue
    IsEmpty: Check if queue is empty
    IsFull: Check if queue is full
    Peek: Get the value of the front of queue without removing it
   
How Queue Works-

Queue operations work as follows:

    Two pointers called FRONT and REAR are used to keep track of the first and last elements in the queue.
    When initializing the queue, we set the value of FRONT and REAR to -1.
    On enqueing an element, we increase the value of REAR index and place the new element in the position pointed to by REAR.
    On dequeueing an element, we return the value pointed to by FRONT and increase the FRONT index.
    Before enqueing, we check if queue is already full.
    Before dequeuing, we check if queue is already empty.
    When enqueing the first element, we set the value of FRONT to 0.
    When dequeing the last element, we reset the values of FRONT and REAR to -1.
	    
Here the codes for implementation of queue in C language- 


	
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *prev;
	struct node *next;
}node;

node *head, *tail;

void push(int value) {
    if (head == NULL) {  // if queue is empty, set head node and set head.prev to head to indicate existence of one item
        head = malloc(sizeof(node));
        head->value = value;
    }
    else if (tail == NULL) {  // if head.prev == head, one item exists
        tail = malloc(sizeof(node));
        head->next = tail;
        tail->value = value;
        tail->prev = head;
    }
    else {
        tail->next = malloc(sizeof(node));
        tail->next->value = value;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

int pop() {
    if (head == NULL) {  // return -1 if trying to pop an empty list
        return -1;
    }
    node *temp_addr = head->next;
    int result = head->value;
    free(head);
    if (temp_addr == NULL) {
        head = NULL;
        tail = NULL;
        return result;
    }
    head = temp_addr;
    head->prev = NULL;
    return result;
}

int length() {
    if (head == NULL) {
        return 0;
    }
    node *current = head;
    int i = 1;
    while (current->next != NULL) {
        i++;
        current = current->next;
    }
    return i;
}

int main() {
    push(1);
    push(2);
    push(3);
    printf("%d\n", length());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", length());
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
}
