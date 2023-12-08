#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <sstream>
using namespace std;

pair<string, string> parseValues(const string &values)
{
    size_t comma = values.find(',');
    string first = values.substr(1, comma - 1);
    string second = values.substr(comma + 2, values.size() - comma - 3);

    return {first, second};
}

int main()
{
    ifstream file("input.txt");

    vector<char> rl;

    map<string, pair<string, string>> datos;

    string line;

    if (getline(file, line))
    {
        istringstream iss(line);
        for (char c : line)
        {
            rl.push_back(c);
        }
    }

    getline(file, line);

    while (getline(file, line))
    {
        size_t pos = line.find('=');
        string key = line.substr(0, pos - 1);
        string values = line.substr(pos + 2);
        datos[key] = parseValues(values);
    }

    auto it = datos.find("AAA");

    int i = 0;
    int steps = 0;
    while (it != datos.end() && i <= rl.size() && it->first != "ZZZ")
    {
        if (i == rl.size())
            i = 0;
        if (rl[i] == 'R')
        {
            it = datos.find(it->second.second);
            steps++;
            i++;
        }
        else if (rl[i] == 'L')
        {
            it = datos.find(it->second.first);
            steps++;
            i++;
        }
    }

    cout << steps << endl;
}