#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;


struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        size_t h1 = hash<T1>()(pair.first);
        size_t h2 = hash<T1>()(pair.second);

        return h1 ^ h2;
    }
};

void addPair(unordered_set<pair<int,int>, pair_hash> &s, int &x, int &y)
{
    pair<int, int> p = make_pair(x, y);
    s.insert(p);
}

void moveSanta(unordered_set<pair<int,int>, pair_hash> &s, char c, int &x, int &y)
{
    if (c == '>'){
        x++;
        addPair(s, x, y);
    }
    else if (c == '<'){
        x--;
        addPair(s, x, y);
    }
    else if (c == '^'){
        y++;
        addPair(s, x, y);
    }
    else if (c == 'v'){
        y--;
        addPair(s, x, y);
    }
}

int main()
{
    string line;
    string filename = R"(C:\Users\Dan\Desktop\AOC\2015\day03\input.txt)";
    ifstream file(filename);
    unordered_set<pair<int,int>, pair_hash> s;


    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    if (!file.is_open())
    {
        perror("File not found");
        return EXIT_FAILURE;
    }

    getline(file, line);
    int iteration = 0;
    s.insert(make_pair(0,0));

    for (char c : line)
    {
        if (iteration % 2 == 0)
        {
            moveSanta(s, c, x1, y1);
        }
        else{
            moveSanta(s, c, x2, y2);
        }
        iteration++;
    }

    cout << "Answer: " << s.size()  << endl;

    file.close();

    return EXIT_SUCCESS;
}
