#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    vector<string> a = {"fire","water"};
    vector<string> b = {"fog", "ice"};
    map<string, int> c;
    c["one"] = 1;
    map<string, int> d;
    if (c == d){
        cout << "c & d equal" << endl;
    }
    else{
        cout << "c & d not equal" << endl;}
    if (a == b){
        cout << "a & b equal" << endl;
    }
    else{
        cout << "a & b not equal" << endl;
    }
}