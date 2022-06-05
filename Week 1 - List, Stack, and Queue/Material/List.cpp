#include <iostream>
#include <list>
using namespace std;
  
int main()
{
  
    list <int> A(4, 100); //[100, 100, 100, 100]
    
    cout << "A.front() = " << A.front() << endl;
    cout << "A.back() = " << A.back() << endl;
    cout << "A.size() = " << A.size() << endl;

    A.push_back(15); //[100, 100, 100, 100, 15]
    cout << "A.back setelah A.push_back = " << A.back() << endl;

    A.push_front(15);//[15, 100, 100, 100, 100, 15]
    cout << "A.front setelah A.push_front = " << A.front() << endl;

    A.pop_front();//[100, 100, 100, 100, 15]
    cout << "A.front setelah A.pop_front = " << A.front() << endl;

    A.pop_back();//[100, 100, 100, 100]
    cout << "A.back setelah A.pop_back = " << A.back() << endl;

    A.remove(100);//[]
    cout << "is empty? " << A.empty() << endl;
    cout << "size? " << A.size() << endl;
    
    return 0;
  
}