// Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
// Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

// Гарантируется, что все имена и фамилии непусты.

// Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

// Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
// Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".
// Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Person{
    public:
    void ChangeFirstName(int year, const string &first_name){
        // cout << "--" << year << endl;
        name[year] = first_name;
        // f_name = first_name;
    }
    void ChangeLastName(int year, const string &last_name){
        surname[year] = last_name;
        // l_name = last_name; 
    }
    string GetFullName(int year){
        int f1 = 0;
        int f2 = 0;
        string full_name, s_name, f_name;
        for (const auto & [key, val] : surname){
            if (key <= year) {
                f2++;
                s_name = val;
            }
        }
        for (const auto & [key, val] : name){
            if (key <= year) {
                f1++;
                f_name = val;
            }
        }
        if (f1 == 1 && f2 == 1)
        {
            full_name = "Incognito";
        }
        // else if (f1 == 1){
        //     full_name = s_name + " " + f_name;
        // }
        // else if (f2 == 1){
        //     full_name = s_name + " " + f_name;
        // }
        else{
            full_name = f_name + " " + s_name;
        }
        return full_name;
    }
    private:
    map <int, string> name = {{1, "with unknown first name"}};
    map <int, string> surname = {{1, "with unknown last name"}};
    int yr = 0;
    // string f_name;
    // string l_name;
};

int main(){
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}){
        cout << person.GetFullName(year) <<endl;
    }
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}){
        cout << person.GetFullName(year) << endl;
    }
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}){
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}

// int main() {
// 	Person person;

// 	person.ChangeFirstName(1965, "Polina");
// 		for (int year : {1964, 1965, 1966}) {
// 			cout << person.GetFullName(year) << endl;
// 		}

// 	  person.ChangeLastName(1964, "Sergeeva");
// 	  for (int year : {1963, 1964, 1966}) {
// 	    cout << person.GetFullName(year) << endl;
// 	  }

// 	return 0;
// }
