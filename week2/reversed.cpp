//Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v, в которой числа переставлены в обратном порядке.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> Reversed(const vector <int> &v){
    vector <int> new_v = {};
    int size = v.size();
    for (int i = v.size() - 1; i >= 0; --i)
    {
        // cout << v[i] << " ";
        new_v.push_back(v[i]);
    }
    return new_v;
}


int main(){
    vector <int> numbers = {1, 5, 3, 4, 2};
    vector <int> container;
    container = Reversed(numbers);
    for (auto n : container){
        cout << n << " ";
    }
    return 0;
}