#include"square.h"
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair <int,int>
#define PLL pair <LL,LL>
#define X first
#define Y second
#define VI vector <int>
#define VLL vector <LL>
#define PB push_back
#define SZ size()
#define MP make_pair

#define INF 1000000007ll
#define LINF INF*INF
#define PI 2.0*acos(0.0)
#define EPS 1e-9

stack <PII> S;
int dp[1002][1002], ryt[1002][1002], dwn[1002][1002], a[1002][1002], N;

int solve(int x, int y) {
    if (x == N-1 || y == N-1) return dp[x][y] = (a[x][y]==0) ? 0 : 1;
    int &rt = dp[x][y];
    if (rt != -1) return rt;
    rt = min (ryt[x][y], dwn[x][y]);
    rt = min (rt, solve(x+1,y+1)+1);
    return rt;
}

int findMaxSquare(int A[SIZE][SIZE], int nn)
{
    N = nn;
    for (int i = 0; i<N; i++)
        for (int j=0;j<N; j++)
            a[i][j] = A[i][j];

    for (int i=0; i<N; i++) {
        for (int j=N-1; j>=0; j--) {
            ryt[i][j] = (a[i][j]==0) ? 0 : (j==N-1) ? 1 : ryt[i][j+1]+1;
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=N-1; j>=0; j--) {
            dwn[j][i] = (a[j][i]==0) ? 0 : (j==N-1) ? 1 : dwn[j+1][i]+1;
        }
    }

    memset(dp,-1,sizeof(dp));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            solve(i,j);
        }
    }

    int ans, fq;
    ans = 0, fq = 0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (dp[i][j] == ans) fq++;
            else if (dp[i][j] > ans) ans = dp[i][j], fq = 1;
        }
    }


	return ans*fq;
}
