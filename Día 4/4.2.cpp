#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    vector<int> cards;
    vector<int> solution;
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

        cards.push_back(veces);
    }

    for (int i = 0; i < cards.size(); i++)
        cout << cards[i] << " ";

    solution.resize(cards.size());
    for (int i = 0; i < cards.size(); i++)
    {
        solution[i] = 1;
    }

    cout << endl;

    for (int i = 0; i < cards.size(); i++)
        cout << solution[i] << " ";

    for (int i = 0; i < cards.size(); i++)
    {
        for (int j = i + 1; j < i + 1 + cards[i]; j++)
        {
            solution[j] += solution[i];
        }
    }

    for (int i = 0; i < solution.size(); i++)
    {
        totalPoints += solution[i];
    }

    cout << endl;

    for (int i = 0; i < cards.size(); i++)
        cout << solution[i] << " ";

    cout << "\n"
         << totalPoints << endl;
}