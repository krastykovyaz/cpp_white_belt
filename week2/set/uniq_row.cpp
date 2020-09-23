#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string>v;
    string word;
    int n;
    cin >> n;
    for (int i=0; i < n; ++i){
        cin >> word;
        v.push_back(word);
    }
    // cout << v.size() <<endl;
    set<string> s(begin(v), end(v));
    cout << s.size() <<endl;
    return 0;
}