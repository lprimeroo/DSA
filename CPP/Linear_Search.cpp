//prograam to perform linear search
#include<stdio.h>
int main()
{
	int n,arr[100],i,search,flag=0;
	printf("Enter the size of the array \n");
	scanf("%d",&n);
	printf("Enter  the array \n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the no. to searched \n");
	scanf("%d",&search);
	for(i=0;i<n;i++)
	{
		if(search == arr[i])
		{
			flag =1;
			break;
		}
	}
	if (flag == 1)
	{
		printf("Search is successful and element is present at %d \n ",i+1);
	}
	else
	{
		printf("Sorry element not found \n");
	}
}
