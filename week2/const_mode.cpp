//const — это специальный модификатор типа, который запрещает изменять переменные этого типа, объявленные с ключевым словом const. И собственно, это основная, основное назначение — это защита от случайного изменения переменных.
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    const vector <string> hi = {"hello"};
    // hi[0][0] = 'H';
    cout << hi[0] << endl;
    const string s = "Hello";
    cout << s.size() << endl;
    // s += ", world";
    string t = s + "!";
    cout << t;
    const int x = 5;
    // x = 6;
    // x += 4;
    cout << x << endl;
    return 0;
}
