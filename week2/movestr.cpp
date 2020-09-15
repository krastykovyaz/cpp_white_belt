//Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination, и дописывает все строки из первого вектора в конец второго. После выполнения функции вектор source должен оказаться пустым.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector <string> &sour, vector <string> &dest){
    for (auto word : sour){
        dest.push_back(word);
    }
    sour.clear();
}

int main(){
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    cout << source.size() << endl;
    for (auto w : destination){
        cout << w << endl;
    }
    return 0;
}