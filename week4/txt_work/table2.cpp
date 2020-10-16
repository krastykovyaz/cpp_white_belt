#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void PrintTable(vector <vector <double>> line, int col, int row){
    for (int j = 0; j < col; j++){
        for (int i = 0; i < row; i++){
            cout << line[j][i];
        }
    }
}

int main(){
    ifstream input("input.txt");
    int row=0, col=0, z = 0;;
    vector <vector <int>> line;
    input >> row;
    input.ignore(1);
    input >> col;
    // cout << row << " " << col << endl;
    cout << fixed;
    if (input){
        int j = 0;
        while (j < row)
        {
            for (int i = 0; i < col; i++){
                // line[j][i].push_back(input);
                // cout << j << " " << i << " " << endl;
                cout << setw(10) << setfill(' ');
                input.ignore(1);
                input >> z;
                cout << z;
                if (i < col - 1)
                    cout << "";
            }
            if (j < row - 1)
                cout << endl;
            j++;
        }
    }
    // PrintTable(line, col, row);
    return 0;
}
