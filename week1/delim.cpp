#include <iostream>
#include <vector>
using namespace std;

int main(){
    double a = 11;
    int b = 3;
    int c = 5;
    int plus_prefix = ++c;
    int plus_postfix = c++;
    cout << "plus_prefxix = " << plus_prefix << endl;
    cout << "plus_postfix = " << plus_postfix << endl;
    c = 5;
    int minus_prefix = --c;
    int minus_postfix = c--;
    cout << "minus_postfix = " << minus_postfix << endl;
    cout << "minus_prefxix = " << minus_prefix << endl;
    cout << "c = " << c << endl;
    cout << a / b;
    c = 1;
    ++c;
    c *= 5;
    c -= 3;
    cout << "ex = " << c++;
    return 0;
}