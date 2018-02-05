#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
struct seg{
    int left;
    int right;
    int value;
    bool lazy;
    int lazy_value;
};
int N;
int Q;
void read_num(){
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i){
        scanf("%d")
    }
}