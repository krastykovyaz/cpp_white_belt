#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ComputeDistance(const string& source, const string& destination){
    return source.length() - destination.length();
}

class Route {
public:
    Route(){
        source = "Saint-Petersburg";
        destination = "Moscow";
        UpdateLength();
    }
    Route(const string& new_source, const string& new_destination){
        source = new_source;
        destination = new_destination;
        UpdateLength();
    }
    ~Route(){
        for (const auto &entry : compute_distance_log){
            cout << entry << endl;
        }
    }
    string GetSource() const{
        return source;
    }
    string GetDestination() const{
        return destination;
    }
    int GetLength() const{
        return length;
    }
    void SetSource(const string & new_source){
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const string & new_destination){
        destination = new_destination;
        UpdateLength();
    }
private:
    void UpdateLength(){
        length = ComputeDistance(source, destination);
        compute_distance_log.push_back(source + " - " + destination);
    }
    string source;
    string destination;
    int length;
    vector <string> compute_distance_log;
};

void PrintRoute(Route& route){
    cout << route.GetSource() << " - " << route.GetDestination() << endl;
}

void ReverseRoute(Route & route){
    string old_source = route.GetSource();
    string old_direction = route.GetDestination();
    route.SetSource(old_direction);
    route.SetDestination(old_source);
}

int main(){
    Route route("Moscow", "Saint-Petersburg");
    route.SetSource("Vyborg");
    route.SetDestination("Vologda");
    return 0;
}