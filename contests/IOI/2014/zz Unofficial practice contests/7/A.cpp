/*
ID: Labib Rashid
LANG: C++
TASK: A-The Smart Bomb
CONTEST: unofficial 07
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <string>

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

int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    double ans, a[3];
    double d[3], hi, lo, m1, m2, v1, v2;
    PLL pp[3];
    int p, q, r;

    while (scanf ("%lld %lld", &pp[0].X, &pp[0].Y) != EOF) {
        scanf ("%lld %lld", &pp[1].X, &pp[1].Y);
        scanf ("%lld %lld", &pp[2].X, &pp[2].Y);

        FOR(i,0,3) {
            d[i] = hypot((double)(pp[i].X-pp[(i+1)%3].X), (double)(pp[i].Y-pp[(i+1)%3].Y));
        }

        ans = 0.0;

        FOR(i,0,3) {
            p = i, q = (i+1)%3, r = (i+2)%3;

            hi = min(d[r],d[p]), lo = max(0.0,d[p]-d[q]);

            if (hi < lo) continue;

            double s1 = (d[q]-(d[r]-d[p]))/2.0;
            s1 = d[p]-s1;

            if (s1 < lo || s1 > hi) continue;

            double k1 = d[p] + d[r]-s1;


            if (ans < k1) {

                ans = k1;
                double k2 = s1;
                a[p] = k2, a[q] = d[p]-k2, a[r] = d[r]-k2;

            }
        }

        FOR(i,0,3) {
            printf ("%lf\n", a[i]);
        }
    }


    return 0;
}
