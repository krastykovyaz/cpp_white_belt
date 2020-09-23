#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
using namespace std;

void print_dic(const map<string, string> &country_capital){
    if (country_capital.size()){
        for (const auto & [key, value] : country_capital){
            cout << key << "/" << value << " ";
        }
    }
    else{
        cout << "There are no countries in the world";
    }
    cout << endl;
}

void change_cap(map<string, string> &country_capital, const string country, const string capital){
    string cap;
    if (country_capital.count(country) == 0){
        country_capital[country]= capital;
        cout << "Introduce new country " <<  country << " with capital " << country_capital[country] << endl;
    }
    else{
        if (country_capital[country] == capital)
        {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        }
        else{
            cout << "Country " << country << " has changed its capital from " << country_capital[country] << " to " << capital << endl;
            country_capital[country] = capital;
        }
    }
    // print_dic(country_capital);
    
}

void rename_country(map<string, string> &country_capital, const string old_c, const string new_c){
    if (country_capital.count(old_c) == 0 || country_capital.count(new_c) != 0)
    {
        cout << "Incorrect rename, skip" << endl;
    }
    else
    {
        const auto it = country_capital.find(old_c);
        if (it != country_capital.end()){
            swap(country_capital[new_c], it->second);
            country_capital.erase(it);
        }
        cout << "Country " << old_c << " with capital " << country_capital[new_c] << " has been renamed to " << new_c << endl;
    }
    // print_dic(country_capital);
    
}

void about_country(map<string, string> &country_capital, const string country){
    if (country_capital.count(country) == 0){
        cout << "Country " << country << " doesn't exist" << endl;
    }
    else{
        cout << "Country " << country <<" has capital " << country_capital[country] << endl;
    }
}

int main(){
    int q;
    map<string, string> country_capital;
    string query, country, capital, o_country, n_country;
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> query;
        // query = "CHANGE_CAPITAL";
        if (query == "CHANGE_CAPITAL"){
            cin >> country;
            cin >> capital;
            // country = "RussianEmpire";
            // capital = "Petrograd";
            change_cap(country_capital, country, capital);
        }
        else if (query == "RENAME"){
            cin >> o_country;
            cin >> n_country;
            rename_country(country_capital, o_country, n_country);
        }
        else if (query == "ABOUT"){
            cin >> country;
            about_country(country_capital, country);
        }
        else if (query == "DUMP"){
            print_dic(country_capital);
        }
    }
    return 0;
}