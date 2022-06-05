#include <iostream>
#include <stack>
using namespace std;
  
int main()
{
  
    stack <int> A;
    
    cout << "is empty?" << A.empty() << endl;

    A.push(10);
    A.push(99);
    cout << "A.size = " << A.size() << endl;
    cout << "A.top() = " << A.top() << endl;
    A.pop();
    A.pop();
    cout << "is empty?" << A.empty() << endl;    

    return 0;
  
}