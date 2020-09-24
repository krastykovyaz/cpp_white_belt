// Два слова называются синонимами друг друга, если они имеют похожие значения. Реализуйте следующие операции над словарём синонимов:

// ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
// COUNT word — узнать количество синонимов слова word.
// CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами. Слова word1 и word2 считаются синонимами, если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.
// Замечание

// Для упрощения, будем считать, что синонимы не обладают транзитивностью, то есть, если A - синоним B, а B - синоним C, то из этого НЕ следует, что A - синоним C.

// Формат ввода

// Сначала вводится количество запросов Q, затем Q строк с описаниями запросов. Гарантируется, что в каждом запросе CHECK и ADD слова word1 и word2 различны. Все слова состоят лишь из латинских букв, цифр и символов подчёркивания.

// Формат вывода

// Для каждого запроса в соответствующей строке выведите ответ на него:

// В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.
// В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, и NO в противном случае.
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