#include<bits/stdc++.h>
using namespace std;

int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
 
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    free(lis);
 
    return max;
}
 
int main()
{
    int n;
    int arr[100000] ;
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>arr[i];
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}
