#include<iostream>
#include<time.h>
#include<chrono>
#include <array>
using namespace std;
using namespace std::chrono;
void swap(int * xp, int * yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void STAY(int arr[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]) swap(&arr[j], &arr[j+1]);
		}
	}
}

int main () {
	int n=10000;
	int best[n], worst[n], random[n];
	
	for (int i=0; i<n; i++) best[i] = i;
	for (int i=0; i<n; i++) worst[i] = n - i;
	for (int i=0; i<n; i++) random[i] = rand() % n;
	
	cout << "algoritma-1.cpp\n";
	{
		cout << "\nbest case\n";
		auto t0 = high_resolution_clock::now();
		STAY(best, n);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	{
		cout << "\nworst case\n";
		auto t0 = high_resolution_clock::now();
		STAY(worst, n);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	{
		cout << "\nrandom case\n";
		auto t0 = high_resolution_clock::now();
		STAY(random, n);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	
	return 0;
}
