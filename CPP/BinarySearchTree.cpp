#include <iostream>

template <class T> struct Node
{
  T value;
  Node *left;
  Node *right;

  Node(T value)
  {
      this->value = value;
  }

  Node (T value, Node <T> left, Node <T> right)
  {
    this->value = value;
    this->left = left;
    this->right = right;
  }
}

template <class T> class BinarySearchTree{
  
}

int int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
