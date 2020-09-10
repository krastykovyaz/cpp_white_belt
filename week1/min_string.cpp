// В стандартном потоке даны три строки, разделённые пробелом. Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов. Выведите в стандартный вывод лексикографически минимальную из них.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    string b;
    string c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a == b || b == c || a == c)
    {
        if (a < c)
            cout << a << endl;
        else if (b < c)
            cout << b << endl;
        else if (a < b)
            cout << a << endl;
        else
        {
            cout << c << endl;
        }
        
    }
    else
    { 
        if (a < b && a < c){
            cout << a;
        }
        else if (b < c && b < a){
            cout << b;
        }
        else
        {
            cout << c;
        }
    }
    return 0;
}