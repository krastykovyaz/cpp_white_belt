#include <iostream>
using namespace std;

struct Day{
    int day;
    explicit Day(int value){
        day = value;
    }
};

struct Month
{
    int month;
    explicit Month(int value){
        month = value;
    }
};

struct Year{
    int year;
    explicit Year(int value){
        year = value;
    }
};


struct Date
{
    int day;
    int month;
    int year;
    Date(Day new_day, Month new_month, Year new_year){
        day = new_day.day;
        month = new_month.month;
        year = new_year.year;
    }
};

void PrintDate(const Date& date){
    cout << date.day << " : " << date.month << " : " << date.year << endl;
}

int main(){
    Date date = {Day{10}, Month{11}, Year{12}};
    PrintDate(date);
    return 0;
}