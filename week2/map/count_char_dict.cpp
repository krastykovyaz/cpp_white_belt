#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){
    map<int, string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
    for (const auto &[key,value] : m){
        cout << key <<" " << value <<endl;
    }
    cout << "---------" << endl;
    m[2] = "two";
    m.erase(1);
    m[3] = "three";
    m.erase(4);
    m[5] = "five";
    cout << m.size() << endl;
    cout << "=================\n";
    vector<string> words = {"one", "two", "three"};
    map<string, int> counter;
    for (const string & word : words){
        if (counter.count(word) == 0){
            counter[word] = 1;
        }
        else
        {
            ++counter[word];
        }
    }
    for (const auto &[key, value] : counter){
        cout << key << value <<endl;
    }
    map<char, vector<string>> grouped_words;
    for (const string& word : words) {
        grouped_words[word[0]].push_back(word);
    }
    for (const auto& item : grouped_words) {
        cout << item.first << endl;
    for (const string& word : item.second) {
        cout << word << " ";
    }
    cout << endl;
    }                      
    return 0;
}