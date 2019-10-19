// cruxiu :)
import java.util.ArrayList
import java.util.Scanner

class SelectionSort {
    fun selectionSort(list: Array<Integer>): Array<Integer> {
        for (i in 0 until list.size - 1) {
            var index = i
            for (j in i + 1 until list.size)
                if (list[j] < list[index])
                    index = j

            val smallerNumber = list[index].toInt()
            list[index] = list[i]
            list[i] = smallerNumber
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
        array = selectionSort(array)
        System.out.println("After sort, your list now is:")
        for (i in array.indices) {
            System.out.println(array[i])
        }
    }
}
