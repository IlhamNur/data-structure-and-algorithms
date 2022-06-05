#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
int eraseAT(string str) {
	string acc;
	bool a, b;
	int x = 0;
	if (str.length() == 0)
		return 0;
	for (int i = 0; i < str.length(); i++) {	
		if (str[i] == '[' || str[i] == ':' || str[i] == '|') {
			if (str[i] == '[') {
				acc.push_back(str[i]);
				a = true;
			} 
			else if (str[i] == ':' && a) {
				if (str[i] == ':' && acc[acc.length() - 1] == ':') {
					acc.pop_back();
					b = false;
				} 
				else {	
					acc.push_back(str[i]);
					b = true;
				}
			}
			else if (str[i] == '|' && b) {} 
			else x++;
		} 
		else if (str[i] == ']') {
			if (acc.length() == 0)
				x++;
			else {
				acc.pop_back();
				a = false;
			}
		} 
		else x++;
	}
	if (acc.length() == 0) return x;
	else return -1;
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < str.length(); j++)
			for (int k = 0; k < str.length(); k++)
				str[i] = str[k];
	return 0;
}

int main () {
	int n=100000;
	string best = "", worst = "", random = "";
	
	for (int i=0; i<n; i++) {
		best.push_back('p');
	}
	for (int i=0; i<n; i++) {
		char symbol[] = {'[', ':'};
		worst.push_back(symbol[rand() % 2]);
	}
	for (int i=0; i<n; i++) {
		char symbol[] = {'['};
		random.push_back(symbol[rand() % 5]);
	}
	
	cout << "algoritma-3.cpp\n";
	{
		cout << "\nbest case\n";
		auto t0 = high_resolution_clock::now();
		eraseAT(best);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	{
		cout << "\nworst case\n";
		auto t0 = high_resolution_clock::now();
		eraseAT(worst);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	{
		cout << "\nrandom case\n";
		auto t0 = high_resolution_clock::now();
		eraseAT(random);
		auto t1 = high_resolution_clock::now();
		auto dt = t1 - t0;
		long long dtms = duration_cast<microseconds>(dt).count();
		cout << "durasi " << dtms << " microseconds\n";
	}
	
	return 0;
}

