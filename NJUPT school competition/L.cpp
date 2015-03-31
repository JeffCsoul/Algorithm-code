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

const int biglongint=2139062143;

int TT,N,ans,f[405][4005],a[405],b[405];

int main()
{
    scanf("%d",&TT);
    for (int gb=1;gb<=TT;gb++)
    {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) scanf("%d",&a[i]);
        for (int i=1;i<=N;i++) scanf("%d",&b[i]);
        memset(f,127,sizeof(f));
        f[0][0]=0;
        for (int i=0;i<N;i++)
            for (int j=0;j<=N*10;j++)
                if (f[i][j]!=biglongint)
                {
                    f[i+1][j+a[i+1]]=min(f[i+1][j+a[i+1]],f[i][j]+1);
                    if (j>=b[i+1]) f[i+1][j-b[i+1]]=min(f[i+1][j-b[i+1]],f[i][j]);
                }
        ans=biglongint;
        for (int j=0;j<=N*10;j++) ans=min(ans,f[N][j]);
        printf("%d\n",ans);
    }
}
