#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int h,w,a,b;
        cin>>h>>w>>a>>b;
        double len;
        len=sqrt(h*h+w*w);
        if (min(a,b)<=len)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
