#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void ReadAll(const string &filename){
    ifstream input(filename);
    string buffer;
    if (input){
        while (getline(input, buffer))
        {
            cout << buffer << endl;
        }
    }
    else
    {
        cout << "Error" << endl;
    }
    
}

int main(){
    const string path = "out.txt";
    ofstream output(path, ios::app);
    output << "Hello" << endl;
    ReadAll(path);
    return 0;
}