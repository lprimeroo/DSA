class Queue:
    def __init__(self):
        self.elements = []

    def empty(self):
        return self.elements == []

    def enqueue(self, element):
        self.elements.insert(0, element)

    def dequeue(self):
        return self.elements.pop()

    def size(self):
        return len(self.elements)


if __name__ == "__main__":
    q = Queue()
    print("Initialized queue q")
    print("Is q empty?", q.empty())
    print("Size is", q.size())
    print("q is", q.elements)
    print("Enqueued:", end='')
    for x in range(1,16):
        q.enqueue(x)
        print(x, end=' ')
    print("\nq is now", q.elements)
    print("Is q empty?", q.empty())
    print("Size is now", q.size())
    print("Dequeued:", end=' ')
    for x in range(13):
        print(q.dequeue(), end=' ')
    print("\nq is now", q.elements)
    print("Size is now", q.size())
    print("Dequeued:", end=' ')
    for x in range(2):
        print(q.dequeue(), end=' ')
    print("\nq is now", q.elements)
    print("Size is now", q.size())
    print("Is q empty?", q.empty())