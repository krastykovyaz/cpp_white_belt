// В этой задаче вам надо разработать класс для представления рациональных чисел и внедрить его в систему типов языка С++ так, чтобы им можно было пользоваться естественным образом. Задание состоит из нескольких частей. К каждой части приложен файл с заготовкой программы, который имеет следующую структуру

// #include <iostream>
// using namespace std;
// // Комментарии, которые говорят, что именно нужно реализовать в этой 
//     программе
// int main() {
//     // Набор юнит-тестов для вашей реализации
//     cout << "OK" << endl;
//     return 0;
// }
// Вам нужно, не меняя тело функции main, реализовать то, что предложено в комментариях, так, чтобы ваша программа выводила на экран сообщение OK. Функция main содержит ряд юнит-тестов, которые проверяют правильность вашей реализации. Если эти тесты находят ошибку в вашей реализации, то вместо OK программа выведет подсказку о том, что именно работает неправильно.

// Когда ваша программа начнёт выводить OK, можете отправлять свой файл на проверку. Ваша реализация будет тестироваться на другом, более полном наборе тестов. То есть, если ваша программа выводит OK, то это не даёт гарантии, что ваша реализация будет принята тестирующей системой. В случае неудачной посылки тестирующая система также выдаст вам подсказку о том, какая именно часть реализации работает неправильно.

// Внимательно изучите набор юнит-тестов для каждой заготовки решения. Тесты описывают требования, предъявляемые к вашей реализации, которые могут быть не указаны в условии задач

// На проверку можно отправлять весь файл с вашей реализацией: функцию main удалять из него не нужно.

// Часть 1

// В первой части Вам надо реализовать класс Rational, который представляет собой рациональное число вида p/q, где p — целое, а q — натуральное и диапазоны возможных значений p, q таковы, что могут быть представлены типом int. При этом, класс Rational должен иметь следующий интерфейс:

// class Rational {
// public:
//   Rational();
//   Rational(int numerator, int denominator);
//   int Numerator() const;
//   int Denominator() const;
// };
// Класс Rational должен гарантировать, что p/q — это несократимая дробь. Например, код

// Rational r(4, 6);
// cout << r.Numerator() << '/' << r.Denominator();
// должен выводить «2/3» — именно поэтому мы делаем Rational классом, а не структурой. Структура позволила бы нарушить этот инвариант:

// struct Rational {
//     int numerator, denominator;
// };
// Rational r{2, 3};
// r.numerator = 6; // Нарушен инвариант несократимости
// Список требований, предъявляемых к реализации интерфейса класса Rational:

// Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
// При конструировании объека класса Rational с параметрами p и q должно выполняться сокращение дроби p/q (здесь вам может пригодиться решение задачи «Наибольший общий делитель»).
// Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель и положительный знаменатель.
// Если дробь p/q положительная, то объект Rational(p, q) должен иметь положительные числитель и знаменатель (обратите внимание на случай Rational(-2, -3)).
// Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
// Гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет знаменателя, равного нулю.

// Замечание:

// В стандарте языка C++17 для вычисления НОД имеется стандартная функция gcd. Допустимо использовать данную функцию для сокращения дробей. Подробнее с данной функцией и её ограничениями можно ознакомиться по ссылке: https://en.cppreference.com/w/cpp/numeric/gcd
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
    // Добавьте поля
    int num, den; 
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
