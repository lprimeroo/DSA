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