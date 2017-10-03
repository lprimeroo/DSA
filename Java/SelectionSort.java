// cruxiu :)
import java.util.ArrayList;
import java.util.Scanner;

public class SelectionSort {
    public static Integer [] selectionSort(Integer [] list){
      for (int i = 0; i < list.length - 1; i++)
      {
          int index = i;
          for (int j = i + 1; j < list.length; j++)
              if (list[j] < list[index])
                  index = j;

          int smallerNumber = list[index];
          list[index] = list[i];
          list[i] = smallerNumber;
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
        array = selectionSort(array);
        System.out.println("After sort, your list now is:");
        for(int i = 0; i < array.length; i++){
           System.out.println(array[i]);
        }
    }
}
