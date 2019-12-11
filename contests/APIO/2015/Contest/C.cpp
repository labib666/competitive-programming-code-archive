/*
ID: Labib666
LANG: C++
Contest: APIO 2015
Task: C
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

LL n, k, x, y, now, ans, hi, lo, m1, m2;
string s1, s2;
PLL p[100005];

LL gval (LL vl) {
    LL sum = 0;
    for (LL i=0; i<now; i++) {
        sum ++;
        //cout << i << " - - " << p[i].X << " " << p[i].Y << endl;
        if (vl >= p[i].X && vl <= p[i].Y) continue;
        if (vl < p[i].X)sum += 2*(p[i].X-vl);
        if (vl > p[i].Y)sum += 2*(vl-p[i].Y);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);

    cin >> k >> n;

    if (k == 1) {
        now = ans = 0, hi = 1000000000; lo = 0;
        for (int i=0; i<n; i++) {
            cin >> s1 >> x >> s2 >> y;
            if (x > y) swap (x,y);
            if (s1 == s2) {
                ans += y-x;
                continue;
            }
            ans += y-x;
            p[now++] = MP (x,y);
        }

        LL cur = LINF;

        while (hi >= lo+6) {
            m1 = (hi-lo)/3;
            m2 = m1 * 2;
            m1 += lo, m2 += lo;
            LL v1 = gval(m1), v2 = gval(m2);
            //cout << hi << "  " << lo << endl;
            if (v1 > v2) lo = m1;
            else hi = m2;
        }

        for (LL i=lo; i<=hi; i++) {
            cur = min(cur, gval(i));
            //cout << i << " " << ans << " " << cur << endl;
        }

        cout << ans+cur << endl;
    }

    return 0;
}
