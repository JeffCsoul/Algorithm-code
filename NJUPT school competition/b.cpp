#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

char s[5000];
int T,len;
int main()
{
    scanf("%d",&T);
    for (int x=1;x<=T;x++)
    {
        memset(s,0,sizeof s);
        scanf("%s",s);
        len=strlen(s);
        printf("Case #%d:\n",x);
        for (int i=0;i<=len;i++)
        {
            if (s[i]=='a'&&s[i+1]=='s'&&s[i+2]=='k')
            {
                printf("love");
                if (s[i+3]=='e'&&s[i+4]=='d')
                    printf("d");
                printf("\n");
            }
        }
    }
    return 0;
}
