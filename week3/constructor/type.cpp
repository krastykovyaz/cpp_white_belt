#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Incognizable{
public:
    Incognizable(){};
    Incognizable(int n){};
    Incognizable(int n1, int n2){};
private:
    // vector <int> v;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}