#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    vector<int> winningNumbers;
    vector<int> myNumbers;
    string line;
    int points = 0;
    int totalPoints = 0;
    int cont = 0;

    while (getline(cin, line))
    {
        cont++;
        points = 0;
        winningNumbers.clear();
        myNumbers.clear();
        string lineAux = line;
        if (line.find("Card") != string::npos)
        {
            int pos = line.find(":");
            line = line.substr(pos + 1);
            pos = line.find("|");
            line = line.substr(0, pos);
            stringstream ss(line);
            int num;
            while (ss >> num)
            {
                winningNumbers.push_back(num);
            }

            pos = lineAux.find("|");
            lineAux = lineAux.substr(pos + 1);
            stringstream ss2(lineAux);
            while (ss2 >> num)
            {
                myNumbers.push_back(num);
            }
        }
        int veces = 0;
        for (int i = 0; i < myNumbers.size(); i++)
        {
            for (int j = 0; j < winningNumbers.size(); j++)
            {
                if (myNumbers[i] == winningNumbers[j])
                {
                    veces++;
                }
            }
        }

        points = pow(2, veces - 1);
        cout << "Card " << cont << " is worth " << points << " points." << endl;

        totalPoints += points;
    }

    cout << totalPoints << endl;
}
