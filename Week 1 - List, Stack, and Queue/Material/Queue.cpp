#include <iostream>
#include <queue>
using namespace std;
  
int main()
{
  
    queue <int> A;
    
    cout << "is empty?" << A.empty() << endl;

    A.push(10);
    A.push(99);
    cout << "A.size setelah push = " << A.size() << endl;
    cout << "A.front() = " << A.front() << endl;
    cout << "A.back() = " << A.back() << endl;
    A.pop();
    A.pop();

    cout << "is empty?" << A.empty() << endl;    

    return 0;
  
}