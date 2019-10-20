// Java implementation of ShellSort
class ShellSort {

    /* function to sort arr using shellSort */
    fun sort(arr: IntArray): Int {
        val n = arr.size

        // Start with a big gap, then reduce the gap
        var gap = n / 2
        while (gap > 0) {
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already
            // in gapped order keep adding one more element
            // until the entire array is gap sorted
            var i = gap
            while (i < n) {
                // add a[i] to the elements that have been gap
                // sorted save a[i] in temp and make a hole at
                // position i
                val temp = arr[i]

                // shift earlier gap-sorted elements up until
                // the correct location for a[i] is found
                var j: Int
                j = i
                while (j >= gap && arr[j - gap] > temp) {
                    arr[j] = arr[j - gap]
                    j -= gap
                }

                // put temp (the original a[i]) in its correct
                // location
                arr[j] = temp
                i += 1
            }
            gap /= 2
        }
        return 0
    }

    companion object {
        /* An utility function to print array of size n*/
        fun printArray(arr: IntArray) {
            val n = arr.size
            for (i in 0 until n)
                System.out.print(arr[i].toString() + " ")
            System.out.println()
        }

        // Driver method
        fun main(args: Array<String>) {
            val arr = intArrayOf(12, 34, 54, 2, 3)
            System.out.println("Array before sorting")
            printArray(arr)

            val ob = ShellSort()
            ob.sort(arr)

            System.out.println("Array after sorting")
            printArray(arr)
        }
    }
}
