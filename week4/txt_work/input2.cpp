// Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений. Гарантируется, что содержимое файла input.txt заканчивается переводом строки.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream input("input.txt");
    string line;
    ofstream output("output.txt");
    if (input)
    {
        while (getline(input, line)){
            output << line << endl;
        }
    }
    return 0;
}