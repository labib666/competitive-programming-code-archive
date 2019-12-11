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
int d[4*1002], a[1002][1002];

void tree (int col, int n, int s, int e) {
    if (s == e) { d[n] = s; return; }
    int m = (s+e)/2;
    tree(col,2*n,s,m);
    tree(col,2*n+1,m+1,e);
    d[n] = (a[d[2*n]][col]>a[d[2*n+1]][col]) ? d[2*n+1] : d[2*n];
    return;
}

int query (int col, int n, int s, int e, int x1, int x2) {
    if (x1 > e || x2 < s) return x1;
    if (x1 <= s && x2 >= e) return d[n];
    int m = (s+e)/2;
    int v1 = query(col,2*n,s,m,x1,x2);
    int v2 = query(col,2*n+1,m+1,e,x1,x2);
    return (a[v1][col] > a[v2][col]) ? v2 : v1;
}


int findMaxSquare(int A[SIZE][SIZE], int N)
{
    for (int i = 0; i<N; i++)
        for (int j=0;j<N; j++)
            a[i][j] = A[i][j];

    for (int i=0; i<N; i++) {
        for (int j=N-1; j>=0; j--) {
            a[i][j] = (a[i][j]==0) ? 0 : (j==N-1) ? 1 : a[i][j+1]+1;
        }
    }

    int ans, fq;
    ans = 0, fq = 0;

    for (int i=0; i<N; i++) {
        tree(i,1,1,N);
        for (int j=0; j<N; j++) {
            if (a[j][i] == 0) continue;
            int hi = a[j][i], lo = 1, mid;
            while (hi >= lo) {
                if (hi < ans) break;
                mid = (hi+lo)/2;
                int vl = query(i,1,1,N,j,j+mid-1);
                if (a[vl][i] >= mid) lo = mid+1;
                else hi = mid-1;
            }
            if (hi == ans) fq++;
            else if (hi > ans) {
                ans = hi, fq = 1;
            }
        }
    }

	return ans*fq;
}
