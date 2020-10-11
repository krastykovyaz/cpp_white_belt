#include <iostream>
#include <string>
using namespace std;

class ReversibleString{
public:
    ReversibleString(){};
    ReversibleString(const string& data){
        str = data;
        }
    void Reverse(){
        string new_string = str;
        int j = 0;
        for (int i = new_string.length() - 1; i >= 0; --i){
            str[j] = new_string[i];
            j++;
        }
    }
    string ToString() const {
        return str;
    }
private:
    string str;
};

int main(){
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
    
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
    
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}