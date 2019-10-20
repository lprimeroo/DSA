import java.util.Scanner;

class BinarySearch {
	
	//Function using binary search algo in recursive method
	int binarySearch(int[] arr,int low,int high,int searchElement)
	{
		if(high>=low)
		{
			int mid=low+(high-low)/2;
			
			if(arr[mid]==searchElement)
				return mid;
			
			if(arr[mid]>searchElement)
				return binarySearch(arr,low,mid-1,searchElement);
			
				return binarySearch(arr,mid+1,high,searchElement);
		}
		return -1;
	}
	
	//Main function is used to take inputs
	public static void main(String args[])
	{
		Scanner input=new Scanner(System.in);
		BinarySearch obj=new BinarySearch();
		
		System.out.print("Enter number of elements in array:");
		int n=input.nextInt();
		
		int[] arr=new int[n];
		System.out.println("Enter elements of the array:");
		for(int i=0;i<n;i++)
		arr[i]=input.nextInt();
		
		System.out.print("Enter element to be searched:");
		int findElement=input.nextInt();
		
		int result = obj.binarySearch(arr,0,n-1,findElement);
		
	    if (result == -1)
	        System.out.println("Element not present");
	    else
	        System.out.println("Element found at index "+result);
		
	}
}
