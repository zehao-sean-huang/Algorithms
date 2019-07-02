#include "../leetcode.h"

using namespace std;

class NumArray {
private:
    vector<int> result;
public:
    NumArray(vector<int> nums) {
        result.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(result[i] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return result[j + 1] - result[i];
    }
};

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        NumArray a = NumArray(readVector(readNumber()));
        int n = readNumber();
        while (n--) {
            cout << a.sumRange(readNumber(), readNumber()) << endl;
        }
    }
    return 0;
}