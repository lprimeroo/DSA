#include <iostream>

using namespace std;

int main() {
	int n;

	cout << "Give the number: ";
	cin >> n;

	cout << "The factors of " << n << " are: 1, ";
	for (int i = 2; i < n/2 + 1; i++) {
		if (n % i == 0) {
			cout << i << ", ";
		}
	}
	cout << n << "\n";

	return 0;
}
