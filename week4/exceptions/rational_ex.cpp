// Вспомним класс Rational, который мы реализовали в задачах, посвящённых перегрузке операторов. Там специально говорилось, что в тестах объекты класса Rational никогда не создаются с нулевым знаменателем и никогда не выполняется деление на ноль. Настало время избавиться от этого ограничения и научиться обрабатывать нулевой знаменатель и деление на ноль. В этой задаче вам предстоит это сделать.

// Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал исключение invalid_argument, если знаменатель равен нулю. Кроме того, переделайте реализацию оператора деления для класса Rational так, чтобы он выбрасывал исключение domain_error, если делитель равен нулю.

#include <iostream>
#include <exception>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if (denominator == 0){
            throw invalid_argument("denominator");
        }
        int g = gcd(numerator, denominator);
        num = numerator / g;
        den = denominator / g;
        if (num == 0){
            den = 1;
        }
        if ((num > 0 && den < 0) || (den < 0 && num < 0)){
            num *= -1;
            den *= -1;
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return den;
    }

private:
    int num, den; 
    // Добавьте поля

};

// Реализуйте для класса Rational операторы ==, + и -
Rational operator+(const Rational& lhs,const Rational& rhs){
    int total_den = lhs.Denominator() * rhs.Denominator();
    int total_num = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
    return {total_num, total_den};
}

Rational operator-(const Rational& lhs,const Rational& rhs){
    int total_den = lhs.Denominator() * rhs.Denominator();
    int total_num = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
    return {total_num, total_den};}

bool operator==(const Rational lhs,const Rational rhs){
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
        return true;
    return false;
}

Rational operator*(const Rational& lhs,const Rational& rhs){
    int total_num = lhs.Numerator() * rhs.Numerator();
    int total_den = lhs.Denominator() * rhs.Denominator();
    return {total_num, total_den};
}

Rational operator/(const Rational& lhs,const Rational& rhs){
    if (rhs.Numerator() / rhs.Denominator() == 0){
        throw domain_error("devision by zero");
    }
    int total_num = lhs.Numerator() * rhs.Denominator();
    int total_den = lhs.Denominator() * rhs.Numerator();
    return {total_num,total_den};
}

ostream& operator<<(ostream & os, const Rational & r){
    os << r.Numerator() << "/" << r.Denominator();
    return os;
}

istream& operator>>(istream & is, Rational & r){
    int num = 0, den = 0;
    string str;
    if (is >> num && is.ignore(256, '/') && is >> den)
        r = {num, den};
    return is;
}

bool operator < (const Rational &rhs, const Rational &lhs) { 
    return (rhs.Numerator() / (double)rhs.Denominator()) < (lhs.Numerator() / (double)lhs.Denominator());
}

void PrintVector(const vector <Rational> &v){
    for(const auto & i : v){
        cout << i.Numerator();
    }
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }
    cout << "OK" << endl;
    return 0;
}