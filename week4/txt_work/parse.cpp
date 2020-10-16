// В файле input.txt записаны вещественные числа, по одному на строчку. На стандартный вывод напечатайте эти числа в том же порядке, по одному на строке, но сделайте так, чтобы у каждого из них было ровно три знака после десятичной точки.
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