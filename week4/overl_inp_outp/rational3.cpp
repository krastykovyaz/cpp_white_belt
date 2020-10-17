

// В этой части вам нужно реализовать операторы ввода и вывода для класса Rational. В результате у вас должен работать
#include <iostream>
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
        // cout << num << " " << den << endl;
    // }
    return is;
}
// Реализуйте для класса Rational операторы * и /
int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }
    {
        istringstream input("");
        Rational r (2, 3);
        input >> r;
        bool equal = r == Rational(2, 3);
        if (!equal) {
            cout << "кривое чтение из пустого потока" << endl;
            return 12;
        }
    }
    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        // cout << r1 << endl;
        // cout << r2;
        // cout << r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;
            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}