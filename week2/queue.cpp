// Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда. Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.

// Реализуйте обработку следующих операций над очередью:

// WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
// QUIET i: пометить i-го человека как успокоившегося;
// COME k: добавить k спокойных человек в конец очереди;
// COME -k: убрать k человек из конца очереди;
// WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
// Изначально очередь пуста.

// Формат ввода

// Количество операций Q, затем описания операций.

// Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.

// Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

// Формат вывода

// Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void come(vector <bool> &queue, int num){
    if (num > 0){
        for (int i = 0; i < num; ++i){
            queue.push_back(false);
        }
    }
    else{
            for (int i = 0; i < -num; ++i){
                queue.pop_back();
            }
        }
}

void worry(vector <bool> &queue, int num){
    int i = 0;
    for(auto people : queue){
        if (i == num){
            people = true;
        }
        i++;
    }
}

void quiet(vector <bool> &queue, int num){
    int i = 0;
    for(auto people : queue){
        if (i == num){
            people = false;
        }
        i++;
    }
}

int main(){
    int oper, i;
    vector <string> move = {};
    vector <bool> queue = {};
    cin >> oper;
    i = 0;
    while (i < oper)
    {
        string s;
        int num;
        cin >> s;
        move.push_back(s);
        if (s == "COME"){
            cin >> num;
            come(queue, num);
        }
        if (s == "WORRY"){
            cin >> num;
            worry(queue, num);
        }
        if (s == "QUIET"){
            cin >> num;
            quiet(queue, num);
        }
        if (s == "WORRY_COUNT"){
            cout << count(queue.begin(), queue.end(), true) << endl;
        }
        i++;
    }
    return 0;
}