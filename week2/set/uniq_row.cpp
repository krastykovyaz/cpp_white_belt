// Дан набор строк. Найдите количество уникальных строк в этом наборе.

// Формат ввода

// Сначала вводится количество строк N, затем — сами N строк, разделённые символом перевода строки. Все строки состоят лишь из латинских букв, цифр и символов подчёркивания.

// Формат вывода

// Выведите единственное целое число — количество уникальных строк в данном наборе.
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