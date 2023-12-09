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

int extrapolate_2(vector<int> line)
{
    int sum = 0;
    for (int i = line.size() - 2; i >= 0; i--)
    {
        sum = line[i] - sum;
    }
    cout << sum << endl;
    return sum;
}

int extrapolateLine(string line)
{
    vector<int> parsedLine = parseLine(line);
    vector<int> indexZero = {parsedLine[0]};
    int n = parsedLine.size();

    while (!zerosUpToN(parsedLine, n))
    {
        for (int i = 0; i < n - 1; i++)
        {
            parsedLine[i] = parsedLine[i + 1] - parsedLine[i];
        }
        indexZero.push_back(parsedLine[0]);
        n--;
    }
    for (int i = 0; i < indexZero.size(); i++)
    {
        cout << indexZero[i] << " ";
    }
    cout << endl;
    return extrapolate_2(indexZero);
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