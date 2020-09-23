#include <iostream>
#include <map>
using namespace std;

void print_date(const map<int, string> &date)
{
    for(auto i : date){
        cout << i.first << ":" << i.second << endl;
    }
    cout << "size = " << date.size() << endl;
}

void print_rever_date(map<string, int> &rever_date)
{
    for(auto i : rever_date){
        cout << i.first << ":" << i.second << endl;
    }
    cout << rever_date["economy"] << endl;
}

map <string, int> biuld_dict_reverse(const map <int, string> date){
    map <string, int> rever_date;
    for(auto i : date){
        rever_date[i.second] = i.first;
    }
    return rever_date;
}

int main(){
    map <int,string> date;
    map < string, int> rever_date;
    date[2009] = "first car";
    date[2015] = "chemistry";
    date[2019] = "economy";
    date.erase(2009);
    rever_date = biuld_dict_reverse(date);
    print_date(date);
    print_rever_date(rever_date);
    return 0;
}