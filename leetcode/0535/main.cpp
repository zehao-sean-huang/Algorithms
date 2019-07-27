#include "../leetcode.h"

using namespace std;

vector<string> urls;

// Encodes a URL to a shortened URL.
string encode(string longUrl) {
    int i = urls.size();
    urls.push_back(longUrl);
    return string(to_string(i));
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
    return urls[stoi(shortUrl)];
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string url = "";
        cin >> url;
        cout << decode(encode(url)) << endl;
    }
    return 0;
}
