// Реализуйте для класса Rational операторы ==, + и - так, чтобы операции с дробями можно было записывать естественным образом. Например, следующий код должен быть валидным:
// const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
// if (r == Rational(7, 12)) {
//   cout << "equal";
// }
// Гарантируется, что во всех тестах, на которых будет тестироваться ваша реализация, числители и знаменатели ВСЕХ дробей (как исходных, так и получившихся в результате соответствующих арифметических операций) будут укладываться в диапазон типа int.
#include <iostream>
#include <numeric>
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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }
    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }
    {
        Rational a(1, 3);
        Rational b(2, 3);
        Rational c = a + b;
        bool equal = c == Rational(1, 1);
        if (!equal){
            cout << "Error" << endl;
            return 3;
        }
    }
    cout << "OK" << endl;
    return 0;
}
