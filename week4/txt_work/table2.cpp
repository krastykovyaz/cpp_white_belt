// В первой строке файла input.txt записаны два числа N и M. Далее в файле находится таблица из N строк и M столбцов, представленная в формате CSV (comma-separated values). Такой формат часто используется для текстового представления таблиц с данными: в файле несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми. Ваша задача — вывести данные на экран в виде таблицы. Формат таблицы:

// 1) размер ячейки равен 10,

// 2) соседние ячейки отделены друг от друга пробелом,

// 3) последняя ячейка в строке НЕ оканчивается пробелом,

// 4) последняя строка НЕ оканчивается символом перевода строки. Гарантируется, что в таблице будет ровно N строк и M столбцов, значение каждой из ячеек — целое число. Пример ввода
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
