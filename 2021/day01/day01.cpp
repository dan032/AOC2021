#include "../aoc2021.h"

void day01a(ifstream &file)
{
    uint16_t prev = 0, res = 0, curr = 0;
    file >> prev;
    while(file >> curr)
    {
        res = curr > prev ? res + 1 : res;
        prev = curr;
    }
}

void day01b(ifstream &file)
{
    uint16_t first = 0, second = 0, third = 0, prevSum = 0, currSum = 0, res = 0, curr = 0;
    while(file >> curr)
    {
        currSum = currSum + curr - first;

        first = second;
        second = third;
        third = curr;

        res = curr > prevSum ? res + 1 : res;
        prevSum = currSum;
    }
}

