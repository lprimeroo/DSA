#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<bits/stc++.h>
using namespace std;

//defining queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

//to check if queue is full or not
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

//to check if queue is empty or not
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }

//To return front element of the queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

//To return rear element of the queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

//To add element to the queue
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

//To remove element from queue
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}


int main()
{
	cout<<"Enter size of stack:";
	int n,tmp;
	cin>>n;
	
	struct Queue* queue = createQueue(1000);
	
	cout<<"Enter elements of stack:";
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		enqueue(queue,tmp);
	}
	
		
	return 0;
}
