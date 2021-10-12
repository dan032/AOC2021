#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    string line;
    string filename = R"(C:\Users\Dan\Desktop\AOC\2015\day02\input.txt)";
    ifstream file(filename);
    vector<string> v;

    if (!file.is_open())
    {
        perror("File not found");
        return EXIT_FAILURE;
    }

    while(file.good())
    {
        getline(file, line);
        v.push_back(line);
    }

    long total = 0;

    for (const auto& e : v)
    {
        int lIdx = e.find('x');
        int l = stoi(e.substr(0, lIdx));

        int wIdx = e.substr(lIdx + 1, e.length()).find('x');
        int w = stoi(e.substr(lIdx + 1, wIdx));

        int h = stoi(e.substr(wIdx + lIdx + 2, e.length()));

        int smallest = min(l, min(w, h));
        int secondSmallest = l + w + h - smallest - max(l, max(w, h));

        int ribbon1 = (2 * smallest) + (2 * secondSmallest);
        int ribbon2 = (l * w * h);

        total += ribbon1 + ribbon2;
    }

    cout << "Answer: " << total << endl;

    file.close();

    return EXIT_SUCCESS;
}
