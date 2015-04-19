#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

double f[60][60];
int n,m,k;
double p;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%lf",&n,&m,&k,&p);
        memset(f,0,sizeof f);
        f[0][1]=1.0;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
            {
                if (j!=1)
                    f[i][j]+=f[i-1][j-1]*(p);
                else
                    f[i][j]+=f[i-1][n]*(p);

                if (j!=n)
                    f[i][j]+=f[i-1][j+1]*(1-p);
                else
                    f[i][j]+=f[i-1][1]*(1-p);
            }
        printf("%.6f\n",f[m][k]);
    }
}
