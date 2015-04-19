#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#define MAXM 10100
#define LL long long
#define FOR(i,v)    for (__typeof(v.begin()) i=v.begin();i!=v.end();i++)
using namespace std;

vector <int> V[MAXM];
int t[MAXM],n,m;
LL ans=0;
void DFS(int u,int cur)
{
    if (cur>ans)    ans=cur;
    FOR(v,V[u])
        DFS(*v,cur+t[*v]);
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        for (int i=1;i<=n;i++)
            V[i].clear();
        for (int i=1;i<=n;i++)
            scanf("%d",&t[i]);
        int x,y;
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            V[x].push_back(y);
        }
        DFS(1,t[1]);
        cout<<ans<<endl;
    }
}
