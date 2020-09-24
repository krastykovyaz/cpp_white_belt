// Реализуйте справочник столиц стран.

// На вход программе поступают следующие запросы:

// CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше её не было.
// RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
// ABOUT country — вывод столицы страны country.
// DUMP — вывод столиц всех стран.
// Формат ввода

// В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов. Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.

// Формат вывода

// Выведите результат обработки каждого запроса:

// В ответ на запрос CHANGE_CAPITAL country new_capital выведите

// Introduce new country country with capital new_capital, если страны country раньше не существовало;
// Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
// Country country has changed its capital from old_capital to new_capital, если страна country до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.
// В ответ на запрос RENAME old_country_name new_country_name выведите

// Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует;
// Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен и страна имеет столицу capital.
// В ответ на запрос ABOUT country выведите

// Country country doesn't exist, если страны с названием country не существует;
// Country country has capital capital, если страна country существует и имеет столицу capital.
// В ответ на запрос DUMP выведите

// There are no countries in the world, если пока не было добавлено ни одной страны;
// последовательность пар вида country/capital, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна. При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.
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