#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector <int> &v, string a){

    cout << a << " : ";
    for (auto const &i : v){
        cout << i << ' ';
    }
}

int main(){
    string a = "abc";
    string b = "bca";
    vector <int> v = {2, 4, 6, 3, 1};
    PrintVector(v, "init");
    sort(begin(v), end(v));
    cout << endl;
    PrintVector(v, "sort");
    cout << endl;
    cout << min(a, b) << endl;
    return 0;
}