// В этом задании вам предстоит написать две небольшие программы. Каждый пункт - отдельная задача, решение отправляйте в поле с соответствующим номером.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream input("input.txt");
    string line;
    if (input)
    {
        while (getline(input, line)){
            cout << line << endl;
        }
    }
    return 0;
}