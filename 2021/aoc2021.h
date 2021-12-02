#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <chrono>

using namespace std;

#ifndef AOC2020_MAIN_H
#define AOC2020_MAIN_H

struct challenge_t {
    void (*f)(ifstream&);
};

void day01a(ifstream&);
void day01b(ifstream&);
void day02a(ifstream&);
void day02b(ifstream&);
void day03a(ifstream&);
void day03b(ifstream&);

#endif //AOC2020_MAIN_H
