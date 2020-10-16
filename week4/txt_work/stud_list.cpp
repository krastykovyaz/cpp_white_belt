#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Student{
    string name;
    string surname;
    int day;
    int month;
    int year;
};


void PrintVector(const vector<Student> &students,string request, int k){
    if (request == "name"){
        for (const auto& student : students){
            if (!(--k)){
                cout << student.name<< ' ' << student.surname << endl;
            }
        }
    }
    else if (request == "date"){
        for (const auto& student : students){
            if (!(--k)){
                cout << student.day << '.' << student.month<< '.' << student.year << endl;
            }
        }
    }
    else{
        cout << "bad request" << endl;
    }
}

int main(){
    vector <Student> students;
    int num = 0, d = 0, m = 0, y = 0, k =0, num_req = 0;
    string n, s, request;
    cin >> num;
    for (int i = 0; i < num; ++i){
        cin >> n;
        cin >> s;
        cin >> d;
        cin >> m;
        cin >> y;
        students.push_back({n, s, d, m, y});
    }
    cin >> num_req;
    for (int i = 0; i < num_req; ++i){
        cin >> request;
        cin >> k;
        if (k > num || k < 1){
            cout << "bad request" << endl;
        }
        else{
            PrintVector(students, request, k);
        }
    }
    return 0;
}