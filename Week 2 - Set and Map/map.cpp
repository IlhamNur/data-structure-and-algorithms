#include<iostream>
#include<map>
using namespace std;
int main(){
	map<int, string> rank;
	rank.insert(pair<int,string>(1, "ilham"));
	rank.insert(pair<int,string>(3, "nur"));
	rank.insert(pair<int,string>(2, "romdoni"));
	
	map<int, string>::iterator itr;
	for(itr = rank.begin(); itr!= rank.end(); itr++){
		cout<<itr->first<<" "<<itr->second<<endl;
	}cout<<endl;
	
}
