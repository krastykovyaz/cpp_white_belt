#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

void print_map(const map <int, set<string>>& m){
    for (const auto &item : m){
        cout << item.first << endl;
        // cout << item.second.size() << endl;
        for (const auto & i : item.second){
            cout << " " << i << endl;
        }
    }
}

void count(const map <int, set<string>>& m, const string &w){
    int res = 0;
    set <string>s = {w};
    for (const auto &item : m){
        // cout << w;
        if (item.second.count(w) == 1){
            for (const auto &i : item.second){
                s.insert(i);
            }
        }
        res += item.second.count(w);
    }

        cout << s.size() - 1 << endl;
}

void check(const map <int, set<string>>& m, set<string> check_v){
    bool flag = false;
    for (const auto & item : m){
        if (check_v == item.second){
            cout << "YES" << endl;
            flag = true;
            break;
        }
    }
    if (!flag){
        cout << "NO" << endl;
    }
}

int main(){
    int n, idx;
    set <string> dictinary;
    // vector <set<string>> sinon;
    set<string> check_v;
    map <int, set<string>> m; 
    string query, words;
    cin >> n;
    idx = 0;
    for (int i = 0; i < n; ++i){
        cin >> query;
        if (query == "ADD"){
            idx++;
            for (int j = 0; j < 2; ++j){
                cin >> words;
                dictinary.insert(words);
            }
            m[idx] = dictinary;
        }
        else if (query == "COUNT"){
            cin >> words;
            // dictinary.count(words);
            count(m, words);
        }
        else if (query == "CHECK"){
            for (int m = 0; m < 2; ++m){
                cin >> words;
                check_v.insert(words);
            }
            check(m, check_v);
        }
        dictinary.clear();
        check_v.clear();
    }
    // print_map(m);
    return 0;
}