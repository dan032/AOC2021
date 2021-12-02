#include "aoc2021.h"

static const vector<challenge_t> challenges = {
        {day01a}, {day01b}, {day02a}, {day02b}, {day03a}, {day03b}
};

void checkTimings()
{

    for(int i = 0; i < challenges.size(); i++)
    {
        auto challenge = challenges[i];
        string filename = R"(C:\Users\Dan\Desktop\AOC\2021\)";
        string day;
        if (i < 10) day = "0" + to_string(i/2 + 1);
        else day = to_string(i/2 + 1);

        filename += "day" + day + "\\input.txt";
        ifstream file(filename);

        int num = 100000;
        double timeTotal = 0;
        for(int x = 0; x < num; x++) {
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            challenge.f(file);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            timeTotal += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            file.clear();
            file.seekg(0);
        }


        std::cout << "Time difference = " << timeTotal/num << "µs" << std::endl;

        file.close();
    }

}

int main()
{
    bool competitionMode = false;
    if (!competitionMode)
        checkTimings();
    else{
        string filename = R"(C:\Users\Dan\Desktop\AOC\2021\day02\input.txt)";
        ifstream file(filename);
        challenges[2].f(file);
        file.clear();
        file.seekg(0);
        challenges[3].f(file);
        file.close();
    }
    return EXIT_SUCCESS;
}