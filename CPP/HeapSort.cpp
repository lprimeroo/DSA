/*C++ Imlementation HeapSort*/
#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int m, int i)
{
    int large = i;  // Initialize large
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child node is larger than root
    if (l < m && arr[l] > arr[large])
        large = l;

    // If right child node is larger than largest so far
    if (r < m && arr[r] > arr[large])
        large = r;

    // If large is not root
    if (large != i)
    {
        swap(arr[i], arr[large]);

        // Recursively heapify the affected sub-tree
        heapify(arr, m, large);
    }
}

// function to do heap sort
void heapSort(int arr[], int m)
{
    // Build heap 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, m, i);

    // One by one extract an element from heap
    for (int i=m-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int m)
{
    for (int i=0; i<m; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
    int arr[100000];
    int n ;
    cout<<"enter the number of elements:";
    cin>>n;
    cout<<"enter all elements:";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);

    return 0;
}