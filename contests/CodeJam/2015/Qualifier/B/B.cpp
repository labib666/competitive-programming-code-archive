/*
ID: Labib666
LANG: C++
Contest: Code Jam 2015 Qualifier
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

#define MAXN


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("B-large.in","r",stdin);
    freopen ("B-large.out","w",stdout);

    int ans, t, tc=0, d, p[1024], mx;

    cin >> t;
    while (tc<t) {
        tc++;
        ans = INF, mx = 0;

        cin >> d;
        for (int i=0; i<d; i++) { cin >> p[i]; mx = max(mx, p[i]); }

        for (int i=1; i<=mx; i++) {
            int cur = 0;
            for (int j=0; j<d; j++) {
                cur += ( p[j] / i );
                if ( p[j] % i ) continue;
                cur--;
            }
            cur += i;
            if (ans < cur) continue;
            ans = cur;
        }

        printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}
