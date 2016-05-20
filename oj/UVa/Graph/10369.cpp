/*
ID: Labib666
LANG: C++
Contest: IOI practice
Task:    10369 - UVa
*/

#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector <int>
#define VLL vector <LL>
#define PQI priority_queue <int>
#define PQLL priority_queue <LL>
#define QI queue <int>
#define QLL queue <LL>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define SZ size()
#define INF 1000000007
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-11

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

#define MAXN

pair <double,double> p[1000];
int n, k, t, tc=0;
int seen[1000];

void dfs(int pos, double dst, int flag) {
    seen[pos] = flag;
    for (int i=0; i<n; i++) {
        if (seen[i]) continue;
        if (dst*dst >= ((p[pos].X-p[i].X)*(p[pos].X-p[i].X)+(p[pos].Y-p[i].Y)*(p[pos].Y-p[i].Y))-EPS) {
            dfs(i,dst,flag);
        }
    }
    return;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);

    scanf("%d", &t);
    while (tc<t) {
        tc++;

        scanf("%d", &k);
        scanf("%d", &n);

        for (int i=0; i<n; i++) {
            scanf("%lf", &p[i].X);
            scanf("%lf", &p[i].Y);
        }

        double hi=1e11, lo=0.0, mid;
        int cnt = 100;
        while (cnt--) {
            mid = (hi+lo)/2.0;
            fill(seen, seen+n, 0);
            int now = 0;
            for (int i=0; i<n; i++){
                if (seen[i] == 0) {
                    now++;
                    dfs(i,mid,now);
                }
            }
            if (now > k) lo = mid;
            else hi = mid;
        }

        printf("%.2lf\n", (hi+lo)/2.0);
    }


    return 0;
}
