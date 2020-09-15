#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintVector(const vector<bool>& v) {
    int i = 0;
    for (auto s : v) {
        cout << i << ":" << s << endl;
        ++i;
  }
}

int main(){
    vector <bool> is_holiday(28, false);
    is_holiday[22] = true;
    is_holiday.resize(32);
    is_holiday.assign(32, false);
    is_holiday[15] = true;
    PrintVector(is_holiday);
    return 0;
}