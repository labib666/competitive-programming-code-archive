/*
Treasure
http://cerberus.delos.com:790/trainprobs2?p=0469&a=U7hm3fua8rP
*/

/*Seeing a huge limit of X and Y and N≤=1000 we can easily come to conclusion
that we need a N^2 dp solution.

It is quite obvious that when we select a treasure then actually we are
selecting a triangle having pick at that point and base on y=-1.

From now on, I will consider base is y=1. (We just make: y[i]=-y[i] for our
convenience.)

Now the solution may not seem trivial in the first glance. So we start drawing
some pyramids. We need some kinds of ordering to run the dp. So seeing some
figure we can decide to sort by a diagonal of the pyramid. Say we are sorting
by: x-y diagonal, and if some two have same x-y diagonal then we sort them by
y value.

Now if we consider A and B two pyramids(A comes before B in sorted list) then
there can be 3 cases:

1. B is inside A.
2. B is completely right of A (does not intersect)
3. B intersects A.

(If A is inside B then we will consider B intersects A)

this 3 condition can be checked with the help of 4 variables for each pyramid:

left diagonal (x-y)
right diagonal (x+y)
left end point (the left point of pyramid on y=1)
right end point (the right point of pyramid on y=1)

For case 1, just add the treasure to A.
For case 2 and 3, check whether taking A with B is optimal or not.

Be careful when computing the intersection area! There are two types of
intersection: (1-3-5-7... (y*y)) and (2-4-6-8... y*(y+1))

Here is my code implementing the above idea: */

#include<stdio.h>
#include<algorithm>
using namespace std;

int dp[2000];
int d1[2000],d2[2000];
int left[2000],right[2000];

struct TREASURE
{
	int x,y,p;
}T[2000];

bool operator<(TREASURE A, TREASURE B)
{
	if(A.x-A.y < B.x-B.y) return 1;
	if(A.x-A.y == B.x-B.y) return A.y<B.y;
	return 0;
}

int F(int x1,int y1,int d1l,int d1r,int x2,int y2,int d2l,int d2r)
{
	int yt;

	if((d2l-d1r)%2==0)
	{
		yt=(d2l-d1r)/2;
		return y2*y2-yt*yt;
	}
	else
	{
		yt=(d2l-d1r-1)/2;
		return y2*y2-yt*(yt+1);
	}

}

int main()
{
	freopen("treasures.in","r",stdin);
	freopen("treasures.out","w",stdout);

	int N,total,ans;
	int i,j;

	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d%d%d",&T[i].x,&T[i].y,&T[i].p);
		T[i].y=-T[i].y;
	}

	sort(T,T+N);

	for(i=0;i<N;i++)
	{
		dp[i]=-T[i].y*T[i].y+T[i].p;
		d1[i]=T[i].x-T[i].y;
		d2[i]=T[i].x+T[i].y;
		left[i]=d1[i]+1;
		right[i]=d2[i]-1;

		for(j=0;j<i;j++)
		{
			if(d1[j]<=d1[i] && d2[i]<=d2[j])
			{
				dp[j]+=T[i].p;
				continue;
			}

			if(right[j]<left[i])
			{
				if(dp[j]-T[i].y*T[i].y+T[i].p>dp[i])
					dp[i]=dp[j]-T[i].y*T[i].y+T[i].p;
				continue;
			}


total=F(T[j].x,T[j].y,d1[j],d2[j],T[i].x,T[i].y,d1[i],d2[i]);

			if(-total+T[i].p+dp[j] > dp[i])
				dp[i]=-total+T[i].p+dp[j];
		}
	}

	ans=0;
	for(i=0;i<N;i++) if(dp[i]>ans) ans=dp[i];

	printf("%d\n",ans);

	return 0;
}
