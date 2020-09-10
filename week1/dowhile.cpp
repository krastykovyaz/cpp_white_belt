#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int num;
    do{
        cout << "Guess number: ";
        cin >> num;
    }
    while(n != num);
    cout << "Your bet is right!" << endl;
    return 0;
}