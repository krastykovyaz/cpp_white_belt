//Напишите функцию, которая
// называется Factorial
// возвращает int
// принимает int и возвращает факториал своего аргумента. Гарантируется, что аргумент функции по модулю не превышает 10. Для отрицательных аргументов функция должна возвращать 1.
#include <iostream>
using namespace std;

long long int Factorial(long long int number){
    if (number < 0){
        return 1;
    }
    if (number > 1){
        return number * Factorial(number - 1);
    }
    else
    {
        return 1;
    }
}

int main(){
    long long int n, result;
    cin >> n;
    result = Factorial(n);
    cout << "result = " << result << endl;
}