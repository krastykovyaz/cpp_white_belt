#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Person {
    string name;
    string surname;
    int age;
};

int main(){
    map <string, int> name_to_value;
    name_to_value["one"] = 1;
    name_to_value["two"] = 2;
    cout << "two is " << name_to_value["two"] << '\n';
    cout << "==============\n";
    vector <Person> staff;
    staff.push_back({"Ivan", "Petrov", 25});
    staff.push_back({"Ivan", "Petrov", 32});
    cout << "first one " << staff[0].name;
    return 0;
}