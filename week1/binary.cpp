// На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, i, number;
    cin >> n;
    vector <int> v = {};
    while (n > 0)
    {
        number = n % 2;
        n = n / 2;
        v.push_back(number);
    }
    i = v.size() - 1;
    while (i >= 0)
    {
        cout << v[i];
        i--;
    }
    return 0;
}