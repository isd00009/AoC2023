#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> lines;

vector<int> parseLine(string &line)
{
    vector<int> values;
    stringstream ss(line);
    int n;

    while (ss >> n)
    {
        values.push_back(n);
    }

    return values;
}

bool zerosUpToN(vector<int> line, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (line[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int extrapolate(vector<int> line, int n)
{
    int sum = 0;
    for (int i = 0; i < line.size(); i++)
    {
        sum += line[i];
    }
    return sum;
}

int extrapolateLine(string line)
{
    cout << line << endl;
    vector<int> parsedLine = parseLine(line);
    int n = parsedLine.size();

    while (!zerosUpToN(parsedLine, n))
    {
        for (int i = 0; i < n - 1; i++)
        {
            parsedLine[i] = parsedLine[i + 1] - parsedLine[i];
            cout << parsedLine[i] << " ";
        }
        n--;
        cout << endl;
    }
    return extrapolate(parsedLine, n);
}

long extrapolateAll()
{
    long sum = 0;
    for (string line : lines)
    {
        sum += extrapolateLine(line);
    }
    return sum;
}

int main()
{
    ifstream file("input.txt");

    string line;

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    file.close();

    long sum = 0;

    sum = extrapolateAll();

    cout << sum << endl;
}