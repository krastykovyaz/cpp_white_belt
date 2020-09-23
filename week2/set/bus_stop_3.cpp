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
