#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int B, P, S, L, K, F;
map<int, int> ladders;
map<int, int> snakes;
map<int, int> players;

inline int pair_to_coord(int x, int y) {
    if (y == 1 && x == 0) {
        return 0;
    } else if (y == B && x == 0) {
        return B * B + 1;
    } else if (y % 2 == 1) {
        return x + (y - 1) * B;
    } else {
        return (B - x + 1) + (y - 1) * B;
    }
}

string effect(int position) {
    if (snakes.find(position) != snakes.end()) {
        return "snake";
    } else if (ladders.find(position) != ladders.end()) {
        return "ladder";
    } else {
        return "none";
    }
}

bool won(int index) {
    return players[index] > B * B;
}

int next(int previous) {
    while (won(previous + 1)) {
        if (previous == P) {
            previous = 0;
        } else {
            previous += 1;
        }
    } 
    return previous + 1;
}

void play(int index, int dice) {
    int position = players[index];
    position += dice;
    string e = effect(position);
    while (e != "none") {
        if (e == "snake") {
            position = snakes[position];
        } else if (e == "ladder") {
            position = ladders[position];
        }
        e = effect(position);
    }
    players[index] = position;
    if (position > B * B) { // winning
        F -= 1;
    }
}

int main() {
    scanf("%d", &B);
    scanf("%d", &P);
    F = P;
    for (int i = 1; i <= P; ++i) {
        players[i] = 0;
    }
    scanf("%d", &S);
    for (int i = 0; i < S; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        snakes[pair_to_coord(x1, y1)] = pair_to_coord(x2, y2);
    }
    scanf("%d", &L);
    for (int i = 0; i < L; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ladders[pair_to_coord(x1, y1)] = pair_to_coord(x2, y2);
    }
    scanf("%d", &K);
    int player = 1;
    for (int i = 1; i <= K; i++) {
        if (F == 0) {
            break;
        } else {
            player = next(player);
            pair<int, int> dice;
            cin >> dice.first >> dice.second;
            play(player, dice.first + dice.second);
        }
    }
    for (int i = 1; i <= P; i++) {
        if (won(i)) {
            cout << i << " winner" << endl;
        } else {
            int y = int(players[i] / B);
            int x = (y % 2 == 1) ? players[i] - (y - 1) * B : y * B - players[i] + 1;
            cout << i << " " << x << " " << y << endl;
        }
    }
    return 0;
}