#include <iostream>
using namespace std;

void merge(int a[],int l,int m,int r)
{
	int i = l,j=m+1,k=l;
	int *c = new int[50];

	while((i<=m) && (j<=r))
	{
		if(a[i]<a[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = a[j++];
		}
	}

	while(i<=m)
	{
		c[k++] = a[i++];
	}

	while(j<=r)
	{
		c[k++] = a [j++];
	}

	for(i=l;i<=r;i++)
	{
		a[i] = c[i];
	}
}

void mergesort(int a[],int l,int r)
{
	int mid;
	if(l<r)
	{
		mid = (l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
int main()
{
	int *a,n,i;
	cin>>n;
	a = new int[n];

	for(i=0;i<n;i++)
		cin>>a[i];

	mergesort(a,0,n-1);

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}