#include <iostream>
#include <set>
#include <map>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set <string> s;
    for (const auto& [key, value] : m)
    {
        // cout << " " << key << value << endl;
        s.insert(value);   
    }
    return s;

}

int main(){
    map<int, string> m ={
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}};
    BuildMapValuesSet(m);
    return 0;
}