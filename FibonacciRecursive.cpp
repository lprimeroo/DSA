#include <iostream>
 
int fib(int n){
	switch(n){
		case 0:
			return 0;
		case 1:
			return 1;
		default:
			return fib(n-1) + fib(n-2);
	}
 
}
 
int main() {
	for(int i = 0; i<10; i++){
		std::cout << fib(i);
	}
	return 0;
}
