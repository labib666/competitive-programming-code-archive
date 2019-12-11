#ifdef NDEBUG
#undef NDEBUG
#endif
#include<cassert>
#include<cstdio>
#include<cstdlib>
#include"tile.h"

static inline int max(int a,int b,int c)
{
	if(b>a)a=b;
	if(c>a)a=c;
	return a;
}

static inline int min(int a,int b,int c)
{
	if(b<a)a=b;
	if(c<a)a=c;
	return a;
}

static void bye()
{
	puts("incorrect.");
	exit(0);
}

static int s;

static inline void checkxy(int x,int y)
{
	static char f[256][256];
	if(x<0||x>=s||y<0||y>=s||f[x][y]!=0)bye();
	f[x][y]=1;
}

static void check(int x1,int y1,int x2,int y2,int x3,int y3)
{
	checkxy(x1,y1);
	checkxy(x2,y2);
	checkxy(x3,y3);
	if(max(x1,x2,x3)!=min(x1,x2,x3)+1)bye();
	if(max(y1,y2,y3)!=min(y1,y2,y3)+1)bye();
	if(x1==x2&&y1==y2)bye();
	if(x1==x3&&y1==y3)bye();
	if(x2==x3&&y2==y3)bye();
}

int main()
{
	static int t[21845][6];
	int n,x,y;
	assert(scanf("%d%d%d",&n,&x,&y)==3);
	assert(1<=n&&n<=8);
	s=1<<n;
	assert(0<=x&&x<s);
	assert(0<=y&&y<s);
	placeTile(n,x,y,t);
	const int m=s*s/3;
	for(int i=0;i<m;i++)check(t[i][0],t[i][1],t[i][2],t[i][3],t[i][4],t[i][5]);
	puts("correct.");
	return 0;
}
