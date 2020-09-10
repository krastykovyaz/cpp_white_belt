//Дано два целых числа A и B (A <= B, A >= 1, B <= 30000). Выведите через пробел все чётные числа от A до B (включительно).
#include <iostream>

int main(){
    int a, b, i;
    std :: cin >> a >> b;
    i = a;
    if (a <= b && a >= 1 && b <= 30000)
    {
       while (i <= b){
           if (i % 2 == 0)
           {
               std :: cout << i;
               if (i < (b - 1)){
                   std :: cout << " ";
               }
           }
           ++i;
       } 
    }
    std :: cout << "\n";
    return 0;
}