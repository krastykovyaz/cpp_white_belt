// На вход вашей программы в стандартном потоке ввода подаются действительные коэффициенты A, B и C уравнения Ax² + Bx + C = 0. Выведите все его различные действительные корни в поток вывода в любом порядке, при этом разделяя корни пробелами. Гарантируется, что хотя бы один из коэффициентов уравнения не равен нулю.
#include <iostream>
// #include <string>
#include <cmath>
using namespace std;

int main(){
    double a;
    double b;
    double c;
    double x1;
    double x2;
    cin >> a;
    cin >> b;
    cin >> c;
    if (((b * b) - (4 * a * c)) < 0 || (a == 0 && b == 0))
        return 0;
    if (a == 0)
    {
        if (b == 0)
            return 0;
        x1 = ((-1) * c == -0 ? 0 : -c) / b;
        cout << x1 << endl;
    }
    else if (b == 0)
    {
        if (a == 0)
            return 0;
        if ( (((-1) * c == -0 ? 0 : -c) / a) < 0)
            return 0;
        x1 = sqrt(((-1) * c == -0 ? 0 : -c) / a) ;
        x2 = sqrt(((-1) * c == -0 ? 0 : -c) / a) * (-1);
        cout << x1 << " ";
        cout << x2 << endl;
    }
    else if (c == 0){
        if (a == 0)
            return 0;
        x1 = 0;
        cout << x1 << " ";
        x2 = ((-1) * b == -0 ? 0 : -b / a);
        cout << x2 << endl;
    }
    else{
        // cout << sqrt((b * b) - (4 * a * c)) << " ";
        x1 = (- b + sqrt((pow(b, 2)) - (4 * a *c))) / (2 * a);
        x2 = (- b - sqrt((pow(b, 2)) - (4 * a *c))) / (2 * a);
        if (x1 == x2){
            cout << x1 << endl;
        }
        else{
            cout << x1 << " ";
            cout << x2 << endl;
        }
    }
    return 0;
}