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

int TT,N,M,xc,yc,flag,jc,kc;
int f[105][105],a[105];

int main()
{
    scanf("%d",&TT);
    for (int gb=1;gb<=TT;gb++)
    {
        scanf("%d %d",&N,&M);
        memset(f,0,sizeof(f));
        for (int i=1;i<=M;i++)
        {
            scanf("%d %d",&xc,&yc);
            f[xc][yc]++;
            f[yc][xc]++;
        }
        for (int i=0;i<=N;i++) a[i]=i;
        while (a[0]==0)
        {
            flag=1;
            for (int i=1;i<N;i++)
                if (f[a[i]][a[i+1]]==0) flag=0;
            if (f[a[N]][a[1]]==0) flag=0;
            if (flag==1)
            {
                for (int i=1;i<=N;i++) cout<<a[i]<<" ";
                cout<<"1"<<endl;
                break;
            }
            jc=N;
            while (a[jc-1]>a[jc]) --jc;
            kc=N;
            while (a[jc-1]>a[kc]) --kc;
            swap(a[jc-1],a[kc]);
            for (int p=jc;p<=(jc+N)/2;p++) swap(a[p],a[N+jc-p]);
        }
    }
}