#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line;
    string filename = R"(C:\Users\Dan\Desktop\AOC\2015\day01\input.txt)";
    ifstream file(filename);

    if (!file.is_open())
    {
        perror("File not found");
        return EXIT_FAILURE;
    }
    getline(file, line);
    int floor = 0;
    int pos = 1;
    for(char c : line)
    {
        if (c == '(') floor++;
        else if (c == ')') floor--;
        if (floor == -1) break;
        pos++;
    }
    cout << "Position: " << pos << endl;
    file.close();

    return EXIT_SUCCESS;
}
