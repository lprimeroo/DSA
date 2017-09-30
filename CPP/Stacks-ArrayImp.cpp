#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
struct Stack
{
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
//To check if stack is full or not
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }
//To check if stack is empty or not
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }
//For adding new element
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
//For deleting the topmost element 
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
//To view topmost element
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

int main()
{
	cout<<"Enter size of stack:";
	int n,tmp;
	cin>>n;
	
	//Creation of stack
	struct Stack* stack = createStack(n);	
	
	cout<<"Enter elements of stack:";
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		push(stack,tmp);
	}
	
	//Deleting topmost element
	printf("%d popped from stack\n", pop(stack));
 
 	//Viewing topmost element
 	printf("Top item is %d\n", peek(stack));
 
	return 0;
}
