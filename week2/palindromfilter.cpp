// Напишите функцию, которая

// называется PalindromFilter
// возвращает vector<string>
// принимает vector<string> words и int minLength и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
// Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string word){
    for (int i = 0; i < word.size(); i++){
        if (word[i] != word[word.size() - i - 1]){
            return false;
        }
    }
    return true;
}

vector <string> PalindromFilter(vector <string> str, int num){
    int i = 0;
    vector <string> new_str = {};
    for (auto w : str){
        if (w.size() < num){
            cout << "first = "<< w << endl;
            continue;

        }
        else{
            if (IsPalindrom(w)){
                new_str.push_back(w);
            }
            else{
                continue;

            }
        }
        i++;
    }
    for (auto z : new_str){
    }
    return str;
}

int main(){
    vector <string> input = {"abacaba", "weew", "bro", "code"};
    int min_len = 4;
    input = PalindromFilter(input, min_len);
    cout << input.size();
    return 0;
}