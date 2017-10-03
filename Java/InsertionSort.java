// cruxiu :)
import java.util.ArrayList;
import java.util.Scanner;

public class InsertionSort {
    public static Integer [] insertionSort(Integer [] list){
        int temp;
        for (int i = 1; i < list.length; i++) {
            for(int j = i ; j > 0 ; j--){
                if(list[j] < list[j-1]){
                    temp = list[j];
                    list[j] = list[j-1];
                    list[j-1] = temp;
                }
            }
        }
        return list;
    }
    public static void main(String a[]){
        Scanner scanner = new Scanner(System.in);
        ArrayList <Integer> arrayList = new ArrayList<Integer>();
        System.out.println("Please, enter the elements of the list.");
        while(scanner.hasNextInt()){
          arrayList.add(scanner.nextInt());
        }
        Integer [] array = arrayList.toArray(new Integer[0]);
        System.out.println("Now, we will sort the list. Your list now is:");
        for(int i = 0; i < array.length; i++){
           System.out.println(array[i]);
        }
        array = insertionSort(array);
        System.out.println("After sort, your list now is:");
        for(int i = 0; i < array.length; i++){
           System.out.println(array[i]);
        }
    }
}
