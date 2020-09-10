#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s = "Hello";
    string t = s;
    t += ", world";
    cout << "s = " << s <<endl;
    cout << "t = " << t <<endl;
    vector <string> w = {"Hello ","world ", "again"};
    vector <string>v;
    v = w;
    v[0] = "Bye ";
    cout << w[0] << w[1] <<endl;
    cout << v[0] << v[1] <<endl;
}