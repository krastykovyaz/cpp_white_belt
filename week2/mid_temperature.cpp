#include <iostream>
#include <vector>
using namespace std;

void ChooseVector(const vector<int> &v, int middle)
{
    int i = 0;
    for (auto nums : v){
        if (nums > middle){
            i++;
        }
    }
    cout << i << endl;
    int idx = 0;
    for (auto nums : v){
        if (nums > middle){
            cout << idx << " ";
        }
        idx++;
    }
}

int main(){
    int n, number, total, middle;
    cin >> n;
    total = 0;
    vector <int> v;
    for (int i = 0; i < n; ++i){
        cin >> number;
        v.push_back(number);
        total += number;
    }
    middle = total / n;
    ChooseVector(v, middle);
    return 0;
}