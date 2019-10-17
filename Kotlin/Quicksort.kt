import java.util.Scanner

/**
 * Java implementation QuickSort.
 */
class Quicksort {

    fun quicksort(array: IntArray, low: Int, high: Int) {
        if (low < high) {
            val pi = partition(array, low, high)

            // Separately sort elements before
            // Partition and after partition
            quicksort(array, low, pi - 1)
            quicksort(array, pi + 1, high)
        }
    }

    private fun partition(array: IntArray, low: Int, high: Int): Int {
        val pivot = array[high]
        var i = low - 1 // Index of smaller element

        for (j in low..high - 1) {

            // If current element is smaller than or equal to pivot
            if (array[j] <= pivot) {
                i++ // Increment index of smaller element
                val aux = array[i]
                array[i] = array[j]
                array[j] = aux
            }
        }
        val aux = array[i + 1]
        array[i + 1] = array[high]
        array[high] = aux
        return i + 1
    }

    fun printArray(array: IntArray, size: Int) {
        for (i in 0 until size) {
            System.out.print(array[i].toString() + " ")
        }
    }

    fun main(args: Array<String>) {

        val inputSize = Scanner(System.`in`)
        System.out.println("enter number of elements:")
        val size = inputSize.nextInt()

        val inputElements = Scanner(System.`in`)
        val array = IntArray(size)
        for (i in 0 until size) {
            System.out.println("enter the element " + (i + 1) + ":")
            array[i] = inputElements.nextInt()
        }
        inputSize.close()
        inputElements.close()

        Quicksort.quicksort(array, 0, array.size - 1)
        System.out.println("Sorted array:")
        Quicksort.printArray(array, array.size)
        System.out.print("\n")
    }
}
