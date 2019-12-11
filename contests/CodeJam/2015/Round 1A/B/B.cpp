/*
ID: Labib666
LANG: C++
Contest: CodeJam 2015 Round 1A
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
    freopen ("B-large.in","r",stdin);
    freopen ("B-large.out","w",stdout);

    LL t, tc=0, n, k, a[1024], hi, lo, mid, cnt;

    cin >> t;
    while (tc<t) {
        tc++;

        cin >> n >> k;
        for (LL i=0; i<n; i++) cin >> a[i];

        lo = 0, hi = 100000000000000ll;
        while (hi>=lo) {
            mid = (hi+lo)/2;
            cnt = 0;
            for (LL j=0; j<n; j++) cnt += (mid / a[j])+1;
            if (cnt >= k) hi = mid-1;
            else lo = mid + 1;
        }
        cnt = 0;

        if (lo == 0) cnt = 0;
        else for (LL j=0; j<n; j++) cnt += ((lo-1) / a[j])+1;

        //cout << lo << " " << cnt << endl;

        cnt = k - cnt;

        LL time = lo, ans;
        for (LL i=0; i<n; i++) {
                if ( lo % a[i] == 0 && cnt == 1) {
                    ans = i+1; break;
                }
                else if ( lo % a[i] == 0 ) cnt--;
        }
        printf ("Case #%lld: %lld\n", tc, ans);
    }


    return 0;
}
