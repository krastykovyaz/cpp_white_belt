#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream input("gw.txt");
    string line;
    if (input){
        while (getline(input, line)){
            cout << line << endl;
        }
    }
    else
        cout << "Error" << endl;
    return 0;
}