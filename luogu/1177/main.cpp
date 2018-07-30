#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int a[100005];

void sort(int *a, int l, int r) {
    int middle;
    int i = l, j = r;
    middle = a[(l + r) >> 1];
    do {
        while (a[i] < middle) {
            i++;
        }
        while (a[j] > middle) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    } while (i <= j);
    if (l < j) {
        sort(a, l, j);
    }
    if (i < r) {
        sort(a, i, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, 0, n - 1);
    printf("%d", a[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", a[i]);
    }
    printf("\n");
    return 0;
}