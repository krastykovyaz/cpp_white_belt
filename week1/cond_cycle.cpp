#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int x = 4;
    int y = 5;
    if (x == y){
        cout << "equal" << endl;
    } else
        cout << "not equal" << endl;
    vector <int> nums = {1, 2, 3};
    for (int i : nums){
        cout << i << endl;
    }
    int n = 5;
    int sum = 0;
    for (int i = 1; i <= n; ++i){
        sum += i;
    }
    cout << sum;
    return 0;
}