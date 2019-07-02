#include "../leetcode.h"

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() && nums2.empty()) return 0;
    int m = nums1.size(), n = nums2.size();
    int arr[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m) {
        if (j >= n) arr[k++] = nums1[i++];
        else if (nums1[i] < nums2[j]) arr[k++] = nums1[i++];
        else arr[k++] = nums2[j++];
    }
    while (j < n) arr[k++] = nums2[j++];
    if ((m + n) % 2) return arr[(m + n) / 2];
    else return (arr[(m + n) / 2] + arr[(m + n) / 2 - 1]) / 2.0;
}

int main() {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<int> nums1 = readVector();
        vector<int> nums2 = readVector();
        cout << findMedianSortedArrays(nums1, nums2) << endl;
    }
    return 0;
}
