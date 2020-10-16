#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string year, month, day;
    int y = 0, m = 0, d = 0;
    ifstream input("bday.txt");
    if (input){
        input >> d;
        input.ignore(1);
        input >> m;
        input.ignore(1);
        input >> y;
        input.ignore(1);
        // getline(input, day, '-');
        // getline(input, month, '-');
        // getline(input, year);
    }
    // cout << year << ' ' << month << ' ' << day << endl;
    cout << y << ' ' << m << ' ' << d << endl;
    return 0;
}