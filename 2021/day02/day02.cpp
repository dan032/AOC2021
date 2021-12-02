#include "../aoc2021.h"

void day02a(ifstream &file){
    uint32_t x = 0, y = 0, amount;
    string dir;

    while(file >> dir >> amount)
    {
        switch (dir[0]) {
            case 'f':
                x = x + amount;
                break;
            case 'd':
                y = y + amount;
                break;
            case 'u':
                y = y - amount;
                break;
        }
    }
}

void day02b(ifstream &file){
    int x = 0, y = 0, amount, aim = 0;
    string dir;

    while(file >> dir >> amount)
    {
        switch (dir[0]) {
            case 'f':
                x = x + amount;
                y = y +  (aim * amount);
                break;
            case 'd':
                y = y + amount;
                break;
            case 'u':
                y = y - amount;
                break;
        }
    }
}
