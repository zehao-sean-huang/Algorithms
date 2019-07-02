#include "../leetcode.h"

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    map<char, string> codes;
    set<string> morse;
    codes['A'] = ".-"; codes['a'] = ".-";
    codes['B'] = "-..."; codes['b'] = "-...";
    codes['C'] = "-.-."; codes['c'] = "-.-.";
    codes['D'] = "-.."; codes['d'] = "-..";
    codes['E'] = "."; codes['e'] = ".";
    codes['F'] = "..-."; codes['f'] = "..-.";
    codes['G'] = "--."; codes['g'] = "--.";
    codes['H'] = "...."; codes['h'] = "....";
    codes['I'] = ".."; codes['i'] = "..";
    codes['J'] = ".---"; codes['j'] = ".---";
    codes['K'] = "-.-"; codes['k'] = "-.-";
    codes['L'] = ".-.."; codes['l'] = ".-..";
    codes['M'] = "--"; codes['m'] = "--";
    codes['N'] = "-."; codes['n'] = "-.";
    codes['O'] = "---"; codes['o'] = "---";
    codes['P'] = ".--."; codes['p'] = ".--.";
    codes['Q'] = "--.-"; codes['q'] = "--.-";
    codes['R'] = ".-."; codes['r'] = ".-.";
    codes['S'] = "..."; codes['s'] = "...";
    codes['T'] = "-"; codes['t'] = "-";
    codes['U'] = "..-"; codes['u'] = "..-";
    codes['V'] = "...-"; codes['v'] = "...-";
    codes['W'] = ".--"; codes['w'] = ".--";
    codes['X'] = "-..-"; codes['x'] = "-..-";
    codes['Y'] = "-.--"; codes['y'] = "-.--";
    codes['Z'] = "--.."; codes['z'] = "--..";
    for (string& word : words) {
        string result = "";
        for (char c : word) {
            result += codes[c];
        }
        morse.insert(result);
    }
    return morse.size();
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int n = readNumber();
    vector<string> words = readStringVector(n);
    cout << uniqueMorseRepresentations(words) << endl;
    return 0;
}