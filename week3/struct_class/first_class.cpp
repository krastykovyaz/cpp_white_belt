#include <iostream>
#include <string>
using namespace std;

class Route {
    private:
    string source;
    string destination;
    int length;
    void UpdateLength(){
        length = ComputeDistance(source, destination);
    }
    public:
    string GetSource(){
        return source;
    };
    string GetDestination(){
        return destination;
    };
    int GetLength(){
        return length;
    };
    void SetSource(const string& new_source){
        source = new_source;
        UpdateLength();
    };
    void SetDestination(const string& new_destination){
        destination = new_destination;
        UpdateLength();
    };
};

int main(){
    Route route;
    route.SetSource("Moscow");
    route.SetDestination("Dubna");
    cout << "Route from " << route.GetSource() << " to " << route.GetDestination() << " is " << route.GetLength() << " meters long"<< endl;
    return 0;
}
