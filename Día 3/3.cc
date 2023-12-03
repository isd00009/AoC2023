#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool esSimbolo(char c)
{
    return c == '*' || c == '-' || c == '$' || c == '#' || c == '@' || c == '&' || c == '=' || c == '+' || c == '/' || c == '%';
}

int main()
{
    freopen("input.txt", "r", stdin);

    vector<string> esquema;
    int suma = 0;
    string line;

    while (getline(cin, line))
    {
        esquema.push_back(line);
    }

    for (int i = 0; i < esquema.size(); ++i)
    {
        for (int j = 0; j < esquema[i].size(); ++j)
        {
            if (isdigit(esquema[i][j]))
            {
                stringstream ss;
                int comienzo = j;
                while (j < esquema[i].size() && isdigit(esquema[i][j]))
                {
                    ss << esquema[i][j];
                    ++j;
                }
                int num;
                ss >> num;
                bool haySimbolo = false;
                for (int k = comienzo; k < j; ++k)
                {
                    for (int l = 0; l < 8; ++l)
                    {
                        int x = i + dx[l];
                        int y = k + dy[l];
                        if (x >= 0 && x < esquema.size() && y >= 0 && y < esquema[x].size() && esSimbolo(esquema[x][y]))
                        {
                            haySimbolo = true;
                            break;
                        }
                    }
                    if (haySimbolo)
                        break;
                }
                if (haySimbolo)
                    suma += num;
            }
        }
    }

    cout << suma << endl;
}