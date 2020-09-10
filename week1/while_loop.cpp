#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n < 0){
        cout << "The number is negative" << endl;
    }
    else {        
        int sum = 0;
        while (n)
        {
            sum += n;
            --n;
        }
        cout << sum;
    } 
    return 0;
}