#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<string> lines;
vector<pair<string, int>> hands;
map<char, int> value = {{'A', 14}, {'K', 13}, {'Q', 12}, {'T', 10}, {'9', 9},
                        {'8', 8},  {'7', 7},  {'6', 6},  {'5', 5},  {'4', 4},
                        {'3', 3},  {'2', 2},  {'J', 1}};

void parse_lines(vector<string> input) {
    for (const auto &currline : input) {
        size_t spacePos = currline.find(" ");
        string cards = currline.substr(0, spacePos);
        int bid = stoi(currline.substr(spacePos + 1));
        hands.push_back(make_pair(cards, bid));
    }
}

pair<int, int> repeated_chars(string input) {
    map<char, int> char_count;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != 'J') {  
            char_count[input[i]]++;
        }
    }
    int max = 0;
    int second_max = 0;
    for (auto it = char_count.begin(); it != char_count.end(); it++) {
        if (it->second > max) {
            second_max = max;
            max = it->second;
        } else if (it->second > second_max && it->second <= max) {
            second_max = it->second;
        }
    }
    return {max, second_max};
}

int num_of_jokers(string input) {
    int count = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'J') {
            count++;
        }
    }
    return count;
}

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    auto a_chars = repeated_chars(a.first);
    auto b_chars = repeated_chars(b.first);
    int a_jokers = num_of_jokers(a.first);
    int b_jokers = num_of_jokers(b.first);

    int new_max_a = a_chars.first + a_jokers;
    int new_max_b = b_chars.first + b_jokers;

    if (new_max_a != new_max_b) {
        return new_max_a < new_max_b;
    }

    if (new_max_b == new_max_a && new_max_b == 3) {
        // is a full house?
        if (a_chars.second != b_chars.second) {
            return a_chars.second < b_chars.second;
        }
    }
    if (new_max_b == new_max_a && new_max_b == 2) {
        // is a two pair?
        if (a_chars.second != b_chars.second) {
            return a_chars.second < b_chars.second;
        }
    }

    // If still tied, compare based on individual card values
    for (int i = 0; i < a.first.size(); i++) {
        if (value.at(a.first[i]) != value.at(b.first[i])) {
            return value.at(a.first[i]) < value.at(b.first[i]);
        }
    }
    return false;
}

int main() {

    int sum = 0;
    string currline;
    ifstream myfile("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile, currline)) {
            lines.push_back(currline);
        }
        myfile.close();
    }

    parse_lines(lines);
    sort(hands.begin(), hands.end(), cmp);
    for (int i = 0; i < hands.size(); i++) {
        cout << hands[i].first << " " << hands[i].second << endl;
        sum += hands[i].second * (i + 1);
    }
    cout << sum << endl;
    return 0;
}
