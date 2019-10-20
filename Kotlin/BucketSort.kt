import java.util.Random

class BucketSort {
    internal fun sort(sequence: IntArray, maxValue: Int): IntArray {
        // Bucket Sort
        val Bucket = IntArray(maxValue + 1)
        val sorted_sequence = IntArray(sequence.size)

        for (i in sequence.indices)
            Bucket[sequence[i]]++

        var outPos = 0
        for (i in Bucket.indices)
            for (j in 0 until Bucket[i])
                sorted_sequence[outPos++] = i

        return sorted_sequence
    }

    internal fun printSequence(sorted_sequence: IntArray) {
        for (i in sorted_sequence.indices)
            System.out.print(sorted_sequence[i].toString() + " ")
    }

    internal fun maxValue(sequence: IntArray): Int {
        var maxValue = 0
        for (i in sequence.indices)
            if (sequence[i] > maxValue)
                maxValue = sequence[i]
        return maxValue
    }

    fun main(args: Array<String>) {
        System.out
                .println("Sorting of randomly generated numbers using BUCKET SORT")
        val random = Random()
        val N = 20
        val sequence = IntArray(N)

        for (i in 0 until N)
            sequence[i] = Math.abs(random.nextInt(100))

        val maxValue = maxValue(sequence)

        System.out.println("\nOriginal Sequence: ")
        printSequence(sequence)

        System.out.println("\nSorted Sequence: ")
        printSequence(sort(sequence, maxValue))
    }
}
