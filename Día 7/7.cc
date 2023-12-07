#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> value = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};

pair<int, int> evaluateHand(string hand)
{
    map<char, int> freq;
    for (char c : hand)
        freq[c]++;

    int maxFreq = 0, secondMaxFreq = 0;
    for (auto &p : freq)
    {
        if (p.second > maxFreq)
        {
            secondMaxFreq = maxFreq;
            maxFreq = p.second;
        }
        else if (p.second > secondMaxFreq)
        {
            secondMaxFreq = p.second;
        }
    }
    return {maxFreq, secondMaxFreq};
}

bool compareHands(const pair<string, int> &a, const pair<string, int> &b)
{
    auto aVal = evaluateHand(a.first);
    auto bVal = evaluateHand(b.first);

    if (aVal != bVal)
        return aVal < bVal;

    for (int i = 0; i < a.first.size(); ++i)
    {
        if (value[a.first[i]] != value[b.first[i]])
            return value[a.first[i]] < value[b.first[i]];
    }
    return false;
}

int main()
{
    vector<pair<string, int>> hands;
    ifstream file("input.txt");
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        string hand;
        int bid;
        if (iss >> hand >> bid)
        {
            hands.push_back(make_pair(hand, bid));
        }
    }

    sort(hands.begin(), hands.end(), compareHands);

    long long totalWinnings = 0;
    for (int i = 0; i < hands.size(); ++i)
    {
        totalWinnings += hands[i].second * (i + 1);
    }

    cout << totalWinnings << endl;
    return 0;
}
