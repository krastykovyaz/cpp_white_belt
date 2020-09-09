#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> nums = {"a","b","c","d","e","f"};
    for (auto c : nums){
        cout << c << "," << endl;
    }
    vector <int> nums2 = {5, 8 , 9, 1, 2, 6};
    int quantity = count(begin(nums2), end(nums2), 5);
    sort(begin(nums2), end(nums2));
    for (auto x : nums2){
        cout << x << " ";
    }
    cout << endl;
    cout << "There are " << quantity << " fives" << endl;
    string word = "babax";
    sort(begin(word), end(word));
    cout << word << " " << count(begin(word), end(word), 'a');
    return 0;
}