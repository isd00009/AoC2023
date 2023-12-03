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

void buscaNumerosAdyacentes(const vector<string> &esquema, int i, int j, int &num1, int &num2)
{
    bool primeroEncontrado = false;

    for (int k = 0; k < 8; ++k)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if (x >= 0 && x < esquema.size() && y >= 0 && y < esquema[x].size() && isdigit(esquema[x][y]))
        {
            string numStr1;
            int y1 = y;
            while (y1 >= 0 && isdigit(esquema[x][y1]))
            {
                numStr1 = esquema[x][y1] + numStr1;
                --y1;
            }

            string numStr2;
            int y2 = y + 1;
            while (y2 < esquema[x].size() && isdigit(esquema[x][y2]))
            {
                numStr2 += esquema[x][y2];
                ++y2;
            }

            string numStr = numStr1 + numStr2;
            int num = stoi(numStr);

            if (!primeroEncontrado)
            {
                num1 = num;
                primeroEncontrado = true;
            }
            else if (num != num1)
            {
                num2 = num;
                break;
            }
        }
    }
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
            int num1 = -1;
            int num2 = -1;
            if (esquema[i][j] == '*')
            {
                buscaNumerosAdyacentes(esquema, i, j, num1, num2);
                if (num1 != -1 && num2 != -1)
                {
                    suma += num1 * num2;
                }
            }
        }
    }

    cout << suma << endl;
}
