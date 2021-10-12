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

        int s1 = l * w;
        int s2 = w * h;
        int s3 = h * l;
        int smallest = min(s1, min(s2, s3));
        total += (2*s1 + 2*s2 + 2*s3 + smallest);
    }

    cout << "Answer: " << total << endl;

    file.close();

    return EXIT_SUCCESS;
}
