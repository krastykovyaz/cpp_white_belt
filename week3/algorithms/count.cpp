#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v = {6, 5, 3, 4, 2, 4};
    cout << count(begin(v), end(v), 4) << endl;
    vector <int> v_man;
    int n;
    for (int i = 0; i < 5; ++i){
        cin >> n;
        v_man.push_back(n);
    }
    int t = 3;
    cout << count_if(begin(v_man), end(v_man), [t](int x){
        if (x % 2 == 0 && x > t)
            return true;
        else
            return false;
        });
    cout << endl;
    return 0;
}