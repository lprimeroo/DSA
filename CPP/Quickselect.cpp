#include <iterator>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>
#include <ctime>
 
template <typename Iterator>
Iterator select(Iterator begin, Iterator end, int n) {
  typedef typename std::iterator_traits<Iterator>::value_type T;
  while (true) {
    Iterator pivotIt = begin + std::rand() % std::distance(begin, end);
    std::iter_swap(pivotIt, end-1);  // Move pivot to end
    pivotIt = std::partition(begin, end-1, std::bind2nd(std::less<T>(), *(end-1)));
    std::iter_swap(end-1, pivotIt);  // Move pivot to its final place
    if (n == pivotIt - begin) {
      return pivotIt;
    } else if (n < pivotIt - begin) {
      end = pivotIt;
    } else {
      n -= pivotIt+1 - begin;
      begin = pivotIt+1;
    }
  }
}
 
int main() {
	int array[] = {9, 8, 7, 6, 5, 0, 1, 2, 3, 4}, c = sizeof(array)/sizeof(*array);
	std::srand(std::time(NULL));
    for (int i = 0; i < 10; i++) {
    std::cout << *select(array, array + c, i);
    if (i < 9) std::cout << " ";
  }
  std::cout << std::endl;
  return 0;
}