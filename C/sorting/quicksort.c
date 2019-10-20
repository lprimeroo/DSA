//Quick Sort

#include<stdio.h>
#include<stdbool.h>

void swap( double *a  , double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}


int Partition( double arr[] , int start , int end )
{
    double pivot = arr[end];
    int partition_index  = start;

    for(int i = start ; i < end  ;i++)
    {
        if(arr[i] <= pivot)
        {
            swap( &arr[i] , &arr[partition_index]);
            partition_index++;
        }
    }
    swap( &arr[partition_index] , &arr[end]);
    return partition_index;
}

void QuickSort( double arr[] , int start , int end)
{
    if(start<end)
    {
        int PI = Partition(arr, start, end);
        QuickSort( arr , start , PI-1);
        QuickSort( arr , PI+1 , end);
    }

}


void print( double arr[] , int size)
{
    for(int i = 0 ; i< size ; i++)
    {
        printf("%10f" , arr[i]);
    }
    printf("\n");
}


int main()
{
    double arr[] = {4.2,5.7,0.3,0.3,1,3,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    print(arr , size);
//    printf("%f\n" , Partition( arr , 0 , size-1));
    QuickSort( arr , 0 , size-1);
    print(arr , size);
    return 0;
}
