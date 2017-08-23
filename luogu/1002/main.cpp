#include<iostream>
#include<cstdio>
long long a,b,n,m,l[22][22],map[23][23];
using namespace std;
void bj(long long x,long long y)
{
    map[x][y]=1;
    map[x-1][y-2]=1;
    map[x-2][y-1]=1;
    map[x-2][y+1]=1;
    map[x-1][y+2]=1;
    map[x+1][y-2]=1;
    map[x+2][y-1]=1;
    map[x+2][y+1]=1;
    map[x+1][y+2]=1;
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
    bj(a,b);
    l[1][0]=1;//为了把应该有一步的一步给过去
    for(int i=1;i<=n+1;++i)
    {
        for(int j=1;j<=m+1;++j)
        {
            l[i][j]=l[i-1][j]+l[i][j-1];//一个点的路径来自左方与上方
            if(map[i-1][j-1]) l[i][j]=0;//如果被马控制那么是0
        }
    }
    printf("%lld",l[n+1][m+1]);//整体向右下挪一下
    return 0;
}