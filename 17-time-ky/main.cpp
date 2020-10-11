#include <iostream>
using namespace std;

template<typename  T> 
void swap2(T& t1, T& t2) {
    T tmpT;
    tmpT = t1;
    t1 = t2;
    t2 = tmpT;
}




int main(int argc, char const *argv[])
{
    int x1=10, x2=20;
    cout << x1 << ' ' << x2 << endl;
    swap2(x1, x2);
    cout << x1 << ' ' << x2 << endl;
    
    return 0;
}
