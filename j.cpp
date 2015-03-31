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

int N,M,ans,s1,s2,jc,x[105],y[105],b[105];
int main()
{
    while (scanf("%d %d",&N,&M)==2)
    {
        for (int i=1;i<=N;i++) scanf("%d %d",&x[i],&y[i]);
        memset(b,0,sizeof(b));
        ans=0;
        while (b[0]==0)
        {
            s1=s2=0;
            for (int i=1;i<=N;i++)
            {
                if (b[i]==1) s1++; else if (b[i]==2) s1+=3;
                if (b[i]==1) s2+=max(0,y[i]-x[i]); else if (b[i]==2) s2+=max(0,y[i]-x[i]+1);
            }
            if (s2<=M) ans=max(ans,s1);
            jc=N;
            while (b[jc]==2)
            {
                b[jc]=0;
                --jc;
            }
            ++b[jc];
        }
        printf("%d\n",ans);
    }
}
