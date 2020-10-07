#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

string CharToLower(string str){
    for (auto &i : str){
            i = tolower(i);
        }
        // cout << str << endl;
        return str;
}

int main(){
    int n;
    string exp;
    cin >> n;
    vector <string> a;
    for (size_t i = 0; i < n; i++)
    {
        cin >> exp;
        a.push_back(exp);
    }
    sort(begin(a), end(a), [](string &x, string &y){
        // cout << "x: " << x << "; y: " << y << '\n';
        // CharToLower(x);
        // CharToLower(y);
        return (CharToLower(x) < CharToLower(y)) ? 1 : 0;
    });
    for (auto const &i : a)
    {
        cout << i << " ";
    }
    return 0;
}