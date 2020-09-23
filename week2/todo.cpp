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
using namespace std;

vector<vector<string>> create_calendar(vector<int> month){
     vector<vector<string>> calender = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < month[i]; j++){
            calender[i].push_back("0");
            // cout << " "<< calender[i][j];
        }
        // cout << " " << endl;
    }
    return calender;
 }

void printCalendar(vector<vector<string>> calender, vector<int> month)
{
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < month[i]; j++){
            // calender[i].push_back();
            cout << " "<< calender[i][j];
        }
        cout << " " << endl;
    }
}

void set_days(vector <vector<string>> &calender, int &current_month, vector <int> month){
    // printCalendar(calender, month);
    // create_calendar(month);
    int business;
    if (current_month < 12){
        int j = 0;
        for(auto i : calender[current_month + 1]){
            if (i != "0"){
                calender[current_month + 1][j] = "0";
            }
            j++;        
        }
        j = 0;
        if (month[current_month] < month[current_month + 1]){
            for(auto i : calender[current_month]){
            calender[current_month + 1][j] = calender[current_month][j];
            j++;        
            }
        }
        else
        {
            business = month[current_month] - month[current_month + 1];
            for(auto i : calender[current_month + 1]){
                calender[current_month + 1][j] = calender[current_month][j];
                j++;        
            }
            string total;
            int n = 0;
            for(auto i : calender[current_month])
            {
                if (n >= j && i != "0")
                {
                    // cout << "j = " << j << endl;
                    total += i;
                    if (n < business + j - 1)
                    {
                        total += " ";
                    }
                }
                n++;
            }
            // cout << "total = "<< total << endl;
            calender[current_month + 1][j - 1] = total;
            // cout << calender[current_month + 1][j - 1] <<endl;
        }
    }
    else
    {
        int j = 0;
        for(auto i : calender[0]){
            calender[0][j] = "0";
            j++;        
        }
    }
    if (current_month < 12){
        current_month += 1;
        }
    else
    {
        int j = 0;
        for(auto i : calender[0]){
            if (i != "0"){
                calender[0][j] = "0";
            }
            j++;        
        }
        j = 0;
        if (month[current_month] < month[0]){
            for(auto i : calender[current_month]){
            calender[0][j] = calender[current_month][j];
            j++;        
            }
        }
        else
        {
            business = month[current_month] - month[0];
            for(auto i : calender[0]){
                calender[0][j] = calender[current_month][j];
                j++;        
            }
            string total;
            int n = 0;
            for(auto i : calender[current_month])
            {
                if (n >= j && i != "0")
                {
                    // cout << "j = " << j << endl;
                    total += i;
                    if (n < business + j - 1)
                    {
                        total += " ";
                    }
                }
                n++;
            }
            // cout << "total = "<< total << endl;
            calender[current_month + 1][j - 1] = total;
            // cout << calender[current_month + 1][j - 1] <<endl;
        }
        current_month = 0;   // cout << current_month;
    }
}

void add_to(vector<string> &calender, const string task, int num)
{
    int idx = 0;
    for (auto i : calender){
        if (idx == num &&  calender[idx] == "0"){
            calender[idx] = task;
        }
        else if (idx == num){
            calender[idx] += " ";
            calender[idx] += task;
        }
        idx++;
    }
}

void dump(const vector <string> calender, int num){
    int i = 0;
    int count = 1;
    if (calender[num] != "0"){
        // cout << calender[num][i];
        while (i < calender[num].length())
        {
            // cout << calender[num][i];
            if (calender[num][i] == ' '){
                count++;
            }
            i++;
        }
        cout << count << " ";
        cout << calender[num] << endl;
    }
    else
    {
        cout << calender[num] << endl;
    }
    
}

int main(){
    int oper, current_month, num, count_oper;
    vector<vector<string>> calender;
    string command, task;
    vector <string> days;
    vector <int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    calender = create_calendar(month);
    current_month = 0;
    oper = 0;
    cin >> count_oper;
    while (oper < count_oper)
    {
        // cout << "current_month = "<< current_month << endl;
        cin >> command;
        if (command == "ADD")
        {
            cin >> num;
            cin >> task;
            num -= 1;
            add_to(calender[current_month], task, num);
            oper++;
        }
        else if (command == "NEXT"){
            set_days(calender, current_month, month);
            oper++;
        }
        else if(command == "DUMP")
        {
            cin >> num;
            num -= 1;
            dump(calender[current_month], num);
            oper++;
        }
        printCalendar(calender, month);
        cout << "==============\n";
    }
    return 0;
}

