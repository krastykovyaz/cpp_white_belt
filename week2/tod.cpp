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

// void printCalendar(const vector<vector<int>> calender, vector<int> month)
// {
//     for (int i = 0; i < 12; i++){
//         for (int j = 0; j < month[i]; j++){
//             calender[i].push_back(j);
//             cout << " "<< calender[i][j];
//         }
//         cout << " " << endl;
//     }
// }

void add_to(vector<vector<string>> &calender, int current_month, int num, string task)
{
    if (calender[current_month][num] == "0"){
        calender[current_month][num] = task;
    }
    else{
        calender[current_month][num] += " ";
        calender[current_month][num] += task;
    }
    for (auto i : calender[current_month])
    {
        cout << i;
    }
    cout << "len = " << calender[current_month].size() << endl;
}
void next(vector<vector<string>> &calender, int current_month, vector <int> month){
    cout << "month[current_month + 1] = " << month[current_month + 1];
    if (month[current_month] < month[current_month + 1])
    {
        for (int i = month[current_month]; i < month[current_month + 1]; i++){
            calender[current_month].push_back("0");
        }
    }
    else if (month[current_month] > month[current_month + 1]){
            calender[current_month].erase(calender[current_month].begin() + month[current_month + 1], calender[current_month].end());
        }
        cout << "len = " << calender[current_month].size() << endl;
        // calender[month[current_month]].resize(month[current_month + 1]);
        // calender[month[current_month + 1]].insert(end(calender[month[current_month + 1]]), begin(calender[current_month]), end(calender[current_month]));
    calender[current_month + 1] = calender[month[current_month]];
}

int main(){
    int oper, current_month, num, j;
    bool flag = false;
    vector<vector<string>> calender(12);
    string command, task;
    vector <int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // calender = create_calendar(month);
    current_month = 0;
    j = 0;
    cin >> oper;
    while (j < oper)
    {

        cin >> command;
        if (current_month == 0 && flag == false){
            calender[current_month].assign(month[current_month], "0");
        }
        if (command == "ADD"){
            cin >> num;
            cin >> task;
            add_to(calender, current_month, (num - 1), task);
            j++;
        }
        else if (command == "NEXT"){
            next(calender, current_month, month);
            current_month += 1;
            j++;
        }
        flag = true;
    }
    return 0;
}

