/* C implementation QuickSort */
#include<bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int arr[100000];
  int n;
  cout<<"enter number of elements: ";
  cin>>n;
  cout<<"enter all elements: ";
  for(int i=0;i<n;i++) cin>>a[i];
	quickSort(arr, 0, n-1);
	cout<<"Sorted array: \n";
	printArray(arr, n);
	return 0;
}
