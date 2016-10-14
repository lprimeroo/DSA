import java.util.Scanner;

/**
 * Java implementation QuickSort.
 */ 
public class Quicksort {

    public static void quicksort(int[] array, int low, int high){
        if (low < high) {
            int pi = partition(array, low, high);

            // Separately sort elements before
            // Partition and after partition
            quicksort(array, low, pi - 1);
            quicksort(array, pi + 1, high);
        }
    }

    private static int partition(int[] array, int low, int high) {
        int pivot = array[high];
        int i = (low - 1); // Index of smaller element

        for (int j= low; j <= high - 1; j++) {

            // If current element is smaller than or equal to pivot
            if (array[j] <= pivot){
                i++; // Increment index of smaller element
                int aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
        int aux = array[i + 1];
        array[i + 1] = array[high];
        array[high] = aux;
        return (i + 1);
    }

    public static void printArray(int[] array, int size) {
        for (int i = 0; i < size; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void main(String args[]){

        Scanner inputSize = new Scanner(System.in);
        System.out.println("enter number of elements:");
        int size = inputSize.nextInt();

        Scanner inputElements = new Scanner(System.in);
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            System.out.println("enter the element " + (i + 1) + ":");
            array[i] = inputElements.nextInt();
        }
        inputSize.close();
        inputElements.close();

        Quicksort.quicksort(array, 0, array.length-1);
        System.out.println("Sorted array:");
        Quicksort.printArray(array, array.length);
        System.out.print("\n");
    }
}
