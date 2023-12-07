#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    vector<vector<int>> map(2);

    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }

    string line;

    if (getline(file, line))
    {
        std::istringstream iss(line);
        std::string temp;
        iss >> temp;
        int value;
        while (iss >> value)
        {
            map[0].push_back(value);
        }
    }

    if (getline(file, line))
    {
        std::istringstream iss(line);
        std::string temp;
        iss >> temp;
        int value;
        while (iss >> value)
        {
            map[1].push_back(value);
        }
    }

    vector<int> waysToBeat;

    for (int i = 0; i < map[0].size(); i++)
    {
        int wtb = 0;

        for (int j = 0; j < map[0][i]; j++)
        {
            int holdTime = j;
            int boatSpeed = holdTime;
            int travelTime = map[0][i] - holdTime;
            int travelDistance = boatSpeed * travelTime;
            if (travelDistance > map[1][i])
            {
                wtb++;
            }
        }
        waysToBeat.push_back(wtb);
    }

    int result = 1;

    for (int i = 0; i < waysToBeat.size(); i++)
    {
        result *= waysToBeat[i];
    }

    cout << result << endl;
}