#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
// Segment Tree Data Structure
struct seg
{
    int value;
    int left;
    int right;
    bool lazy;
    int lazy_value;
};
// Global Variables
int N;
int M;
const int MAXN = 100500;
int a[MAXN];
seg b[3 * MAXN];
// Return the middle value for left and right
int get_mid(int m, int n)
{
    return (m + n) / 2;
}
// Read Data Function
void read_nums()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &M);
}
// Build the segment tree function
int build(int index, int left, int right)
{
    b[index].left = left;
    b[index].right = right;
    b[index].lazy = false;
    b[index].lazy_value = 0;
    if (left == right)
    {
        b[index].value = a[left];
    }
    else
    {
        int mid = get_mid(left, right);
        if (right <= mid)
        {
            b[index].value = build(2 * index, left, right);
        }
        else if (mid < left)
        {
            b[index].value = build(2 * index + 1, left, right);
        }
        else
        {
            b[index].value = build(2 * index, left, mid) + build(2 * index + 1, mid + 1, right);
        }
    }
    return b[index].value;
}
// Modification Action Function
int modify(int index, int left, int right, int value)
{
    if (b[index].left == left && b[index].right == right)
    {
        if (b[index].lazy)
        {
            b[index].lazy_value += value;
        }
        else
        {
            b[index].lazy = true;
            b[index].lazy_value = value;
        }
        b[index].value += (left - right + 1) * value;
    }
    else
    {
        int mid = get_mid(b[index].left, b[index].right);
        if (b[index].lazy)
        {
            b[index].lazy = false;
            b[2 * index].value += b[index].lazy_value * (mid - b[index].left + 1);
            b[2 * index].lazy = true;
            b[2 * index].lazy_value += b[index].lazy_value;
            b[2 * index + 1].value += b[index].lazy_value * (b[index].right - mid);
            b[2 * index + 1].lazy = true;
            b[2 * index + 1].lazy_value += b[index].lazy_value;
        }
        if (right <= mid)
        {
            b[index].value = modify(2 * index, left, right, value) + b[2 * index + 1].value;
        }
        else if (left > mid)
        {
            b[index].value = b[2 * index].value + modify(2 * index + 1, left, right, value);
        }
        else
        {
            b[index].value = modify(2 * index, left, mid, value) + modify(2 * index + 1, mid + 1, right, value);
        }
    }
    return b[index].value;
}
// Query Action Function
int query(int index, int left, int right) ///??????????
{
    return 0;
}
int main()
{
    read_nums();
    build(1, 1, N);
    for (int i = 1; i <= M; ++i)
    {
        int action;
        scanf("%d&", &action);
        switch (action)
        {
        case 1:
        {
            int a, b, X;
            scanf("%d %d %d", &a, &b, &X);
            modify(1, a, b, X);
            break;
        }
        case 2:
        {
            int pos;
            scanf("%d", &pos);
            // printf("%d\n", query(pos)); ////?????????
            break;
        }
        }
    }
    printf("%d\n",b[1].value);
    return 0;
    // cerr << b[1].value << endl;
}