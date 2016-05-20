/*
ID: Labib666
LANG: C++
Contest: Facebook Hacker Cup 2015
Task: 2 ( 30 pts )
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
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

#define MAXN

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen ("new_years_resolution.txt","r",stdin);
    freopen ("output.txt","w",stdout);

    int t, tc = 0, n, p, pp, g, gg, f, ff, P[25], G[25], F[25];

    scanf ("%d", &t);
    while (tc < t) {
        tc++;

        scanf("%d %d %d %d", &p, &g, &f, &n);
        for (int i=0; i<n; i++) scanf("%d %d %d", &P[i], &G[i], &F[i]);

        bool fail = 1;

        for (int i=0; i<(1<<n); i++) {
            pp = gg = ff = 0;
            for (int j=0; j<n; j++) {
                if (i&(1<<j)) {
                    pp += P[j], gg += G[j], ff += F[j];
                }
            }
            if (pp == p && gg == g && ff == f) { fail = 0; break; }
        }

        if (fail) printf( "Case #%d: no\n", tc );
        else printf( "Case #%d: yes\n", tc );
    }


    return 0;
}
