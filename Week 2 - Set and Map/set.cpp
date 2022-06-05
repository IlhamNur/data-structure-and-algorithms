#include<bits/stdc++.h>
#include<set> //himpunan variabel tidak sama
using namespace std;
int main(){
	set<int> s;
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.erase(2);
	
	cout<<"Element set s = ";
	for(auto it :s){
		cout<<it<<" ";
	} cout<<endl;
	return 0;
}
