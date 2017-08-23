#include <iostream>
#include <string>
void printAllBinary(string &result, int &size) {
    if (result.size() == size) {
        cout << result << endl;
        return;
    }
    result += "0";
    printAllBinary(result,size);
    result = result.substr(0,result.size()-1);
    result += "1";
    printAllBinary(result,size);
    result = result.substr(0,result.size()-1);
    return;
}
void printAllBinary(int size) {
    if (size < 0) return;
    string result;
    printAllBinary(result, size);
}