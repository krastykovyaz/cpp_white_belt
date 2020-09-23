#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool check(map <string, vector <char>> &ch, const vector <string> words){
    map <char, int> counter_1;
    map <char, int> counter_2;
    // counter_1.clear();
    // counter_2.clear();
    // cout << counter_1.size() << " " << counter_2.size() << endl;
    bool flag = false;
    for (const string &word : words){
        int i = 0;
        for (const char &c : word){
            // ch[word].push_back(c);
            // cout << ch[word][i] << endl;
            if (flag){
                ++counter_2[c];
            }
            else{
                ++counter_1[c];
            }
            i++;
        }
        // cout << "---\n";
        flag = true;
    }
    // cout << counter_1.size();
    // cout << counter_2.size();
    if (counter_1.size() == counter_2.size() && equal(counter_1.begin(), counter_1.end(), counter_2.begin()))
    {
        return true; 
    }
    // for (const auto &[key, value] : counter_1){
    //     cout << key << " : " << value << endl;
    // }
    // for (const auto &[key, value] : counter_2){
    //     cout << key << " : " << value << endl;
    // }
    return false;
}

void print_dict(const map <string, vector <char>> ch)
{
    for (const auto &key : ch){
        cout << key.first << endl;
        for (const auto &value : ch){
            cout << value.first << " = "<< endl;
        }
    }
}

int main(){
    int quantity;
    vector <string> words;
    map <string, vector <char>> ch;
    vector <string> result;
    cin >> quantity;
    for(int i = 0; i < quantity; i++){
        string first, second;
        cin >> first;
        cin >> second;
        // first = "ras";
        // second = "sar";
        words.push_back(first);
        words.push_back(second);
        if (check(ch, words)){
            result.push_back("YES");
        }
        else{
            result.push_back("NO");
        }
        words.clear();
    }
    // print_dict(ch);
    for (const auto &ind : result){
        cout << ind << endl;
    }
    return 0;
}
