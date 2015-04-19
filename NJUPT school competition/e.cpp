#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define LL long long
#define MOD 1000000007
using namespace std;

LL n,ans;

LL pw(LL a,LL i)
{
    if (i==0)       return 1%MOD;
    LL tmp=pw(a,i>>1);
    tmp=tmp*tmp%MOD;
    if (i&1)    tmp=(LL) tmp*a%MOD;
    return tmp%MOD;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n;
        LL p1=(( (pw(2,n+1)*(n%MOD))%MOD ) *(n%MOD) )%MOD;
        LL p2=pw(2,n+3);
        LL m1=(((pw(2,n+1)*(n%MOD))%MOD)*3)%MOD;
        m1=(LL) MOD - m1;
        LL m2=MOD - 8;
        LL ans=(p1+p2)%MOD;
        ans=(ans + m1 + m2)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
