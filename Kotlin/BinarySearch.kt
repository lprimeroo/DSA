import java.util.Scanner

class BinarySearch {

    //Function using binary search algo in recursive method
    fun binarysearch(arr: IntArray, l: Int, r: Int, x: Int): Int {
        if (r >= l) {
            val mid = l + (r - l) / 2

            if (arr[mid] == x)
                return mid

            return if (arr[mid] > x) binarysearch(arr, l, mid - 1, x) else binarysearch(arr, mid + 1, r, x)

        }
        return -1
    }

    companion object {

        //Main function is used to take inputs
        fun main(args: Array<String>) {
            val input = Scanner(System.`in`)
            val obj = BinarySearch()

            System.out.print("Enter number of elements in array:")
            val n = input.nextInt()

            val arr = IntArray(n)
            System.out.println("Enter elements of the array:")
            for (i in 0 until n)
                arr[i] = input.nextInt()

            System.out.print("Enter element to be searched:")
            val el = input.nextInt()

            val result = obj.binarysearch(arr, 0, n - 1, el)

            if (result == -1)
                System.out.println("Element not present")
            else
                System.out.println("Element found at index $result")

        }
    }
}
