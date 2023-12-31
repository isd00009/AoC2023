#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    map<string, int> color_limits = {{"red", 12}, {"green", 13}, {"blue", 14}};

    ifstream input("input.txt", ios::in);

    int suma = 0;
    string line;
    while (getline(input, line))
    {
        string word;

        int number = 0;
        map<string, int> color_counter;

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
        bool possible = true;

        for (int i = 0; i < line.length() && possible; ++i)
        {
            color_counter.clear();
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
                    if (color_counter[word] > color_limits.at(word))
                    {
                        possible = false;
                    }
                }
                word = "";
                number = 0;
            }
            else
            {
                word += line[i];
            }
        }
        if (possible)
        {
            suma += id;
        }
    }

    cout << "Solucion: " << suma << endl;

    return 0;
}