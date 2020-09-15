#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintVector(const vector<string>& v) {
  for (string s : v) {
    cout << s << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> v;
  int i = 0;
  while (i < n) {
    string s;
    cin >> s;
    v.push_back(s);
    cout << "Current size = " << v.size() << endl;
    ++i;
  }
  PrintVector(v);
  return 0;
}