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
const int maxn=1000006;

int fac[maxn];
int A,B,N,e;

int powc(int a,int b)
{
    if (b==0) return 1;
    int d=powc(a,b/2);
    d=(LL)d*d%bigp;
    if (b%2==1) d=(LL)d*a%bigp;
    return d;
}

int C(int M,int N)
{
    int ans=fac[M];
    ans=(LL)ans*powc(fac[N],bigp-2)%bigp;
    ans=(LL)ans*powc(fac[M-N],bigp-2)%bigp;
    return ans;
}

bool ok(int s)
{
    while (s>0)
    {
        if ((s%10!=A)&&(s%10!=B)) return false;
        s/=10;
    }
    return true;
}

int main()
{
    fac[0]=1;
    for (int i=1;i<maxn;i++) fac[i]=(LL)fac[i-1]*i%bigp;

    while (scanf("%d %d %d",&A,&B,&N)==3)
    {
        int sum=0;
        for (int i=0;i<=N;i++)
        {
            e=A*i+B*(N-i);
            if (ok(e)) sum=(sum+C(N,i))%bigp;
        }
        printf("%d\n",sum);
    }
}
