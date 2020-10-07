#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
    int n, exp;
    cin >> n;
    vector <int> a;
    for (size_t i = 0; i < n; i++)
    {
        cin >> exp;
        a.push_back(exp);
    }
    sort(begin(a), end(a), [](int x, int y){
        // cout << "x: " << x << "; y: " << y << '\n'; 
        if (x < 0 && y > 0){
            x *= -1;
            return (x < y) ? 1 : 0; 
        }
        else if (y < 0 && x > 0){
            y *= -1;
            return (x < y) ? 1 : 0;
        }
        else if (x < 0 && y < 0){
            y *= -1;
            x *= -1;
            return (x < y) ? 1 : 0;
        }
        return (x < y) ? 1 : 0;
    });
    for (auto const &i : a)
    {
        cout << i << " ";
    }
    return 0;
}