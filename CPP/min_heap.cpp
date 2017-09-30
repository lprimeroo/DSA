/*
A binary heap is a complete binary tree which satisfies the heap ordering property. The ordering can be one of two types:

the min-heap property: the value of each node is greater than or equal to the value of its parent, with the minimum-value element at the root.
the max-heap property: the value of each node is less than or equal to the value of its parent, with the maximum-value element at the root.
this specific code and class is for max heap. Max heap is also impleneted in the same way.(code has been added).

In a heap the highest (or lowest) priority element is always stored at the root, hence the name "heap". A heap is not a sorted structure and can 
be regarded as partially ordered. As you see from the picture, there is no particular relationship among nodes on any given level, even among the siblings.

Since a heap is a complete binary tree, it has a smallest possible height - a heap with N nodes always has O(log N) height.

A heap is useful data structure when you need to remove the object with the highest (or lowest) priority. A common use of a heap is to implement a priority queue.
*/
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

class min_h{

    int size,rear;
    int  *m_heap;
    public:
    //constructor
    min_h(int s)
    {
        rear=0;
        size=s+1;
    	m_heap = new int[s+1];
    	*m_heap=0;
    }

    void perculate_up(int child_ind)
    {
    	if(child_ind>1)
        {
			if(*(m_heap+child_ind/2)>*(m_heap+child_ind))
        	{
        	    swap((m_heap+child_ind/2),(m_heap+child_ind));
            	perculate_up(child_ind/2);
        	}
        }
    }

    void insert(int val)
    {
        if(rear<size)
        {
            ++rear;
            *(m_heap+rear) = val;
            perculate_up(rear);
        }
        else
        {
            cout<<"heap is full right now. cannot add more elements\n";
        }
    }

    void print_heap()
    {
        for(int i=1;i<size;++i)
            cout<<*(m_heap+i)<<" ";
    }

};


int main()
{
    //max_h <int> maxheap;
    min_h tree(13);
    tree.insert(35);
    tree.insert(33);
    tree.insert(42);
    tree.insert(10);
    tree.insert(14);
    tree.insert(19);
    tree.insert(27);
    tree.insert(44);
    tree.insert(26);
    tree.insert(31);
    tree.insert(8);
    tree.insert(5);
    tree.insert(50);
    tree.print_heap();
}
