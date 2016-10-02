class TreeNode:

    def __init__(self, val, left = None, right = None, parent = None):
        self.val        = val
        self.leftChild  = left
        self.rightChild = right
        self.parent     = parent

    def hasLeftChild(self):
        return self.leftChild

    def hasRightChild(self):
        return self.rightChild

    def isRoot(self):
        return not self.parent

    def isLeaf(self):
        return not(self.leftChild or self.rightChild)


class BinarySearchTree:

    def __init__(self):
        self.root = None


    def insert(self, val):
        if self.root:
            self._insert(val, self.root)
        else:
            self.root = TreeNode(val)

    def _insert(self, val, currentNode):
        if val < currentNode.val:
            if currentNode.hasLeftChild():
                self._insert(val, currentNode.leftChild)
            else:
                currentNode.leftChild = TreeNode(val, parent = currentNode)
        else:
            if currentNode.hasRightChild():
                self._insert(val, currentNode.rightChild)
            else:
                currentNode.rightChild = TreeNode(val, parent = currentNode)



    # if BST contains node return it

    def contains(self, val):
        if self.root:
            return self._contains(val, self.root)
        else:
            return None

    def _contains(self, val, currentNode):
        if not currentNode:
            return None
        elif val == currentNode.val:
            return currentNode
        elif val < currentNode:
            return self._contains(val, currentNode.leftChild)
        else:
            return self._contains(val, currentNode.rightChild)


    # search for the minimum node

    def findMin(self):
        if self.root:
            return self._findMin(self.root)
        else:
            return None

    def _findMin(self, currentNode):
        if currentNode.hasLeftChild():
            return self._finMin(currentNode.leftChild)
        else:
            return currentNode


    # search for the maximum node

    def findMax(self):
        if self.root:
            return self._findMax(self.root)
        else:
            return None

    def _findMax(self, currentNode):
        if currentNode.hasRightChild():
            return _findMax(currentNode.rightChild)
        else:
            return currentNode

