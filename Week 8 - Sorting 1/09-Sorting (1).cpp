#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>

// Bubble Sort //

void bubblesort(int *a, int n) {
	bool swapped = true;
	int temp = 0;
	do {
		swapped = false;
		for (int i = 1; i < n; i ++) {
			if (a[i - 1] > a[i]) {
				temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
				swapped = true;
			}
		}
		for (int i = 0; i < n; i ++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
	} while (swapped);
}

// Selection Sort //

void selectionsort(int *a, int n) {
	for (int i = 0; i < n; i ++) { 
		int jMin = i;
		for (int j = i + 1; j < n; j ++)
			if (a[j] < a[jMin])
				jMin = j;
		if (jMin != i) {
			int temp = a[jMin];
			a[jMin] = a[i];
			a[i] = temp;
		}
		for (int i = 0; i < n; i ++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
	}
}

// Insertion Sort //

void insertionsort(int *a, int n) { // n^2
	for (int i = 1; i < n; i ++) { // n
		int temp = 0;
		for (int j = i; j > 0; j --) { // n
			if (a[j - 1] <= a[j])
				break;
			temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
		}
		for (int i = 0; i < n; i ++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
	}
}

// Cetak isi larik.
void printArr(int *a, int n) {
	for (int i = 0; i < n; i ++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

int main() {
	std::random_device rd;
	int n = 16;
	int arr[3][n]; // {[n angka], [n angka], [n angka]}
	for (int i = 0; i < n; i ++)
		arr[0][i] = (unsigned int)rd() >> 24 + 1;
	// Buat salinan larik.
	for (int j = 1; j < 5; j ++)
	for (int i = 0; i < n; i ++)
		arr[j][i] = arr[0][i];
	std::cout << "Isi sebelum pengurutan" << std::endl << "  ";
	printArr(arr[0], n);
	std::cout << "Bubble Sort" << std::endl << "  ";
	bubblesort(arr[0], n);
	std::cout << "*****************************************************" << std::endl;
	printArr(arr[0], n);
	std::cout << "Selection Sort" << std::endl << "  ";
	selectionsort(arr[1], n);
	std::cout << "*****************************************************" << std::endl;
	printArr(arr[1], n);
	std::cout << "Insertion Sort" << std::endl << "  ";
	insertionsort(arr[2], n);
	std::cout << "*****************************************************" << std::endl;
	printArr(arr[2], n);
	
}
