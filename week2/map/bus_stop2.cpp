// В этой задаче вам нужно присваивать номера автобусным маршрутам.

// А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.

// Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).

// Указание

// В C++ ключом словаря может быть не только число или строка, но и другой контейнер, например, vector.

// Формат ввода

// Сначала вводится количество запросов Q, затем Q описаний запросов.

// Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N различных названий остановок соответствующего маршрута. Названия остановок состоят лишь из латинских букв и символов подчёркивания.

// Формат вывода

// Выведите ответ на каждый запрос в отдельной строке.

// Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i, где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int compare(const vector<string> stops, const string total_stop, int index){
    bool flag = false;
    int i = 1;
    for (const auto & item : stops){
            if (item == total_stop){
                cout << "Already exists for " << i << endl;
                flag = true;

            }
            i++;
        }
        if (flag == false){
            index++;
            cout << "New bus " << index << endl;
        }
    return index;
}

void print_dic(map<string, int> path){
    for(const auto & [key, value] : path){
        cout << key << " " << value << endl;
    }
}

void print_vec(vector<string> stops){
    for (const auto &n : stops){
            cout << n << " ";
        }
    }


int main (){
    int query, quan_stops, idx, tmp_index, index;
    // map<vector<string>, int> path;
    map <string, int>path;
    vector<string> stops;
    string total_stop, name_stop;

    idx = 1;
    cin >> query;
    for (int i = 0; i < query; ++i){
        cin >> quan_stops;
        for (int j = 0; j < quan_stops; ++j){
            cin >> name_stop;
            total_stop += name_stop;
        }
        tmp_index = index;
        index = compare(stops, total_stop, index);
        stops.push_back(total_stop);
        if (tmp_index != index){
            path[total_stop] = index;
        }
        total_stop = "";
    }
    // print_dic(path);
    // print_vec(stops);
    // compare(total_stops);
    return 0;
}
