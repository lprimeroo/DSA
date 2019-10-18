#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int a[] , int size)
{
    for(int i = 0 ; i< size ; i++)
    {
        int j = i+1;
        while( j <= 0 &&  a[j-1]>a[j])
        {
            int key = a[j];
            a[j] = a[j-1];
            a[j-1] = key;
            j--;
        }
    }
}

void print(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {3,1,4,2,5};
    int size= 5;

    print(arr , size);
    insertion_sort(arr , size);
    print(arr , size);
}

