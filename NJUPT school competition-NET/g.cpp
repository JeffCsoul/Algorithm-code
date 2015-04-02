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

const int maxn=100005;

int prime[maxn],u[maxn],ff[maxn];
int mt,ct,TT,N,sc;

int main()
{
    int m=100000;
    prime[1]=1;
    for (int i=2;i<=m;i++)
        if (prime[i]==0)
        {
            mt=m/i;
            for (int j=i;j<=mt;j++)
                prime[j*i]=i;
        }
    memset(u,0,sizeof(u));
    u[1]=1;
    for (int i=2;i<=m;i++)
    {
        if (prime[i]==0)
        {
            u[i]=-1;
            continue;
        }
        ct=i/prime[i];
        if (ct%prime[i]==0) u[i]=0; else u[i]=u[ct]*(-1);
    }
    scanf("%d",&TT);
    for (int gb=1;gb<=TT;gb++)
    {
        scanf("%d",&N);
        memset(ff,0,sizeof(ff));
        LL ans=0;
        for (int i=1;i<=N;i++)
        {
            scanf("%d",&sc);
            for (int j=1;j*j<=sc;j++)
            {
                if (sc%j==0) ++ff[j],++ff[sc/j];
                if (j*j==sc) --ff[j];
            }
        }
        for (int i=1;i<=m;i++)
            if (u[i]!=0)
                ans=(LL)ans+(LL)u[i]*((LL)ff[i]*(ff[i]-1)/2);
        cout<<ans<<endl;
    }
}
