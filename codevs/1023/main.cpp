//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
//clock() 计时
//对数据进行排序后在搜索
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
int N;
int M;
const int MAXN = 100500;
const int MAXB = 5000;
int blocksize;
int blockcnt;
int a[MAXN];
int b[MAXB];
void modify(int position, int number){
    a[position] += number;
    b[(position - 1) / blocksize + 1] += number;
}
int getLimit(int index){
    return (index - 1) / blocksize + 1;
}
void query(int left, int right){
    int leftlim = getLimit(left);
    int rightlim = getLimit(right);
    int plus, minus, big;
    for (int i = left; i <= leftlim * blocksize; ++i){
        plus += a[i];
    }
    for (int i = right+1; i <= rightlim * blocksize; ++i){
        minus += a[i];
    }
    for (int i = leftlim + 1; i <= rightlim; ++i){
        big += b[i];
    }
    #ifdef DEBUG
    printf("%d %d %d \n",plus,big, minus);
    #endif
    printf("%d\n",plus + big - minus);
}
int main(){
    scanf("%d",&N);
    blocksize = int(sqrt(N));
    blockcnt = int(N / blocksize) + 1;
    int temp = 0;
    for (int i = 1; i <= N; ++i){
        scanf("%d",&a[i]);
        if (i % blocksize == 1) ++temp;
        b[temp] += a[i];
    }
    scanf("%d",&M);
    for (int i = 1; i <= M; ++i){
        int action,num1,num2;
        scanf("%d",&action);
        scanf("%d%d",&num1,&num2);
        switch (action){
            case 1: {
                modify(num1,num2);
                break;
            }
            case 2: {
                query(num1,num2);
                break;
            }
        }
        #ifdef DEBUG
        for(int i=1;i<=blockcnt;++i) {
            printf("%d ",b[i]);
        }
        puts("");
        #endif
    }
    return 0;
}
