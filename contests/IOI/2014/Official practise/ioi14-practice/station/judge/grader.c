#ifdef NDEBUG
#undef NDEBUG
#endif
#include<assert.h>
#include<stdio.h>
#include"station.h"

int main()
{
	static int f[500000];
	int n,k;
	assert(scanf("%d%d",&n,&k)==2);
	assert(2<=n&&n<=500000);
	assert(1<=k&&k<=3000);
	for(int i=0;i<n;i++)assert(scanf("%d",f+i)==1&&0<=f[i]&&f[i]<=1);
	assert(f[0]==1&&f[n-1]==1);
	scanf(" ");assert(getchar()==EOF);
	printf("%d\n",findMinDays(n,k,f));
	return 0;
}
