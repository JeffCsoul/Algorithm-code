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

int powc(int a,int b)
{
    if (b==0) return 1;
    int d=powc(a,b/2);
    d=(LL)d*d%bigp;
    if (b%2==1) d=(LL)d*a%bigp;
    return d;
}

int main()
{
    int T,xc,yc;
    scanf("%d",&T);
    for (int gb=1;gb<=T;gb++)
    {
        scanf("%d %d",&xc,&yc);
        printf("%d\n",powc(xc,yc));
    }
}