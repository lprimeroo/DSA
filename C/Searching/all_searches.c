//ALL TYPES OF SEARCHES

#include<stdio.h>
#include<stdbool.h>

void sort( int arr[5] , int size)
{
    for( int i = 0 ; i < size  ; i++)
    {
        for( int j = 0 ; j < size-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

bool binary_search( int arr[] ,int low , int high,  int key )
{

    if(low>high)
    {
        printf("NOT FOUND\n");
        return false;
    }

    int mid = (low+high)/2;
    if( arr[mid] == key)
    {
        printf("FOUND\n");
        return true;
    }
    else if( arr[mid] < key)
    {
        binary_search(arr, mid+1 , high , key );
    }
    else
    {
        binary_search(arr, low , mid-1 , key );
    }
}

bool binary_search_iterative( int arr[] , int size , int key)
{
    int low = 0;
    int high = size-1;


    while(low < high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == key)
        {
            printf("FOUND\n");
            return true;
        }
        else if(arr[mid] > key)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    printf("NOT FOUND\n");
    return false;
}


void print(int arr[5] , int size)
{
    for(int i = 0 ; i< size ; i++)
    {
        printf("%2d" , arr[i]);
    }
    printf("\n");
}

bool linear_search( int arr[] , int size , int key)
{
    for( int i = 0 ; i < size ; i++ )
    {
        if(arr[i] == key)
        {
            printf("FOUND\n");
            return true;
        }
    }
    printf("Not Found\n");
    return false;
}

int main()
{
    int arr[5] = {3,4,1,5,0};
    sort(arr , 5);
    print(arr , 5);
    binary_search(arr , 0 , 5 , 4);
    binary_search_iterative(arr , 5 , 9);
    linear_search(arr , 5 , 1);
}
