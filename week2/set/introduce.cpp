#include <iostream>
#include <set>
#include <vector>
using namespace std;

void print_set(const set<string> &s)
{
    for (const auto &item : s){
        cout << item << endl;
    }
}

int main(){
    vector<string>v = {"March", "July", "January"};
    set<string> s(begin(v), end(v));
    print_set(s);
    return 0;
}