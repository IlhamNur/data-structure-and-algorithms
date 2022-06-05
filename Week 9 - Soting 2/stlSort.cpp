#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int data[] = {9,1,2,8,7,3,4,5,6,0};
	vector<int> v(data, data + 10);
	sort(v.begin(), v.begin() + 5);
	
	for(int i=0; i<10; i++){
		cout<<v[i]<<" ";
	}
}
