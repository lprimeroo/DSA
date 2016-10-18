import java.util.*;

class MergeSort 
{

	private void merge(int[] a,int low,int high)
	{
		int mid=(low+high)/2;
		int i=low,j=mid+1;
		int[] c = new int[high-low+1];
		int k=0;
		while(i<=mid && j<=high)
		{
			if(a[i]<=a[j])
			{
				c[k]=a[i];
				i++;
				k++;
			}
			else
			{
				c[k]=a[j];
				j++;
				k++;
			}
		}
		while(i<=mid)
		{
			c[k]=a[i];
			k++;
			i++;
		}
		while(j<=high)
		{
			c[k]=a[j];
			k++;
			j++;
		}
		for(i=low;i<=high;i++)
		{
			a[i]=c[i-low];
		}
	}

	public void mergesort(int[] a,int low, int high)
	{
		if(low>=high)
			return;
		else
		{
			int mid=(low+high)/2;
			mergesort(a,low,mid);
			mergesort(a,mid+1,high);
			merge(a,low,high);
		}
	}

	public void print(int[] a,int n)
	{
		int i=0;
		for(i=0;i<n;i++)
			System.out.print(a[i]+" ");
	}

	public static void main(String[] args)
	{
		Scanner inputSize = new Scanner(System.in);
        System.out.println("Enter number of elements:");
        int size = inputSize.nextInt();

        Scanner inputElements = new Scanner(System.in);
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            System.out.println("Enter the element " + (i + 1) + ":");
            a[i] = inputElements.nextInt();
        }
        inputSize.close();
        inputElements.close();

       	MergeSort mergeSort = new MergeSort();
       	mergeSort.mergesort(a,0,size-1);
       	mergeSort.print(a,size);
	}
}