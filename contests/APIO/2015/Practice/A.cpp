/*
ID: Labib666
LANG: C++
Contest: APIO practice 2015
Task: A
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
//--------------------------------------------------------------------------------------------------------

LL n, w, x, wmx = 0, ans = 0;
vector <LL> v[10004];
LL tel[10004], ts[10004];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);

    scanf("%lld", &n);
    for (LL i=0; i<n; i++) {
        scanf("%lld%lld", &w, &x);
        wmx = max(w,wmx); ts[w] += x;
        v[w].push_back(x);
    }

    for (LL i=1; i<=wmx; i++) {
        sort ALL(v[i]);
        tel[i] = v[i].size();
    }

    for (LL i=1; i<=wmx; i++) {
        if (tel[i] == 0) continue;
        for (LL j=1; j<i; j++) {
            if (tel[j] == 0) continue;
            LL fe = 0, fs = 0, ee = tel[j], es = ts[j], dl = i-j;
            for (LL k=0; k<tel[i]; k++) {
                while (fe < tel[j] && v[j][fe] < v[i][k]) { fs += v[j][fe]; es -= v[j][fe]; fe++; ee--; }
                LL dp = (fe*v[i][k]-fs) + (es-ee*v[i][k]);
                ans += dl * dp;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
