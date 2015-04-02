#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#define LL long long
#define REP(i,n) for (int i=1;i<=n;i++)
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();i++)

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int TT;
char ctmp;
bool flg;
bool M[30][30];
bool B[30][30];
int bi,bj,ei,ej,n,m,t;
struct qnode
{
	int x,y,stp;
	qnode()	{}
	qnode(int _x,int _y,int _stp)
	{
		x=_x;	y=_y;	stp=_stp;
	}
}tmp;
queue <qnode> Q;
int main()
{
	cin>>TT; 
	while (TT--)
	{
		while (!Q.empty())	Q.pop();
		memset(M,0,sizeof M);
		memset(B,0,sizeof B);
		flg=false;
		scanf("%d%d%d",&n,&m,&t);
		getchar();
		REP(i,n)
		{
			REP(j,m)
			{
				ctmp=getchar();
				if (ctmp=='.'||ctmp=='O'||ctmp=='X')
					M[i][j]=1;
				if (ctmp=='*')	
					M[i][j]=0;
				if (ctmp=='O')	//end
					ei=i,ej=j;
				if (ctmp=='X')	//begin
					bi=i,bj=j;
			}
			getchar();
		}
		Q.push(qnode(bi,bj,0));
		for (;!Q.empty();Q.pop())
		{
			tmp=Q.front();
			int tx,ty;
			if (tmp.x==ei&&tmp.y==ej&&tmp.stp<=t)	flg=true;
			for (int i=0;i<4;i++)
			{
				tx=tmp.x+dx[i];	ty=tmp.y+dy[i];
				if (!B[tx][ty]&&M[tx][ty])
				{
					Q.push(qnode(tx,ty,tmp.stp+1));
					B[tx][ty]=1;
				}
			}
		}
		if (flg)
			puts("happy end");
		else
			puts("bad end");
	}
}


