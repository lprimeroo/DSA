#include<stdio.h>
#include<stdlib.h>

void selection_sort(int a[] , int n)
{
    for( int i = 0 ; i<n; i++)
    {
        int min = i;
        for( int j = i+1 ; j<n; j++)
        {
            if(a[min]>a[j])
            {
                min = j;
            }
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
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
    int arr[] = { 5, 1, 6 , 2, 4, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    print(arr , size );
    printf("\nAFTER SORTING USING SELECTION SORT: \n");
    selection_sort(arr , size);
    print(arr , size );
    return 0;
}
