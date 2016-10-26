import java.util.Scanner;

public class HeapSort {
	public static void main(String[] args) {
		int [] arr;
		int n;
		Scanner userIn = new Scanner(System.in);

		System.out.println("Enter the number of elements: ");
		n = userIn.nextInt();
		arr = new int[n];

		System.out.println("Enter each of the elements: ");
		for (int i = 0; i < n; i++) {
			arr[i] = userIn.nextInt();
		}

		userIn.close();

		arr = heapSort(arr, n);

		System.out.println("Sorted array is:");
		printArray(arr, n);
	}

	public static int [] heapSort(int [] arr, int n) {
		int temp;

		for (int i = n / 2 - 1; i >= 0; i--) {
			arr = heapify(arr, n, i);
		}

		for (int i = n - 1; i >= 0; i--) {
			temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

			arr = heapify(arr, i, 0);
		}

		return arr;
	}

	public static int [] heapify(int [] arr, int n, int i) {
		int large = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int temp;

		if (l < n && arr[l] > arr[large]) {
			large = l;
		}

		if (r < n && arr[r] > arr[large]) {
			large = r;
		}

		if (large != i) {
			temp = arr[i];
			arr[i] = arr[large];
			arr[large] = temp;

			heapify(arr, n, large);
		}

		return arr;
	}

	public static void printArray(int [] arr, int n) {
		for (int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
}