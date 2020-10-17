#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Duration{
    int hours, minutes;
    Duration(int h = 0, int m = 0){
        int total = h * 60 + m;
        hours = total / 60;
        minutes = total % 60;
    }
};

Duration operator+(Duration& lhs, Duration& rhs){
    return {lhs.hours + rhs.hours, lhs.minutes + rhs.minutes};
}

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

bool operator<(const Duration& lhs, const Duration& rhs){
    if (lhs.hours == rhs.hours){
        return lhs.minutes < rhs.minutes;
    }
    return lhs.hours < rhs.hours;
}

void PrintVector(vector <Duration> &v){
    for (const auto& i : v){
        cout << i.hours << ":" << i.minutes << " ";
    }
    cout << endl;
}

int main(){
    stringstream dur_ss("2, 50"), dur_ss1("2, 10"), dur_ss2("10, 20");
    Duration d;
    Duration d1, d2;
    dur_ss >> d;
    dur_ss1 >> d1;
    dur_ss2 >> d2;
    vector<Duration> v = {d, d1, d2};
    cout << d1 + d2 << endl;
    PrintVector(v);
    sort(begin(v), end(v));
    PrintVector(v);
    cout << d << endl;
}