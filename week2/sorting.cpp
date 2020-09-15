#include <iostream>
#include <vector>
using namespace std;

void Sort_num(vector <int > &n){
    sort(begin(n), end(n));
}

int main(){
    vector<int> nums = {1, 2, 3, 9, 8, 7};
    Sort_num(nums);
    for (auto i : nums){
        cout << i << " ";
    }
    return 0;
}