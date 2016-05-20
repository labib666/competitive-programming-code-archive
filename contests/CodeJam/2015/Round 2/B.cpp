/*
ID: Labib666
LANG: C++
Contest: CodeJam 2015 Online Round 2
Task: B
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
#define EPS 1e-12

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

pair <double,double> p[200];
int n, t, tc = 0;
double v, x;

bool check (double tt) {

    double vv, sum, r, t1, t2;

    sum = 0.0; vv = v;
    for (int i=0; i<n; i++) {
        r = tt * p[i].Y;
        if (r > vv) r = vv;
        vv -= r;
        sum += r * p[i].X;
    }
    if ( abs(vv) > EPS ) return 0;
    t1 = sum / v;

    //if (tc == ) cout << tt << " " << t1 << "here1\n";

    sum = 0.0; vv = v;
    for (int i=n-1; i>=0; i--) {
        r = tt * p[i].Y;
        if (r > vv) r = vv;
        vv -= r;
        sum += r * p[i].X;
    }
    if ( abs(vv) > EPS ) return 0;
    t2 = sum / v;

    //if (tc == ) cout << tt << " " << t2 << "here2\n";

    if (t1 <= x+EPS && t2 >= x-EPS) { return 1; }
    else return 0;

}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("B-large.in","r",stdin);
    freopen ("B-large.out","w",stdout);

    cin >> t;
    while (tc < t) {

        tc++;
        printf("Case #%d: ", tc);

        cin >> n >> v >> x;

        for (int i=0; i<n; i++) cin >> p[i].Y >> p[i].X;


        sort (p, p+n);

        if (p[n-1].X < x || p[0].X > x ) {

            cout << "IMPOSSIBLE\n";
            continue;

        }

        /*if (tc == ) {
            cout << n <<  " " << v << " " << x << endl;
            for (int i= 0; i<n; i++) cout << p[i].Y << " " << p[i].X << endl;
        }


        /*if (n == 2) {
            double hi = v, lo = 0.0, mid;
            int it = 150;

            while (it--) {
                mid = (hi+lo)/2;
                //if (abs (mid*p[0].X + (v-mid)*p[1].X - v*x) < EPS) break;
                if (mid*p[0].X + (v-mid)*p[1].X - v*x > 0) lo = mid;
                else hi = mid;
            }

            double ans = max (mid/p[0].Y, (v-mid)/p[1].Y);
            printf ("%.8lf\n", ans);
            continue;
        }*/

        double hi = 1e25, lo = 0.0, mid;
        int it = 300;

        while (it--) {

            mid = hi+lo; mid /= 2.0;

            if ( check(mid) ) hi = mid;
            else lo = mid;

        }

        mid = (hi + lo)/2;

        /*if (mid > 1e14 || abs(mid)< EPS ) {

            cout << "IMPOSSIBLE\n";
            continue;

        }*/

        printf ("%.8lf\n", mid);

    }


    return 0;
}
