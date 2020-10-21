// Итак, теперь у нас с вами есть полноценный тип для представления обыкновенных дробей: класс Rational интегрирован в язык с помощью перегрузки операторов и не позволяет выполнять некорректные операции за счёт выбрасывания исключений. Давайте на основе класса Rational создадим простой калькулятор для обыкновенных дробей.
// Вам надо написать программу, которая считывает из стандартного ввода одну строку в формате ДРОБЬ_1 операция ДРОБЬ_2. ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где X — целое, а Y — целое неотрицательное число. операция — это один из символов '+', '-', '*', '/'.
// Если ДРОБЬ_1 или ДРОБЬ_2 является некорректной обыкновенной дробью, ваша программа должна вывести в стандартный вывод сообщение "Invalid argument". Если считанная операция — это деление на ноль, выведите в стандартный вывод сообщение "Division by zero". В противном случае выведите результат операции.
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
        // cout << denominator << " <-" << endl;
        if (denominator == 0){
            throw invalid_argument("Invalid argument");
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
    if (rhs.Numerator() == 0){
        throw domain_error("Division by zero");
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

Rational ParseRationals(string &rationals){
    Rational r;
    stringstream ss(rationals);
    int n, d;
    ss >> n;
    ss.ignore(1);
    ss >> d;
    r = {n, d};
    return r;
}

void PrintRationals(const Rational & r1,const Rational & r2){
    cout << r1.Numerator() << "/" << r1.Denominator() << " " << r2.Numerator() << "/" << r2.Denominator() << endl;
}

void  Culc(const Rational &r1, const Rational &r2, const string & sign){
    if (sign == "+")
        cout << r1 + r2;
    else if (sign == "-")
        cout << r1 - r2;
    else if (sign == "*")
        cout << r1 * r2;
    else
    {
        try {
            auto x = r1 / r2;
        } catch (domain_error& ex) {
            cout << ex.what();
        }
    }
}

int main() {
    Rational r1, r2;
    string rational1, rational2, sign;
    cin >> rational1;
    cin >> sign;
    cin >> rational2;
    try{
        r1 = ParseRationals(rational1);
        r2 = ParseRationals(rational2);
    }catch (invalid_argument& ex){
        cout << ex.what() << endl;
        return 1;
    }
    Culc(r1, r2, sign);
    cout << endl;
    return 0;
}