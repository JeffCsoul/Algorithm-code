 #include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define LL long long
#define REP(i,n) for (int i=1;i<=n;i++)
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();i++)

using namespace std;

const int bigp=1000000007;

int N,M,f[1005][1005];
int main()
{
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for (int i=1;i<=1000;i++)
    {
        f[i][0]=1;
        for (int j=1;j<=min(1000,i);j++)
            f[i][j]=(f[i-1][j]+f[i][j-1])%bigp;
    }
    while (scanf("%d%d",&N,&M)!=EOF)
    {
        printf("%d\n",f[N][M]);
    }
}

