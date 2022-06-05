#include<iostream>
using namespace std;
int deretAritmatika(int n){
	if(n==1){
		return 1;
	}
	
	return n+deretAritmatika(n-1);
}

int factorial(int n){
	if(n==0){
		return 1;
	}
	
	if(n==1){
		return 1;
	}
	int result = n*factorial(n-1);
	cout<<"Hasil ke "<<n<<" = "<<result<<endl;
	return result;
}

int fibonacci(int n){
	if(n==0){
		return 0;
	}
	
	if(n==1 || n==2){
		return 1;
	}
	int result = fibonacci(n-1)+fibonacci(n-2) ;
	cout<<"Hasil deret fibonacci ke "<<n<<" = "<<result<<endl;
	return result;
}

int main(){
	cout<<fibonacci(7)<<endl;
}
