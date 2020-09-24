// У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца: оплата счетов за электричество, абонентская плата за связь и пр. Вам нужно реализовать работу со списком таких дел на месяц, а именно, реализовать набор следующих операций:

// ADD i s

// Назначить дело с названием s на день i текущего месяца.

// DUMP i

// Вывести все дела, запланированные на день i текущего месяца.

// NEXT

// Перейти к списку дел на новый месяц. При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся и становится активным (новый) список дел на следующий месяц: все дела со старого списка дел копируются в новый список. После выполнения данной команды новый список дел и следующий месяц становятся текущими, а работа со старым списком дел прекращается. При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах:

// если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
// если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.
// Замечания

// Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца. Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список.
// Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
// Начальным текущим месяцем считается январь.
// Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.
// Формат ввода

// Сначала число операций Q, затем описания операций.

// Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания. Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.

// Формат вывода

// Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.
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
    bool flag = false;
    if (current_month[day] == "0"){
        current_month[day] = task;
    }
    else{
        if (task != "0"){
            current_month[day] = current_month[day] + " " + task;
            int j = 0;
            for (int i = 0; i < current_month[day].length(); ++i){
                    while (current_month[day][i] != ' ')
                    {
                        current_month[day][j] = current_month[day][i];
                        ++i;
                        ++j;
                        flag = true;
                    }
                    if (flag){
                        current_month[day][j] = ' ';
                        ++j;
                    } 
                }
            }
        }
    // }
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