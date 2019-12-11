/*
ID: Labib666
LANG: C++
Contest: CodeJam 2015 Round 1A
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

int gcd (int a, int b){return (b == 0) ? a : gcd (b, a%b);}

int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}

LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}
//-------------------------------------------------------------------------------------------------

#define MAXN



int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz text.txt","r",stdin);
    freopen ("A-large-practice.in","r",stdin);
    freopen ("A-large-practice.out","w",stdout);

    int t, tc=0, n, a[1024], a1, a2;
    int mx;

    cin >> t;
    while (tc<t) {
        tc++;

        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];

        a1 = 0; a2 = mx = 0;
        for (int i=1; i<n; i++) {
            if (a[i]<a[i-1]) a1 += (a[i-1]-a[i]);
        }

        for (int i=1; i<n; i++) {
            if (a[i]<a[i-1]) mx = max (mx, a[i-1]-a[i]);
        }
        int lft = a[0];
        for (int i=1; i<n; i++) {
            a2 += min(lft, mx);
            lft = a[i];
        }


        printf ("Case #%d: %d %d\n", tc, a1, a2);
    }


    return 0;
}
