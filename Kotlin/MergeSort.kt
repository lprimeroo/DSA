import java.util.*

class MergeSort {

    private fun merge(a: IntArray, low: Int, high: Int) {
        val mid = (low + high) / 2
        var i = low
        var j = mid + 1
        val c = IntArray(high - low + 1)
        var k = 0
        while (i <= mid && j <= high) {
            if (a[i] <= a[j]) {
                c[k] = a[i]
                i++
                k++
            } else {
                c[k] = a[j]
                j++
                k++
            }
        }
        while (i <= mid) {
            c[k] = a[i]
            k++
            i++
        }
        while (j <= high) {
            c[k] = a[j]
            k++
            j++
        }
        i = low
        while (i <= high) {
            a[i] = c[i - low]
            i++
        }
    }

    fun mergesort(a: IntArray, low: Int, high: Int) {
        if (low >= high)
            return
        else {
            val mid = (low + high) / 2
            mergesort(a, low, mid)
            mergesort(a, mid + 1, high)
            merge(a, low, high)
        }
    }

    fun print(a: IntArray, n: Int) {
        var i = 0
        i = 0
        while (i < n) {
            System.out.print(a[i].toString() + " ")
            i++
        }
    }

    companion object {

        fun main(args: Array<String>) {
            val inputSize = Scanner(System.`in`)
            System.out.println("Enter number of elements:")
            val size = inputSize.nextInt()

            val inputElements = Scanner(System.`in`)
            val a = IntArray(size)
            for (i in 0 until size) {
                System.out.println("Enter the element " + (i + 1) + ":")
                a[i] = inputElements.nextInt()
            }
            inputSize.close()
            inputElements.close()

            val mergeSort = MergeSort()
            mergeSort.mergesort(a, 0, size - 1)
            mergeSort.print(a, size)
        }
    }
}