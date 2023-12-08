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

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

unsigned long long findlcm(vector<unsigned long long> nums)
{
    unsigned long long ans = nums[0];

    for (unsigned int i = 1; i < nums.size(); i++)
    {
        ans = (((nums[i] * ans)) / (gcd(nums[i], ans)));
    }

    return ans;
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

    vector<map<string, pair<string, string>>::iterator> iters;

    for (auto it = datos.begin(); it != datos.end(); it++)
    {
        if (it->first[2] == 'A')
        {
            iters.push_back(it);
        }
    }

    unsigned long long steps = 0;
    int j = 0;

    vector<unsigned long long> stepsC;

    for (int i = 0; i < iters.size(); i++)
    {
        steps = 0;
        while (iters[i] != datos.end() && iters[i]->first[2] != 'Z')
        {
            if (j == rl.size())
                j = 0;

            if (rl[j] == 'R')
            {
                iters[i] = datos.find(iters[i]->second.second);
                steps++;
                j++;
            }
            else if (rl[j] == 'L')
            {
                iters[i] = datos.find(iters[i]->second.first);
                steps++;
                j++;
            }
        }
        stepsC.push_back(steps);
    }

    steps = findlcm(stepsC);

    cout << steps << endl;
}