#include <bits/stdc++.h>

using namespace std;

// n is the number of elements
// v is the vector
void combSort(int* v, int n) {
	// Initially the gap is n
	int gap = n;
	bool moved = true;

	while (moved == true || gap > 1) {
		// Calculate the gap
		gap = (gap * 10) / 13;
		if (gap < 1) {
			gap = 1;
		}

		moved = false;
		
		for (int i = 0; i < n - gap; i++) {
			if (v[i] > v[i + gap]) {
				swap(v[i], v[i + gap]);
				moved = true;
			}
		}
	}
}

// Printing the vector
void print(int* v, int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main() {
	int *v, n;

	cout << "Give the number of elements: ";
	cin >> n;

	cout << "Give the numbers ";
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	combSort(v, n);

	print(v, n);
}
