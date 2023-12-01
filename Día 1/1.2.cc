#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int findDigit(const std::string &line, int pos)
{
    if (line[pos] >= '0' && line[pos] <= '9')
        return line[pos] - '0';

    if (line.substr(pos, 4) == "zero")
        return 0;
    if (line.substr(pos, 3) == "one")
        return 1;
    if (line.substr(pos, 3) == "two")
        return 2;
    if (line.substr(pos, 5) == "three")
        return 3;
    if (line.substr(pos, 4) == "four")
        return 4;
    if (line.substr(pos, 4) == "five")
        return 5;
    if (line.substr(pos, 3) == "six")
        return 6;
    if (line.substr(pos, 5) == "seven")
        return 7;
    if (line.substr(pos, 5) == "eight")
        return 8;
    if (line.substr(pos, 4) == "nine")
        return 9;
    return -1;
}

int main()
{
    ifstream file;
    file.open("input.txt");

    if (!file.is_open())
    {
        cout << "File not found!" << endl;
        return 1;
    }

    int suma = 0;

    while (!file.eof())
    {
        string line;
        getline(file, line);

        int first = -1;
        int last = -1;

        int i = 0;
        while (i < line.length() && first == -1) {
            first = findDigit(line, i);
            i++;
        }

        i = line.length() - 1;
        while (i >= 0 && last == -1) {
            last = findDigit(line, i);
            i--;
        }

        if(first != -1 && last != -1){
            suma += first*10 + last;
        }
    }

    cout << "Suma: " << suma << endl;

    return 0;
}