// Java program for implementation of Comb Sort
class CombSort {
    // To find gap between elements
    fun getNextGap(gap: Int): Int {
        var gap = gap
        // Shrink gap by Shrink factor
        gap = gap * 10 / 13
        return if (gap < 1) 1 else gap
    }

    // Function to sort arr[] using Comb Sort
    fun sort(arr: IntArray) {
        val n = arr.size

        // initialize gap
        var gap = n

        // Initialize swapped as true to make sure that
        // loop runs
        var swapped = true

        // Keep running while gap is more than 1 and last
        // iteration caused a swap
        while (gap != 1 || swapped == true) {
            // Find next gap
            gap = getNextGap(gap)

            // Initialize swapped as false so that we can
            // check if swap happened or not
            swapped = false

            // Compare all elements with current gap
            for (i in 0 until n - gap) {
                if (arr[i] > arr[i + gap]) {
                    // Swap arr[i] and arr[gap]
                    arr[i] = arr[i + gap]
                    arr[i + gap] = arr[i]
                    arr[i] = arr[i + gap]

                    // Set swapped
                    swapped = true
                }
            }
        }
    }

    companion object {

        // Driver method
        fun main(args: Array<String>) {
            val ob = CombSort()
            val arr = intArrayOf(8, 4, 1, 56, 3, -44, 23, -6, 28, 0)
            ob.sort(arr)

            System.out.println("sorted array")
            for (i in arr.indices)
                System.out.print(arr[i].toString() + " ")

        }
    }
}
