#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Print_words(vector<string> words){
    for (auto w : words){
        cout << w << " ";
    }
}

bool Contain(vector <string> str, string word){
    for (auto w : str){
        if (w == word){
            return true;
        }
    }
    return false;
}

int main(){
    cout << Contain({"water", "fire", "air"}, "fire") << endl;
    Print_words({"water", "fire", "air"});
    return 0;
}