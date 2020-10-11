#include <iostream>
#include <vector>
using namespace std;

int ComputeDistance(const string& source, const string& destination){
    return source.length() - destination.length();
}

class Route {
public:
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
    }
    string source;
    string destination;
    int length;
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
    Route route;
    route.SetSource("Saint-Petersburg");
    route.SetDestination("Moscow");
    PrintRoute(route);
    ReverseRoute(route);
    PrintRoute(route);
    return 0;
}