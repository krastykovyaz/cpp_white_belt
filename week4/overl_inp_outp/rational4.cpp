#include <iostream>
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
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        // PrintVector(v);
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}