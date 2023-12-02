#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ifstream input("input.txt", ios::in);

    long long totalPowerSum = 0;
    string line;
    while (getline(input, line))
    {
        string word;
        int number = 0;
        int id = 0;
        int pos = line.find("Game");
        if (pos != string::npos)
        {
            line.erase(0, pos + 5);
        }

        // Read the number of the game
        while (isdigit(line[0]))
        {
            id = id * 10 + (line[0] - '0');
            line.erase(0, 1);
        }

        line.erase(0, 2);
        line.append(";");

        map<string, int> color_counter;
        map<string, int> min_cubes = {{"red", 0}, {"green", 0}, {"blue", 0}};

        for (int i = 0; i < line.length(); ++i)
        {
            if (isdigit(line[i]))
            {
                while (isdigit(line[i]))
                {
                    number = number * 10 + (line[i] - '0');
                    i++;
                }
            }
            else if (line[i] == ',' || line[i] == ' ' || line[i] == ';')
            {
                color_counter[word] += number;
                if (word != "")
                {
                    min_cubes[word] = max(min_cubes[word], color_counter[word]);
                    color_counter[word] = 0;
                }
                word = "";
                number = 0;
            }
            else
            {
                word += line[i];
            }
        }

        int power = 1;
        for (const auto &pair : min_cubes)
        {
            power *= pair.second;
        }
        totalPowerSum += power;
    }

    cout << "Sum of the power of the minimum sets: " << totalPowerSum << endl;

    return 0;
}
