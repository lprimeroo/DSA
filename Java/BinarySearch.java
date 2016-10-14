import java.util.Scanner;

class BinarySearch {
	
	//Function using binary search algo in recursive method
	int binarysearch(int[] arr,int l,int r,int x)
	{
		if(r>=l)
		{
			int mid=l+(r-l)/2;
			
			if(arr[mid]==x)
				return mid;
			
			if(arr[mid]>x)
				return binarysearch(arr,l,mid-1,x);
			
				return binarysearch(arr,mid+1,r,x);
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
		int el=input.nextInt();
		
		int result = obj.binarysearch(arr,0,n-1,el);
		
	    if (result == -1)
	        System.out.println("Element not present");
	    else
	        System.out.println("Element found at index "+result);
		
	}
}
