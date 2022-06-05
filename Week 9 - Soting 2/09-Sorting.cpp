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
	}
}

// Insertion Sort //

void insertionsort(int *a, int n) {
	for (int i = 1; i < n; i ++) {
		int temp = 0;
		for (int j = i; j > 0; j --) {
			if (a[j - 1] <= a[j])
				break;
			temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
		}
	}
}

// Quicksort //

int qs_partition(int *a, int lo, int hi);

void quicksort(int *a, int lo, int hi) {
	if (lo >= hi) return;
	int p = qs_partition(a, lo, hi);
	quicksort(a, lo, p);
	quicksort(a, p + 1, hi);
}

int qs_partition(int *a, int lo, int hi) {
	int p = a[(lo + hi) / 2];
	int i = lo - 1;
	int j = hi + 1;
	while (true) {
		do i ++; while (a[i] < p);
		do j --; while (a[j] > p);
		if (i >= j) return j;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

// Merge Sort //

void ms_split(int *b, int p, int r, int *a);
void ms_merge(int *b, int p, int q, int r, int *a);

void mergesort(int *a, int n) {
	int b[n];
	for (int i = 0; i < n; i ++)
		b[i] = a[i];
	ms_split(b, 0, n, a);
	for (int i = 0; i < n; i ++)
		a[i] = b[i];
}

void ms_split(int *b, int p, int r, int *a) {
	if (r - p < 2)
		return;
	int q = (p + r) / 2;
	ms_split(a, p, q, b);
	ms_split(a, q, r, b);
	ms_merge(b, p, q, r, a);
}

void ms_merge(int *b, int p, int q, int r, int *a) {
	int i = p;
	int j = q;
	for (int k = p; k < r; k ++) {
		if (i < q && (j >= r || a[i] <= a[j]))
			b[k] = a[i ++];
		else
			b[k] = a[j ++];
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
	int arr[5][n]; 
	for (int i = 0; i < n; i ++)
		arr[0][i] = (unsigned int)rd() >> 24 + 1;
	// Buat salinan larik.
	for (int j = 1; j < 5; j ++)
	for (int i = 0; i < n; i ++)
		arr[j][i] = arr[0][i];
	std::cout << "Isi sebelum pengurutan" << std::endl << "  ";
	printArr(arr[0], n);
	std::cout << "Quicksort" << std::endl << "  ";
	quicksort(arr[3], 0, n - 1);
	printArr(arr[3], n);
	std::cout << "Merge Sort" << std::endl << "  ";
	mergesort(arr[4], n);
	printArr(arr[4], n);
}
