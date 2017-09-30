// C++ implementation of Radix Sort
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// Count sort implementation
void countSort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Making the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
    
    int m = getMax(arr, n);
 
    // Counting sort for every digit. 
    // Instead of passing digit number, exp is passed. exp is 10^i
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 

int main()
{
    int arr[100000];
    int n;
    cout << "enter the number of elements:";
    cin>>n;
    cout<<"enter all the elements:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    radixsort(arr, n);
    cout << "After Sorting :\n";
    print(arr, n);
    return 0;
}

