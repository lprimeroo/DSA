import javafx.util.Pair
import java.util.ArrayList

class MinHeap<T : Comparable<T>> {

    private var heap: ArrayList<T>? = null

    val isEmpty: Boolean
        get() = heap!!.size() <= 1

    val min: T
        @Throws(EmptyHeapException::class)
        get() {
            if (heap!!.size() <= 1) {
                throw EmptyHeapException("getMin")
            }

            return heap!!.get(1)
        }

    constructor() {
        heap = ArrayList<T>(32)
        heap!!.add(null)
    }

    private constructor(array: Array<T>?) {
        heap = ArrayList<T>(2)
        heap!!.add(null)

        if (array == null || array.size < 1) {
            return
        }

        heap!!.ensureCapacity(array.size + 2)
        for (i in array.indices) {
            heap!!.add(array[i])
        }

        for (i in heap!!.size() / 2 downTo 1) {
            bubbleDown(i)
        }
    }

    fun insert(element: T) {
        heap!!.add(element)
        bubbleUp(heap!!.size() - 1)
    }

    @Throws(EmptyHeapException::class)
    fun extractMin() {
        if (heap!!.size() <= 1) {
            throw EmptyHeapException("extractMin")
        }

        heap!!.set(1, heap!!.get(heap!!.size() - 1))
        heap!!.remove(heap!!.size() - 1)
        bubbleDown(1)
    }

    private fun bubbleUp(n: Int) {
        if (n > 1) {
            val parent = heap!!.get(n shr 1)

            if (parent.compareTo(heap!!.get(n)) === 1) {
                heap!!.set(n shr 1, heap!!.get(n))
                heap!!.set(n, parent)

                bubbleUp(n shr 1)
            }
        }
    }

    private fun bubbleDown(n: Int) {
        if ((n shl 1) + 1 < heap!!.size() || n shl 1 < heap!!.size()) {
            val son = getSonWithLowerKey(n)

            if (son.getValue().compareTo(heap!!.get(n)) === -1) {
                heap!!.set(son.getKey(), heap!!.get(n))
                heap!!.set(n, son.getValue())

                bubbleDown(son.getKey())
            }
        }
    }

    private fun getSonWithLowerKey(n: Int): Pair<Integer, T> {
        val leftSonIndex = n shl 1
        val rightSonIndex = leftSonIndex + 1

        if (rightSonIndex >= heap!!.size()) {
            return Pair<Integer, T>(leftSonIndex, heap!!.get(leftSonIndex))
        }

        val leftSon = heap!!.get(leftSonIndex)
        val rightSon = heap!!.get(rightSonIndex)

        return if (leftSon.compareTo(rightSon) < 0) {
            Pair<Integer, T>(leftSonIndex, leftSon)
        } else Pair<Integer, T>(rightSonIndex, rightSon)

    }

    companion object {

        fun <E : Comparable<E>> makeHeap(array: Array<E>): MinHeap<E> {
            return MinHeap(array)
        }
    }

}

internal class EmptyHeapException(action: String) : Exception("Heap is empty. Cannot perform action '".concat(action).concat("'."))
