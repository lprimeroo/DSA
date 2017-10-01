#include <vector>

#include <iostream>

template <typename T, typename C = std::vector<T> >
class CircularBuffer {
 public:
  // typical (value centric) STL-aliases
  typedef T value_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef unsigned int size_type;

 private:
  // this is me-and-myself, STL-style 
  typedef CircularBuffer<T, C> class_type;

  // forbid copy-construction (as inside private)
  CircularBuffer(const class_type& cls);
  class_type& operator=(const class_type& cls);

  // underlying-item-container
  C items;

  // maximum capacity
  const size_type max_items;

 public:
  // create CircularBuffer directly with its max slot count
  CircularBuffer(unsigned int max_slots) : max_items(max_slots) {}

  // is empty ?
  bool empty() const {
    return items.empty();
  }
  // return container item count
  size_type size() const {
    return items.size();
  }
  // return maximum capacity
  size_type capacity() const {
    return max_items;
  }

  // front item inspect (const & non-const)
  reference front() {
    return items.front();
  }
  const_reference front() const {
    return items.front();
  }

  // pop and throw away front item
  void pop() {
    if (!empty())
      items.erase(items.begin());
  }

  // back item inspect
  reference back() {
    return items.back();
  }
  const_reference back() const {
    return items.back();
  }

  // push new item at back and maintain circular property
  void push(const value_type& item) {
    if (items.size() == max_items)
      pop();
    items.push_back(item);
  }
};

using namespace std;

int main() {

	CircularBuffer<int> circ_buf_int(5);

	cout << "adding 12, 22, 32, 42, 52" << endl << endl;
	circ_buf_int.push(12);
	circ_buf_int.push(22);
	circ_buf_int.push(32);
	circ_buf_int.push(42);
	circ_buf_int.push(52);

	cout << "five items added" << endl;
	cout << circ_buf_int.front() << endl;
	cout << circ_buf_int.back() << endl << endl;

	circ_buf_int.push(100);
	circ_buf_int.push(200);
	
	cout << "two more items added (100 and 200)" << endl;
	cout << circ_buf_int.front() << endl;
	cout << circ_buf_int.back() << endl;

  return 0;
}

