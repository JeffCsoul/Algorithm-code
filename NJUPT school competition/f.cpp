#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int M[12][12];
int L[12];
bool B[12];
int ansl[50000],ansr[50000];
int kl,kr,n,m;
void dfs(int t)
{
    L[1]=1;
    L[t]=n;
    int tot=0;
    for (int i=1;i<t;i++)
        if (M[L[i]][L[i+1]]!=-1)
           tot+=M[L[i]][L[i+1]];
        else
        {
            tot=0;
            break;
        }
    if (tot!=0)
        ansl[++kl]=tot;
    tot=0;
    L[1]=n;
    L[t]=1;
    for (int i=1;i<t;i++)
        if (M[L[i]][L[i+1]]!=-1)
            tot+=M[L[i]][L[i+1]];
        else
        {
            tot=0;
            break;
        }
    if (tot!=0)
        ansr[++kr]=tot;

    if (n==t)  return;
    for (int i=2;i<n;i++)
        if (!B[i])
        {
            L[t]=i;
            B[i]=true;
            dfs(t+1);
            L[t]=0;
            B[i]=false;
        }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(ansl,0,sizeof ansl);
        memset(ansr,0,sizeof ansr);
        kl=kr=0;
        memset(M,0,sizeof M);
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&M[i][j]);
        memset(B,0,sizeof B);
        dfs(2);
        int mkd=-1,dis=2147483647;
        for (int i=1;i<=kl;i++)
            for (int j=1;j<=kr;j++)
            {
                if (abs( ansl[i]+ansr[j] -m)<dis)
                {
                    mkd=ansl[i]+ansr[j];
                    dis=abs(ansl[i]+ansr[j]-m);
                }
            }
        cout<<mkd<<endl;
    }
}
