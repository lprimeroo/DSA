import java.util.Scanner

class BubbleSort {

    //Bubble sort in ascending order
    fun bubblesort(arr: IntArray) {
        for (i in 0 until arr.size - 1) {
            for (j in 0 until arr.size - i - 1)
                if (arr[j] > arr[j + 1]) {
                    val tmp = arr[j]
                    arr[j] = arr[j + 1]
                    arr[j + 1] = tmp
                }
        }

        //printing the sorted array
        for (i in arr.indices)
            System.out.print(arr[i].toString() + " ")
    }

    companion object {
        //Main function taking input from user
        fun main(args: Array<String>) {

            val input = Scanner(System.`in`)
            val obj = BubbleSort()

            System.out.print("Enter number of elements in array:")
            val n = input.nextInt()

            val arr = IntArray(n)
            System.out.println("Enter elements of the array:")
            for (i in 0 until n)
                arr[i] = input.nextInt()

            System.out.println("Sorted array:")
            obj.bubblesort(arr)
        }
    }
}
