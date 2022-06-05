#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
    
    int n, input;
    map<string, string> cheat;
    map<string, string>::iterator itr;
    string x, y;
    
    cin >> n;
    
    while(n--) {
        cin >> input;
        if (input == 1) {
            cin >> x >> y;
            if (x.size() != 4 || y.size() > 100) {
                break;
            }
            else {
                itr = stadion.find(x) ;
                if (itr != stadion.end()) {
                    cout << "kursi sudah dipesan " << itr->second<< endl;
                }
                else {
                    stadion.insert(pair<string,string>(x, y));
                    cout << "kursi berhasil dipesan" << endl;
                }
            }
        }
        else {
            cin >> x;
            if (x.size()!= 4) {
                break;
            }
            else {
                itr = stadion.find(x);
                if (itr == stadion.end()) {
                    cout << "kursi masih kosong" << endl;
                }
                else {
                    cout << "kursi sudah dipesan " << itr->second << endl;
                }
            }
        }
    }
    return 0;
}
