#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void Print(vector<string>v, vector<double>d, int width){
    cout << left;
    cout << fixed << setprecision(3);
    for (const auto &dob : d){
        cout << setw(width) << dob;
    }
    cout << endl << setfill('.');
    for (const auto &str : v){
        cout << setw(width) << str;
    }
}

int main(){
    vector<string>v = {"a", "b", "c"};
    vector <double>d = {1, 200, 0.0000003};
    Print(v, d, 10);
    return 0;
}