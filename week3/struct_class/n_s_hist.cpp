
// Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

// Гарантируется, что все имена и фамилии непусты.

// Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

// Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
// Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".
// Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".
// В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не только последние имя и фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке. Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе изменение при формировании истории нужно игнорировать.

// Для лучшего понимания формата см. примеры.
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Full_name{
    string nam;
    string sur;
};

void PrintVector(const vector <string> &v){
    for (const auto & item : v){
        cout << item << " ";
    }
    // cout << endl;
}

string build(const map <string, int> &m){
    string patern;
    for (const auto &[key, val] : m){
        patern += key;
    }
    return(patern);
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        if (members.count(year) == 0){
            members[year].sur = "";
        }
        members[year].nam = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if (members.count(year) == 0){
            members[year].nam = "";
        }
        members[year].sur = last_name;
    }

    string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
        string full_n;
        string f_n = "";
        string l_n = "";
        if (members.size() == 0)
            return "Incognito";
        for (const auto &y : members){
            if (y.first <= year && y.second.nam != ""){
                f_n = y.second.nam;
            }
            if (y.first <= year && y.second.sur != ""){
                l_n = y.second.sur;
            }
        }
        if (f_n == "" && l_n == "") return "Incognito";
        if (f_n == "") return "with unknown first name " + l_n;
        else if (l_n == "") return f_n + " with unknown last name";
        else return f_n + " " + l_n;
    }       
    string GetFullNameWithHistory(int year) {
        vector<string> nms, lms;
        string names = "";
        string surname = "";
        if (members.size() == 0)
            return "Incognito";
        for (const auto &y : members)
        {
            if (y.first <= year && y.second.sur != ""){
                if (y.second.sur != surname && surname != ""){
                    lms.push_back(surname);

                }
                surname = y.second.sur;
            }
            if (y.first <= year && y.second.nam != ""){
                if (y.second.nam != names && names != ""){
                    nms.push_back(names);
                    // cout << names << endl;
                }
                names = y.second.nam;
            }
        }
        string secnames_string = "", firstnames_string = "";
        // if (nms.size() == 0 && lms.size() == 0)
        //     return "Incognito";
        if (nms.size() > 0){
            firstnames_string += " (";
            firstnames_string += nms[nms.size() - 1];
            if (nms.size() > 1){
                for (int i = nms.size() - 1; i > 0; --i){
                    if (i > 0)
                        firstnames_string += ", ";
                    firstnames_string += nms[i - 1];                   
                }
            }
            firstnames_string += ")";
        }
        if (lms.size() > 0){
            secnames_string += " (";
            secnames_string += lms[lms.size() - 1];
            if (lms.size() > 1){
                for (int i = lms.size() - 1; i > 0; --i){
                    if (i > 0)
                        secnames_string += ", ";
                    secnames_string += lms[i - 1];
                }
                
            } 
            secnames_string += ")";
        }
        if (!names.length() && !surname.length())
            return "Incognito";
        if (names == "") return surname + secnames_string + " with unknown first name";
        else if (surname == "") return names + firstnames_string + " with unknown last name";
        else return names + firstnames_string + " " + surname + secnames_string;
    }
    private:
    map <int, Full_name> members;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}