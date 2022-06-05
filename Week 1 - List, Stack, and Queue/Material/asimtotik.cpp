#include<iostream>
#include<chrono>
using namespace std;

int fibonacciRecursif(int n){
	if(n==0){
		return 0;
	}
	
	if(n==1 || n==2){
		return 1;
	}
	int result = fibonacciRecursif(n-1)+fibonacciRecursif(n-2) ;
	return result;
}

int fibonacciFor(int n){
	if(n==1 ||n==2){
		return 1;
	}
	int temp, a=0,b=1,c;
	for(int i=0; i<n; i++){
		c = a+b;
		a = b;
		b = c;
	}
	return b;
}

int main(){
	auto t0 = chrono::high_resolution_clock::now();
	//cout<<fibonacciRecursif(10)<<endl;
	//cout<<fibonacciFor(3)<<endl;
	auto t1 = chrono::high_resolution_clock::now();
	auto dt = t1 - t0;
	long long dtms = chrono::duration_cast<chrono::microseconds>(dt).count();
	cout<<dtms<<" microsecond"<<endl;
}
