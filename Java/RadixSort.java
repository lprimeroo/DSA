import java.util.Scanner;

public class RadixSort {
	public static void main(String[] args) {
		int [] arr = new int[100000];
		int n;
		Scanner userIn = new Scanner(System.in);
		
		// retrieve number of elements and elements to be sorted
		System.out.print("Enter the number of elements: ");
		n = userIn.nextInt();
		
		System.out.print("Enter each of the elements: ");
		for (int i = 0; i < n; i++) {
			arr[i] = userIn.nextInt();
		}
		
		// close user input
		userIn.close();
		
		// perform radix sort
		arr = radixSort(arr, n);
		
		// display the sorted result
		System.out.println("After sorting:");
		printArr(arr, n);
	}
	
	private static void printArr(int [] arr, int n) {
		for (int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	
	private static int[] radixSort(int [] arr, int n) {
		int max = getMax(arr, n);
		
		for (int exp = 1; max/exp > 0; exp *= 10) {
			arr = countSort(arr, n, exp);
		}
		
		return arr;
	}
	
	private static int getMax(int [] arr, int n) {
		int max = arr[0];
		
		for (int i = 1; i < n; i++) {
			if (arr[i] > max) max = arr[i];
		}
		
		return max;
	}
	
	private static int [] countSort(int [] arr, int n, int exp) {
		int [] output = new int[n];
		int [] count = new int[10];
		int i;
		
		// store count of occurrences in count[]
		for (i = 0; i < n; i++) {
			count[(arr[i]/exp)%10]++;
		}
		
		for (i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		
		// making the output array
		for (i = n - 1; i >= 0; i--) {
			output[count[(arr[i]/exp)%10] - 1] = arr[i];
			count[(arr[i]/exp)%10]--;
		}
		
		return output;
	}
}
