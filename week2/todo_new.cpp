#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_c_month(const vector <string>& current_month){
    int i = 0;
    cout << "Size = " << current_month.size() << endl;
    for (const auto& item : current_month){
        cout << item;
        i++;
    }
    // cout << "size_i = " << i << endl;
    cout  << endl;
}


void if_else_add(vector <string>& current_month, int day, string& task){
    if (current_month[day] == "0"){
        current_month[day] = task;
    }
    else{
        if (task != "0"){
            current_month[day] = current_month[day] + " " + task;
        }
    }
}

void next (vector <string>& current_month, const vector <int> &month, int &i_month){
    int new_month = 0;
    vector <string> tmp_vec;
    string tmp;
    if (i_month == 11)
    {
        new_month = 0;
    }
    else{
        new_month = i_month + 1;
    }
    // cout<< "i = " << i_month << endl;
    // cout << "i_month" << month[i_month] << endl;
    // cout << "new_month" << month[new_month] << endl;
    if (month[new_month] > month[i_month]){
        for (int item = month[i_month]; item < month[new_month]; ++item){
        current_month.push_back("0");}
    }
    else if (month[new_month] < month[i_month]){
        // tmp_vec = current_month;
        // current_month.resize(month[new_month]);
        // cout << "s i z = " << current_month.size() << endl;
        for (int item = month[new_month]; item <= month[i_month]; ++item){
            // cout << "month[new_month] = " << month[new_month] << endl;
            // cout << "item =" << current_month[item] << endl;
            if_else_add(current_month, month[new_month], current_month[item]);
        }
        current_month.erase(current_month.begin() + month[new_month] + 1, current_month.end());
        // cout << current_month[item] << endl;
    }
    // print_c_month(current_month);
    i_month = new_month;
}

int main(){
    int n, day, i_month, new_month, l;
    string query, task;
    vector <int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector <string> current_month, tmp_vec;

    cin >> n;
    i_month = 0;
    for (int j = 1; j <= month[i_month]; ++j){
        current_month.push_back("0");
    }
    for (int i = 0; i < n; ++i){
        cin >> query;
        if (query == "ADD"){
            cin >> day;
            cin >> task;
            if_else_add(current_month, day, task);
        }
        else if (query == "NEXT")
        {
            next(current_month, month, i_month);
        }
        else if (query == "DUMP")
        {
            cin >> day;
            int space = 1;
            for (int it = 0; it < current_month[day].length(); it++){
                if (current_month[day][it] == ' ')
                {
                    while(current_month[day][it] == ' '){
                        it++;
                    }
                    space++;
                }
            }
            if (space && current_month[day] != "0")
                cout << space << " ";
            cout << current_month[day] << endl;
            }
        
    }
    
    return 0;
}