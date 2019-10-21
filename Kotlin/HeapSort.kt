import java.util.Scanner

class HeapSort {
    fun main(args: Array<String>) {
        var arr: IntArray
        val n: Int
        val userIn = Scanner(System.`in`)

        System.out.println("Enter the number of elements: ")
        n = userIn.nextInt()
        arr = IntArray(n)

        System.out.println("Enter each of the elements: ")
        for (i in 0 until n) {
            arr[i] = userIn.nextInt()
        }

        userIn.close()

        arr = heapSort(arr, n)

        System.out.println("Sorted array is:")
        printArray(arr, n)
    }

    fun heapSort(arr: IntArray, n: Int): IntArray {
        var arr = arr
        var temp: Int

        for (i in n / 2 - 1 downTo 0) {
            arr = heapify(arr, n, i)
        }

        for (i in n - 1 downTo 0) {
            temp = arr[0]
            arr[0] = arr[i]
            arr[i] = temp

            arr = heapify(arr, i, 0)
        }

        return arr
    }

    fun heapify(arr: IntArray, n: Int, i: Int): IntArray {
        var large = i
        val l = 2 * i + 1
        val r = 2 * i + 2
        val temp: Int

        if (l < n && arr[l] > arr[large]) {
            large = l
        }

        if (r < n && arr[r] > arr[large]) {
            large = r
        }

        if (large != i) {
            temp = arr[i]
            arr[i] = arr[large]
            arr[large] = temp

            heapify(arr, n, large)
        }

        return arr
    }

    fun printArray(arr: IntArray, n: Int) {
        for (i in 0 until n) {
            System.out.print(arr[i].toString() + " ")
        }
        System.out.println()
    }
}