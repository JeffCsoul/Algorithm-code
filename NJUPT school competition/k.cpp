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

const int maxlongint=2147483647;

int f[15][15][15][15][15][2];
int TT,N,A,B,C,D;

int dfs(int N,int A,int B,int C,int D,int flag)
{
    if ((N<0)||(A<0)||(B<0)||(C<0)||(D<0)) return -maxlongint;
    if (N==0) return 0;
    if (f[N][A][B][C][D][flag]!=-maxlongint) return f[N][A][B][C][D][flag];
    f[N][A][B][C][D][flag]=0;
    f[N][A][B][C][D][flag]=max(f[N][A][B][C][D][flag],dfs(N-2,A-1,B,C,D,1)+3);
    if (flag==0)
    f[N][A][B][C][D][flag]=max(f[N][A][B][C][D][flag],dfs(N-1,A,B-1,C,D,1));
    else
    f[N][A][B][C][D][flag]=max(f[N][A][B][C][D][flag],dfs(N-1,A,B-1,C,D,1)+4);
    f[N][A][B][C][D][flag]=max(f[N][A][B][C][D][flag],dfs(N-4,A,B,C-1,D,flag)+6);
    f[N][A][B][C][D][flag]=max(f[N][A][B][C][D][flag],dfs(N-10,A,B,C,D-1,flag)+10);
    //cout<<N<<" "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<flag<<"    "<<f[N][A][B][C][D][flag]<<endl;
    return f[N][A][B][C][D][flag];
}

int main()
{
    for (int i=0;i<=10;i++)
        for (int j=0;j<=10;j++)
            for (int k=0;k<=10;k++)
                for (int s=0;s<=10;s++)
                    for (int e=0;e<=10;e++)
                        f[i][j][k][s][e][0]=f[i][j][k][s][e][1]=-maxlongint;
    scanf("%d",&TT);
    for (int gb=1;gb<=TT;gb++)
    {
        scanf("%d",&N);
        scanf("%d %d %d %d",&A,&B,&C,&D);
        printf("%d\n",dfs(N,A,B,C,D,0));
    }
}
