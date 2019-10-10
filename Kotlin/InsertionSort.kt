// cruxiu :)
import java.util.ArrayList
import java.util.Scanner

class InsertionSort {
    fun insertionSort(list: Array<Integer>): Array<Integer> {
        var temp: Int
        for (i in 1 until list.size) {
            for (j in i downTo 1) {
                if (list[j] < list[j - 1]) {
                    temp = list[j].toInt()
                    list[j] = list[j - 1]
                    list[j - 1] = temp
                }
            }
        }
        return list
    }

    fun main(a: Array<String>) {
        val scanner = Scanner(System.`in`)
        val arrayList = ArrayList<Integer>()
        System.out.println("Please, enter the elements of the list.")
        while (scanner.hasNextInt()) {
            arrayList.add(scanner.nextInt())
        }
        var array = arrayList.toArray(arrayOfNulls<Integer>(0))
        System.out.println("Now, we will sort the list. Your list now is:")
        for (i in array.indices) {
            System.out.println(array[i])
        }
        array = insertionSort(array)
        System.out.println("After sort, your list now is:")
        for (i in array.indices) {
            System.out.println(array[i])
        }
    }
}
