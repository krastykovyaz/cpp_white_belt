#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    vector <int> a = {3, 4, 2, 1};
    int sum = 0;
    for (auto i : a){
        sum += i;
    }
    cout << sum << endl;
    map<string, int> b = {{"a", 1}, {"b", 2}, {"c", 3}};
    int addit = 0;
    string s;
    for (auto i : b){
        addit += i.second;
        s += i.first;
    }
    cout << "str = " << s << endl;
    cout << "num = " << addit << endl;
    return 0;
}