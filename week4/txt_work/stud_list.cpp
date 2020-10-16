// Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения. Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.

// Формат ввода

// Первая строка содержит одно целое число N от 0 до 10000 — число студентов.

// Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов — имя и фамилию очередного студента, и три целых числа от 0 до 1000000000 — день, месяц и год рождения.

// Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.

// Следующие M строк содержат строку длиной от 1 до 15 символов — запрос, и целое число от 0 до 1000000000 — номер студента (нумерация начинается с 1).

// Формат вывода

// Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.

// Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.

// Для остальных запросов выведите bad request.
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