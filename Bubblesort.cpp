#include <iostream>
using namespace std;

int main()
{
	
	//i and j are used to iterate through the bubble sort 
	int *arrayToSort,arraySize,i,j,temp;
	
	//Read in the desired aray size
	cin>>arraySize;
	
	//Define the size of the array to 'arrayToSort' and allow the user to populate said array.
	arrayToSort = new int[arraySize];
	for(i=0;i<arraySize;i++)
		cin>>arrayToSort[i];

	//Contains two loops || Note that in both average and worst-case scenarios, results in a big O notation of O(N^2)
	for(i=0;i<arraySize-1;i++)
	{
		for(j=0;j<arraySize-i-1;j++)
		{
			//Compares the values of all elements, swapping the lower figures for higher ones 
			if(arrayToSort[j]>arrayToSort[j+1])
			{
				temp = arrayToSort[j];
				arrayToSort[j] = arrayToSort[j+1];
				arrayToSort[j+1] = temp;
			}
		}
	}

	cout<<"Sorted array\n";
	for(i=0;i<arraySize;i++)
		cout<<arrayToSort[i]<<" ";
	cout<<endl;
}
