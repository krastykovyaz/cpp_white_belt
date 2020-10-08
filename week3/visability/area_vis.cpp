#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "Hello";
    {
        string s = "world";
        cout << s << endl;
    }
    cout << s << endl;
    return 0;
}