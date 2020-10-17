// Аналогично предыдущей части, реализуйте операторы * и /. Например, следующий код должен быть валидным:
// const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
// if (r == Rational(2, 3)) {
//   cout << "equal";
// }
// Как и в предыдущем случае, гарантируется, что во всех тестах, на которых будет тестироваться ваша реализация, числители и знаменатели ВСЕХ дробей (как исходных, так и получившихся в результате соответствующих арифметических операций) будут укладываться в диапазон типа int.

// Кроме того, гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет выполняться деление на ноль.
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
// Реализуйте для класса Rational операторы * и /

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
