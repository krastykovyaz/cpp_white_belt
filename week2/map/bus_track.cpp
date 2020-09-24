// Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

// NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
// BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
// STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
// ALL_BUSES — вывести список всех маршрутов с остановками.
// Формат ввода

// В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.

// Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.

// Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus отсутствует, количество остановок больше 0, а после числа stop_count следует именно такое количество названий остановок, причём все названия в каждом списке различны.

// Формат вывода

// Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:

// На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в котором они создавались командами NEW_BUS. Если остановка stop не существует, выведите No stop.
// На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, в котором они были заданы в соответствующей команде NEW_BUS. Описание каждой остановки stop должно иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, проезжающих через остановку stop, в порядке, в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus. Если через остановку stop не проезжает ни один автобус, кроме bus, вместо списка автобусов для неё выведите no interchange. Если маршрут bus не существует, выведите No bus.
// На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке. Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке, в котором они были заданы в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.
// Предупреждение

// Условие задачи выше содержит много важных деталей. Если вы не уверены в том, что не упустили ни одной, перечитайте условие ещё раз.
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void put_tracks(map <string, vector<string>> &buses, const string bus, const vector<string> &stop_names)
{
    for (auto i : stop_names){
        // cout << i << " " << endl;
        buses[bus].push_back(i);
    }
}

void print_dic(map <string, vector<string>> &buses)
{

    for (const auto &item : buses){
        cout << item.first << endl;
        for (const auto word : item.second){
            cout << word << endl;
        }
    }
    // cout << buses["Tolstopaltsevo"].size() << endl;
}

void print_vec(const vector<string>stop_names){
    for (const auto &i : stop_names){
        cout << i << " ";
    }
}

void print_dic_int(const map<int, vector<string>> m){
    for (const auto &item : m){
        for (const auto &i : item.second){
            cout << i << " "<< endl;
        }
    }
}

void bus_for_stop(map<string, vector<string>>& buses, const string& stop, map <int, string> bus_seq){
    bool flag = false;
    // cout << buses["33"].size() << endl;
    // print_dic(buses);
    vector <string> bus_4_stop;
    for (const auto &item : buses)
    {
        for(const auto stops : item.second){
            // cout << "Stop = "<< item.first << " ";
            if (stops == stop){
                if (!flag){
                    // cout << "Stop " << stop << ":";
                    flag = true;
                    // cout << " item = "<< item.first << endl;
                }
                bus_4_stop.push_back(item.first);
                // cout << item.first <<endl;
            }
        }
    }
    int z = 0;
    for (const auto& i : bus_seq){
        // cout << i.first;
        for (const auto& j : bus_4_stop){
            if (i.second == j){
                cout << i.second;
                if (z < bus_4_stop.size() - 1){
                    cout << " ";
                } 
                z++;
            }
        }
            // cout << j << " ";
    }
    if (!flag){
        cout << "No stop";
    }
    cout << endl;
}

map<string, vector<string>> rever_stop_2_bus(const map<string, vector<string>>& buses){
    map<string, vector<string>> reverse_buses;
    for (const auto& bus : buses){
        // cout << bus.first << endl;
        for(const auto& item : bus.second){
            reverse_buses[item].push_back(bus.first);
        }
    }
    // print_dic(reverse_buses);
    return reverse_buses;
}

void stop_4_bus(const map<string, vector<string>>& buses, const string& bus, const map <string, map <int, vector<string>>> &number_stops,\
    map <int, string> bus_seq){
    int count = 0;
    int one_bus = 0;
    map<string, vector<string>> reverse_buses;
    map <string, vector<string>> store;
    vector<string>stops;
    reverse_buses = rever_stop_2_bus(buses);
    // print_dic(reverse_buses);
    for(const auto& i : reverse_buses){
        for (const auto& item : i.second){
            if (item == bus){
                one_bus ++;
                stops.push_back(i.first);
                // cout << i.first << endl;
            }
        }
    }
    // cout << "number_bus "<< number_stops.size() << endl;
    // cout << "stops "<< stops.size() << endl;
    // print_dic_int(number_stops);
    int z = 0;
    for (const auto & b : number_stops){
        if (b.first == bus){
            for (const auto& item : b.second){
                for (const auto&i : item.second){
                    for (const auto& iter : stops){
                        // cout << "i = " << i << endl;
                        // cout << "iter = " << iter << endl;
                        // cout << item.first;
                        if (iter == i){
                            // cout <<" "<< iter << ":";
                            for (const auto& j : reverse_buses){
                                for (const auto& k : j.second){
                                    // cout << k << " ";
                                    if (j.first == i){
                                        store[i].push_back(k);
                                        // cout << i<< k << endl;
                                        // z++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    // print_dic(store);
    if (store.empty())
    {
        cout << "No bus"<<endl;
    }
    for (const auto &stait : number_stops){
        // for (const auto &sta : stait.second){
            if (stait.first == bus){
                // cout << stait.first <<endl;
                for (const auto &sta : stait.second){
                    for (const auto &st : sta.second){
                        // cout << " " << st <<endl;
                        for (const auto &s : store){
                            if (st == s.first){
                                cout <<"Stop "<< s.first << ":";
                                if (reverse_buses[s.first].size() == 1){
                                    cout << " no interchange";
                                }
                                else{
                                    for (const auto &i : bus_seq){
                                        // cout << i.first << " ";
                                        for (const auto &x : s.second){
                                            if (i.second == x && x != bus){
                                                cout <<  " " << x;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        cout << endl;
                }
            }
        }
    }
}

void all_buses(const map<string, vector<string>>& buses, const map <string, map<int, vector<string>>> number_stops){
    int count = 0;
    int idx = 0;
    if (buses.size() != 0){
        // for (const auto& item : buses){
        //     cout << "Bus " << item.first << ":";
        //     idx = 0;
        //     for (const auto & n : number_stops){
        //         for (const auto& z : n.second){
        //             // cout << z.first;
        //             count = 0;
        //             for (const auto & stop : z.second){
                        
        //                 // for (const auto& i : item.second){
        //                     cout << stop << endl;
        //                     // if (stop == i && count < item.second.size() && idx < buses.size()){
        //                     //     cout << " " << stop;
        //                         // idx++;
        //                     // }
        //                 // }
        //                 count++;
        //             }
        //         }
        //     }
        //     cout << endl;
        // }
        for (const auto &item : number_stops){
            cout << "Bus "<< item.first << ":";
            for (const auto &it : item.second){
                for (const auto & stop : it.second){
                    cout << " " << stop;
                }
                cout << endl;
            }
        }
    }
    else
    {
        cout << "No buses" << endl;
    }
    
}

int main(){
    int num_query, count_stop, idx, size_tmp;
    map <string, vector<string>> stops, buses;
    map <string, int> tmp;
    map <int, string> number_bus;
    map<int, string> bus_seq;
    map <string, map<int, vector<string>>> number_stops;
    vector<string>stop_names;
    string query, bus, bus_stop;
    cin >> num_query;
    idx = 0;
    size_tmp = 0;
    for (int i = 0; i < num_query; ++i){
        cin >> query;
        if (query == "NEW_BUS"){
            cin >> bus;
            bus_seq[i] = bus;
            idx++; 
            cin >> count_stop;
            number_bus[i] = bus;
            for (int j = 0; j < count_stop; ++j){
                cin >> bus_stop;
                number_bus[j] = bus_stop;
                tmp[bus_stop] = i;
                // if (size_tmp < tmp.size()){
                    number_stops[bus][i].push_back(bus_stop);
                // }
                stop_names.push_back(bus_stop);
            }
            // print_vec(stop_names);
            put_tracks(buses, bus, stop_names);
        }
        else if (query == "BUSES_FOR_STOP")
        {
            cin >> bus;
            bus_for_stop(buses, bus, bus_seq);
        }
        else if (query == "STOPS_FOR_BUS"){
            cin >> bus;
            stop_4_bus(buses, bus, number_stops, bus_seq);
        }
        else if (query == "ALL_BUSES"){
            all_buses(buses, number_stops);
        }
        size_tmp = tmp.size();
        stop_names.clear();
        // bus_seq.clear();
        // print_dic(buses);
    }
    return 0;
}