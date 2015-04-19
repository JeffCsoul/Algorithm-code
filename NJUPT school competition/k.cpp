#include <cstdio>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;

int cnt;
int n;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        LL ans=0;
        scanf("%d",&n);
        ans=n;
        int x,y;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            ans+=x+y;
        }
        if (ans%2==0)
            puts("B");
        else
            puts("D");
    }
}
