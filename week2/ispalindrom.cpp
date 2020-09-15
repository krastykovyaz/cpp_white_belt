// Напишите функцию, которая

// называется IsPalindrom
// возвращает bool
// принимает параметр типа string и возвращает, является ли переданная строка палиндромом
// Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. Пустая строка является палиндромом.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string word){
    int count = 0;
    vector <char> part_one;
    vector <char> part_two;
    for (auto w : word)
    {
        count++;
    }
    if (count == 1){
        return true;
    }
    if (count % 2 == 0)
    {
        for (int i = 0; i < count / 2; i++)
        {

            part_one.push_back(word[i]);
        }
        for (int i = count - 1; i >= count / 2; --i)
        {
            part_two.push_back(word[i]);
        }
    }
    else{
        for (int i = 0; i < count / 2; i++)
        {
            part_one.push_back(word[i]);
        }
        for (int i = count - 1; i >= (count / 2) + 1; --i)
        {
            part_two.push_back(word[i]);
        }
    }
    if (part_two == part_one) {
        return true;
    }
    else
    {
        return false;
    }
}