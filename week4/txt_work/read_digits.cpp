#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    ifstream input("input.txt");
    double line;
    // cout << fixed << setprecision(3);
    if (input){
        while (input >> line)
        {
            cout << fixed << setprecision(3);
            cout << line << endl;
        }
    }
    return 0;
}