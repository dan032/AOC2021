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

    for(char c : line)
    {
        if (c == '(') floor++;
        else if (c == ')') floor--;
    }
    cout << "Floor: " << floor << endl;
    file.close();

    return EXIT_SUCCESS;
}
