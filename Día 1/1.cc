#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream input("input.txt");
    string line;
    int sum = 0;

    while (getline(input, line))
    {
        int firstNumber = -1;
        int lastNumber = -1;

        for(char c : line){
            if(isdigit(c)){
                if(firstNumber == -1){
                    firstNumber = c - '0';
                }
                lastNumber = c - '0';
            }
        }

        if(firstNumber != -1 && lastNumber != -1){
            sum += firstNumber * 10 + lastNumber;
        }
    }

    cout << sum << endl;
}