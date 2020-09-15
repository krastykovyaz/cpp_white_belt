#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Person {
    string name;
    string surname;
    int age;
};

vector <Person> GetMoscowPopulation();

void PrintPopulationSize(const vector <Person> &p)
{
    cout << "There are " << p.size() << " people in Moscow ";
}
int main() {
    auto start = steady_clock::now();
    vector <Person> people = GetMoscowPopulation();
    auto finish = steady_clock::now();
    cout << "Duration for GetMoscowPopulation = " << (finish - start).count() << endl;
    start = steady_clock::now();
    PrintPopulationSize(people);
    finish = steady_clock::now();
    cout << "Duration for PrintPopulationSize = " << (finish - start).count() << endl;
    return 0;
}