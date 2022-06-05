#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void HOME(int arr[], int n){
	int i, key, j;
	for(i=1; i<n; i++){
		key = arr[i];
		j = i - 1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main () {
	int n=10000;
	int best[n], worst[n], random[n];
	
	for (int i=0; i<n; i++) best[i] = i;
	for (int i=0; i<n; i++) worst[i] = n - i;
	for (int i=0; i<n; i++) random[i] = rand() % n;
	
	cout << "algoritma-2.cpp\n";
	{
		cout << "\nbest case\n";
		auto t0 = high_resolution_clock::now();
		HOME(best, n);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	{
		cout << "\nworst case\n";
		auto t0 = high_resolution_clock::now();
		HOME(worst, n);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	{
		cout << "\nrandom case\n";
		auto t0 = high_resolution_clock::now();
		HOME(random, n);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	
	return 0;
}
