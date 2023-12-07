#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string tiempostr;
    string distanciastr;

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
        while (iss >> temp)
        {
            tiempostr += temp;
        }
    }

    if (getline(file, line))
    {
        std::istringstream iss(line);
        std::string temp;
        iss >> temp;
        while (iss >> temp)
        {
            distanciastr += temp;
        }
    }

    long long tiempo = stoll(tiempostr);
    long long distancia = stoll(distanciastr);

    int wtb = 0;

    for (long i = 0; i < tiempo; i++)
    {
        long holdTime = i;
        long boatSpeed = holdTime;
        long travelTime = tiempo - holdTime;
        long travelDistance = boatSpeed * travelTime;
        if (travelDistance > distancia)
        {
            wtb++;
        }
    }

    cout << wtb << endl;
}