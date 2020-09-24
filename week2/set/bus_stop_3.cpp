// В этой задаче вам нужно присваивать номера автобусным маршрутам.

// А именно, для каждого маршрута, заданного множеством названий остановок, нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такое множество остановок.

// В отличие от задачи «Автобусные остановки — 2», наборы остановок, которые можно получить друг из друга перестановкой элементов или добавлением/удалением повторяющихся, следует считать одинаковыми.

// Формат ввода

// Сначала вводится количество запросов Q, затем Q описаний запросов.

// Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N названий остановок соответствующего маршрута (не обязательно различных). Названия остановок состоят лишь из латинских букв и символов подчёркивания.

// Формат вывода

// Выведите ответ на каждый запрос в отдельной строке.

// Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i, где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

void print_dic(map<string, int> path){
    for(const auto & [key, value] : path){
        cout << key << " " << value << endl;
    }
}

void print_set(set<set<string>>  path){
    for (const auto &n : path){
        for (const auto &item: n)
            cout << item << " ";
            cout << endl;
        }
    }


int main (){
    int query, quan_stops, idx, tmp_index, index;
    set<set<string>>  path;
    // set <string> path;
    map <int, set<string>>pos;
    set<string> stops;
    string total_stop, name_stop;

    idx = 1;
    cin >> query;
    for (int i = 0; i < query; ++i){
        cin >> quan_stops;
        for (int j = 0; j < quan_stops; ++j){
            cin >> name_stop;
            stops.insert(name_stop);   
            // path.insert(name_stop);
        }
        if (path.count(stops) == 0){
            path.insert(stops);
            cout << "New bus " << idx << endl;
            pos[idx] = stops;
            idx++;
        }
        else
        {
            int z = 1;
            for (const auto & item : path){
                // for (const auto &i : item){
                //     cout << i << " "; 
                    
                // }
                // cout << endl;
                for (const auto & j : pos){
                    if (item == stops && item == j.second)
                    {
                        cout << "Already exists for " << j.first << endl;
                        // z++;
                    }
                    z++;
                }
            }
            
        }

        stops.clear();   
    }

    return 0;
}
