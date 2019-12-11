/*
ID: Labib666
LANG: C++
Contest: ioi unofficial practice contest 3
Task: Quality of Living
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
#define LINF 1000000000000000007
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

int R, C, H, W, Q[3001][3001];
int G[3001][3001];

int Grid (int val) {
    FOR (i,0,R) {
        FOR (j,0,C) {
            G[i][j] = (Q[i][j]<=val) ? -1 : 1;
        }
    }

    FOR(i,0,R) {
        int sum = 0, tmp;
        FOR(j,0,W-1) {
            sum += G[i][j];
        }
        for (int j=0, k=W-1; k < C; k++,j++) {
            sum += G[i][k];
            tmp = G[i][j];
            G[i][j] = sum;
            sum -= tmp;
        }
    }

    FOR(i,0,C) {
        int sum = 0, tmp;
        FOR(j,0,H-1) {
            sum += G[j][i];
        }
        for (int j=0, k=H-1; k < R; k++,j++) {
            sum += G[k][i];
            tmp = G[j][i];
            G[j][i] = sum;
            sum -= tmp;
        }
    }

    FOR (i,0,R) {
        if (i+H > R) continue;
        FOR (j,0,C) {
            if (j+W > C) continue;
            if (G[i][j] <= 0) return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("2Quality of Living.txt","r",stdin);

    cin >> R >> C >> H >> W;

    FOR(i,0,R) {
        FOR (j,0,C) {
            cin >> Q[i][j];
        }
    }

    int hi = R*C, lo = 1, mid;
    while (hi >= lo) {
        mid = (hi+lo)/2;
        if (Grid(mid)) hi = mid-1;
        else lo = mid+1;
    }

    cout << lo << endl;

    return 0;
}
