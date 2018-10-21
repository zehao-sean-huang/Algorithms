#include <bits/stdc++.h>

using namespace std;

// Brute Force

int N, M;

pair<string, string> weighings[20];

char evaluate(char c1, char c2, int i) {
    int left = 0, right = 0;
    if (weighings[i].first.find(c1) != string::npos) {
        left -= 1;
    }
    if (weighings[i].first.find(c2) != string::npos) {
        left -= 1;
    }
    if (weighings[i].second.find(c1) != string::npos) {
        right -= 1;
    }
    if (weighings[i].second.find(c2) != string::npos) {
        right -= 1;
    }
    if (left < right) {
        return '<';
    } else if (left == right) {
        return '=';
    } else if (left > right) {
        return '>';
    }
}

void process(char c1, char c2, char c3, char c4) {
    bool result = true;
    for (int i = 0; i < M; ++i) {
        if (evaluate(c1, c2, i) != evaluate(c3, c4, i)) {
            result = false;
            break;
        }
    }
    if (result) {
        printf("%c%c=%c%c\n", c1, c2, c3, c4);
    }
}

void enumerate() {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            char c1 = char(65 + i);
            char c2 = char(65 + j);
            for (int k = i; k < N - 1; ++k) {
                for (int h = j; h < N; ++h) {
                    char c3 = char(65 + k);
                    char c4 = char(65 + h);
                    if (!(c1 == c3 && c2 == c4)) {
                        process(c1, c2, c3, c4);
                    }
                }
            }
        } 
    }
}

int main() {
    string temps;
    getline(cin, temps);
    N = stoi(temps.substr(0, temps.find(",")));
    M = stoi(temps.substr(temps.find(",") + 1));
    for (int i = 0; i < M; ++i) {
        getline(cin, temps);
        weighings[i].first = temps.substr(0, temps.find("-"));
        weighings[i].second = temps.substr(temps.find("-") + 1);
    }
    enumerate();
    return 0;
}