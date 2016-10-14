#include <iostream>
using namespace std;

int main()
{
	int *a,n,i,j,temp;
	cin>>n;
	a = new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	cout<<"Sorted array\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}