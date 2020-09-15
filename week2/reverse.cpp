//Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector <int> &v){
    vector <int> new_v = {};
    int size = v.size();
    for (int i = v.size() - 1; i >= 0; --i)
    {
        // cout << v[i] << " ";
        v.push_back(v[i]);
    }
    v.erase(v.begin() + 0, v.begin() + size);
}


int main(){
    vector <int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (auto n : numbers){
        cout << n << " ";
    }
    return 0;
}