class SegmentTree(size: Int) {
    private val tree: IntArray
    private val maxsize: Int
    private val height: Int

    private val STARTINDEX = 0
    private val ENDINDEX: Int
    private val ROOT = 0

    init {
        height = Math.ceil(Math.log(size) / Math.log(2))
        maxsize = 2 * Math.pow(2, height) as Int - 1
        tree = IntArray(maxsize)
        ENDINDEX = size - 1
    }

    private fun leftchild(pos: Int): Int {
        return 2 * pos + 1
    }

    private fun rightchild(pos: Int): Int {
        return 2 * pos + 2
    }

    private fun mid(start: Int, end: Int): Int {
        return start + (end - start) / 2
    }

    private fun getSumUtil(startIndex: Int, endIndex: Int, queryStart: Int, queryEnd: Int, current: Int): Int {
        if (queryStart <= startIndex && queryEnd >= endIndex) {
            return tree[current]
        }
        if (endIndex < queryStart || startIndex > queryEnd) {
            return 0
        }
        val mid = mid(startIndex, endIndex)
        return getSumUtil(startIndex, mid, queryStart, queryEnd, leftchild(current)) + getSumUtil(mid + 1, endIndex, queryStart, queryEnd, rightchild(current))
    }

    fun getSum(queryStart: Int, queryEnd: Int): Int {
        return if (queryStart < 0 || queryEnd > tree.size) {
            -1
        } else getSumUtil(STARTINDEX, ENDINDEX, queryStart, queryEnd, ROOT)
    }

    private fun constructSegmentTreeUtil(elements: IntArray, startIndex: Int, endIndex: Int, current: Int): Int {
        if (startIndex == endIndex) {
            tree[current] = elements[startIndex]
            return tree[current]
        }
        val mid = mid(startIndex, endIndex)
        tree[current] = constructSegmentTreeUtil(elements, startIndex, mid, leftchild(current)) + constructSegmentTreeUtil(elements, mid + 1, endIndex, rightchild(current))
        return tree[current]
    }

    fun constructSegmentTree(elements: IntArray) {
        constructSegmentTreeUtil(elements, STARTINDEX, ENDINDEX, ROOT)
    }

    private fun updateTreeUtil(startIndex: Int, endIndex: Int, updatePos: Int, update: Int, current: Int) {
        if (updatePos < startIndex || updatePos > endIndex) {
            return
        }
        tree[current] = tree[current] + update
        if (startIndex != endIndex) {
            val mid = mid(startIndex, endIndex)
            updateTreeUtil(startIndex, mid, updatePos, update, leftchild(current))
            updateTreeUtil(mid + 1, endIndex, updatePos, update, rightchild(current))
        }
    }

    fun update(update: Int, updatePos: Int, elements: IntArray) {
        val updatediff = update - elements[updatePos]
        elements[updatePos] = update
        updateTreeUtil(STARTINDEX, ENDINDEX, updatePos, updatediff, ROOT)
    }

    companion object {

        fun main(vararg arg: String) {
            val elements = intArrayOf(1, 3, 5, 7, 9, 11)
            val segmentTree = SegmentTree(6)
            segmentTree.constructSegmentTree(elements)
            var num = segmentTree.getSum(1, 5)

            System.out.println("the num is $num")
            segmentTree.update(10, 5, elements)
            num = segmentTree.getSum(1, 5)
            System.out.println("the num is $num")
        }
    }
}