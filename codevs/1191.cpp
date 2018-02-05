#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
struct seg{
    public:
    int black_cnt;
    int left;
    int right;
};
int N;
const int MAXN = 200100;
int M;
seg a[4 * MAXN];
void read_nums(){
    scanf("%d %d", &N, &M);
}
int get_mid(int m, int n) {
    return (m + n) / 2;
}
int build(int index, int left, int right){
    a[index].left = left;
    a[index].right = right;
    if (left == right) {
        a[index].black_cnt = 1;
    }
    else {
        int mid = get_mid(left, right);
        a[index].black_cnt = build(2 * index, left, mid) + build(2 * index + 1, mid + 1, right);
    }
    return a[index].black_cnt;
}
int modify(int index, int left, int right){
    if (a[index].black_cnt != 0) {
        if (left == a[index].left && right == a[index].right) {
            a[index].black_cnt = 0;
        }
        else {
            int mid = get_mid(a[index].left, a[index].right);
            if (right <= mid) {
                a[index].black_cnt = modify(2 * index, left, right) + a[2 * index + 1].black_cnt;
            }
            else if (left > mid) {
                a[index].black_cnt = modify(2 * index + 1, left, right) + a[2 * index].black_cnt;
            }
            else {
                a[index].black_cnt = modify(2 * index, left, mid) + modify (2 * index + 1, mid + 1, right);
            }
        }
    }
    return a[index].black_cnt;
}
int main(){
    read_nums();
    build(1,1,N);
    for (int i = 1; i <= M; ++i) {
        int left, right;
        scanf("%d %d",&left,&right);
        printf("%d\n",modify(1, left, right));
    }
    return 0;
}