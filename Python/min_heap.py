import heapq
class Heap(object):

    """ A binary heap is a complete binary tree which satisfies the heap
    ordering property. The ordering can be one of two types:

    the min-heap property: the value of each node is greater than or equal to
    the value of its parent, with the minimum-value element at the root.
    the max-heap property: the value of each node is less than or equal to the
    value of its parent, with the maximum-value element at the root.
    this specific code and class is for max heap. Max heap is also impleneted in
    the same way.(code has been added).

    In a heap the highest (or lowest) priority element is always stored at the
    root, hence the name "heap". A heap is not a sorted structure and can
    be regarded as partially ordered. As you see from the picture, there is no
    particular relationship among nodes on any given level, even among the siblings.

    Since a heap is a complete binary tree, it has a smallest possible height -
    a heap with N nodes always has O(log N) height.

    A heap is useful data structure when you need to remove the object with the
    highest (or lowest) priority. A common use of a heap is to implement a
    priority queue. """

    def __init__(self):
        """ create a new min-heap. """
        self._heap = []

    def push(self, item):
        """ Push an item with into the heap.  """
        heapq.heappush(self._heap, item)

    def pop(self):
        """ Returns the item with least"""
        item = heapq.heappop(self._heap)[1] # (prio, item)[1] == item
        return item

    def __len__(self):
        return len(self._heap)

    def __iter__(self):
        """ Get all elements ordered by asc. """
        return self

    def next(self):
        """ Get all elements ordered (lowest first). """
        try:
            return self.pop()
        except IndexError:
            raise StopIteration
