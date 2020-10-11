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
        cout << "Default Construct" << endl;
    }
    Route(const string& new_source, const string& new_destination){
        source = new_source;
        destination = new_destination;
        UpdateLength();
        cout << "Constructed" << endl;
    }
    ~Route(){
        cout << "Destructed" << endl;
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

Route GetRoute(){
    cout << 1 << endl;
    return {};
}

int main(){
    Route route({});
    Route route2("Moscow", "Saint-Petersburg");
    route.SetSource("Vyborg");
    route.SetDestination("Vologda");
    GetRoute();
    cout << 2 << "\n";
    return 0;
}