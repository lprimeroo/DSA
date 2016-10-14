import java.util.Scanner;

class BubbleSort {
	
	//Bubble sort in ascending order
	void bubblesort(int arr[])
	{		
		for(int i=0;i<arr.length-1;i++)
		{
			for(int j=0;j<arr.length-i-1;j++)
				if(arr[j]>arr[j+1])
				{
					int tmp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=tmp;
				}
		}
		
		//printing the sorted array
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
	}
	//Main function taking input from user
	public static void main(String[] args) {
		
		Scanner input=new Scanner(System.in);
		BubbleSort obj=new BubbleSort();
		
		System.out.print("Enter number of elements in array:");
		int n=input.nextInt();
		
		int[] arr=new int[n];
		System.out.println("Enter elements of the array:");
		for(int i=0;i<n;i++)
		arr[i]=input.nextInt();
		
		System.out.println("Sorted array:");
		obj.bubblesort(arr);	
	}
}
