#include "../leetcode.h"

using namespace std;

int myAtoi(string str) {
    int result = 0;
    // boolean to hold if the number is a negative number
    bool isNegative = false;
    // boolean to hold if we strictly must expect a number
    bool expectNumber = false;
    // iterate over string
    for(auto it = str.begin(); it != str.end(); ++it) {
        // if we did not expect a digit and there is trailing whitespace continue
        if(*it == ' ' && expectNumber == false) {
            continue;
        } else {
            // get the current character index so that we can convert it to number
            int charIdx = *it - '0';
            if(charIdx >= 0 && charIdx <= 9) { // if we have encountered a number
                expectNumber = true;
                // do boundary check
                if(result > INT_MAX / 10 || ((result == (INT_MAX / 10)) && (charIdx > 7))) {
                    if(isNegative == true) { // if we have encountered a negative sign before, return INT_MIN
                        return INT_MIN;
                    }
                    return INT_MAX;
                }                  
                // update our result
                result = (result * 10) + charIdx;
            } else if((*it == '+' || *it == '-') && expectNumber == false) {
                // if we have encountered a sign character and we did not expect a character
                // update the sign flag and expect numbers from now on
                expectNumber = true;
                isNegative = (*it == '-');
            } else {
                // we were expecting a number but instead we have encountered something else so break the loop
                break;
            }
        }
        // at this point we can consider there was no white space or signs or numbers, so continue to iterate
    }
    if(isNegative == true) {
        // check if we have encountered a negative sign
        return result * -1;
    }
    return result;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = "";
        while (s.empty()) getline(cin, s);
        cout << myAtoi(s) << endl;
    }
    return 0;
}
