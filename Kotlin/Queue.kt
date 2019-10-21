import java.util.ArrayList

class Queue<T> internal constructor() {
    private val queue: ArrayList<T>

    val isEmpty: Boolean
        get() = queue.size() < 1

    init {
        queue = ArrayList<T>()
    }

    fun enqueue(element: T) {
        queue.add(element)
    }

    @Throws(EmptyQueueException::class)
    fun dequeue(): T {
        if (isEmpty) {
            throw EmptyQueueException("Dequeue")
        } else {
            val element = queue.get(0)
            queue.remove(0)
            return element
        }
    }

}

internal class EmptyQueueException(action: String) : Exception("Queue is empty. Underflow.Cannot perform action $action")
