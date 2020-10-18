#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <exception>
using namespace std;


struct Date{
    int year;
    int month;
    int day;
};

void EnsureNextSymbSkip(stringstream & stream){
    if (stream.peek() != '/'){
        stringstream ss;
        ss << "expected \"/\", but got: \"" << char(stream.peek()) << "\"";
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

Date ParseDate(const string& s){
    stringstream stream(s); //стороковый поток
    Date date;
    stream >> date.year;
    EnsureNextSymbSkip(stream);
    stream >> date.month;
    EnsureNextSymbSkip(stream);
    stream >> date.day;
    return date;
}


int main(){
    string str_date = "2020/10/18";
    try {
        Date date = ParseDate(str_date);
        cout << setw(2) << setfill('0') << date.day << '.' << setw(2) << setfill('0') << date.month << '.' << date.year << endl;
    } catch (exception & ex){
        cout << "Exception happens: " << ex.what() << endl;
    }
    return 0;
}