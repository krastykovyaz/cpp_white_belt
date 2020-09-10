#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    string str = "asdfghjasdfghjasdfghgfdsaaghjkla";
    for (int i = 0; i < str.size(); ++i){
        if (str[i] == 'a'){
            cout << i << endl;
        }
    }
    return 0;
}