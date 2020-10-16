#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Duration{
    int hours, minutes;
    Duration(int h = 0, int m = 0){
        hours = h;
        minutes = m;
    }
};

ostream& operator<<(ostream& stream, const Duration& d){
    stream << setfill('0');
    stream << setw(2) << d.hours << ":"  << setw(2) << d.minutes;
    return stream;
}

istream& operator>>(istream& stream, Duration& d){
    stream >> d.hours;
    stream.ignore(1);
    stream >> d.minutes;
    return stream;
}

int main(){
    stringstream dur_ss("2, 50");
    Duration d;
    dur_ss >> d;
    cout << d << endl;
}