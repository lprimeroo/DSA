import java.util.Scanner

class RadixSort {
    fun main(args: Array<String>) {
        var arr = IntArray(100000)
        val n: Int
        val userIn = Scanner(System.`in`)

        // retrieve number of elements and elements to be sorted
        System.out.print("Enter the number of elements: ")
        n = userIn.nextInt()

        System.out.print("Enter each of the elements: ")
        for (i in 0 until n) {
            arr[i] = userIn.nextInt()
        }

        // close user input
        userIn.close()

        // perform radix sort
        arr = radixSort(arr, n)

        // display the sorted result
        System.out.println("After sorting:")
        printArr(arr, n)
    }

    private fun printArr(arr: IntArray, n: Int) {
        for (i in 0 until n) {
            System.out.print(arr[i].toString() + " ")
        }
        System.out.println()
    }

    private fun radixSort(arr: IntArray, n: Int): IntArray {
        var arr = arr
        val max = getMax(arr, n)

        var exp = 1
        while (max / exp > 0) {
            arr = countSort(arr, n, exp)
            exp *= 10
        }

        return arr
    }

    private fun getMax(arr: IntArray, n: Int): Int {
        var max = arr[0]

        for (i in 1 until n) {
            if (arr[i] > max) max = arr[i]
        }

        return max
    }

    private fun countSort(arr: IntArray, n: Int, exp: Int): IntArray {
        val output = IntArray(n)
        val count = IntArray(10)
        var i: Int

        // store count of occurrences in count[]
        i = 0
        while (i < n) {
            count[arr[i] / exp % 10]++
            i++
        }

        i = 1
        while (i < 10) {
            count[i] += count[i - 1]
            i++
        }

        // making the output array
        i = n - 1
        while (i >= 0) {
            output[count[arr[i] / exp % 10] - 1] = arr[i]
            count[arr[i] / exp % 10]--
            i--
        }

        return output
    }
}
