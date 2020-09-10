//Дана строка. Найдите в этой строке второе вхождение буквы f и выведите индекс этого вхождения. Если буква f в данной строке встречается только один раз, выведите число -1, а если не встречается ни разу, выведите число -2. Индексы нумеруются с нуля.
#include <iostream>
#include <string>
using namespace std;

int main(){
    string f;
    cin >> f;
    int count = 0;
    for (int i = 0; i < f.size(); ++i)
    {
        if (f[i] == 'f'){
            count += 1;
        }
        if (count == 2){
            cout << i << endl;
            return 0;
        }
    }
    if (count == 1)
    {
        cout << -1 << endl;
    }
    if (count == 0)
        cout << -2 << endl;
    return 0;
}
