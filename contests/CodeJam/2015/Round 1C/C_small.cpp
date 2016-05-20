/*
ID: Labib666
LANG: C++
Contest: CodeJam R1C
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



int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("C-small-attempt1.in","r",stdin);
    freopen ("C-small-attempt1.out","w",stdout);

    LL t, tc=0, c, d, v, a[110];

    // small
    LL seen[100];
    set <LL> s;
    set <LL>::iterator it;

    //large

    cin >> t;
    while (tc<t) {
        tc++;

        cin >> c >> d >> v;
        for (LL i=0; i<d; i++) cin >> a[i];

        if (c == 1) {

            LL ans = 30;

            for (LL now = 0; now <(1ll<<15); now++) {
                s.clear();
                for (LL i=0; i<d; i++) s.insert(a[i]);
                for (LL i=0; i<15; i++) {
                    if (now&(1ll<<i)) s.insert (i+1);
                }

                memset(seen, 0, sizeof(seen));
                seen[0] = 1;

                for (it = s.begin(); it != s.end(); it++) {
                    for (LL j=v-*it; j>=0; j--) {
                        if (seen[j]) seen[j+*it] = 1;
                    }
                }

                bool fail = 0;
                for (LL i=0; i<=v; i++) {
                    if (seen[i] == 0) {
                        fail = 1;
                        break;
                    }
                }

                if (fail) continue;
                ans = min (ans, (LL)s.size());
            }

            printf ("Case #%lld: %lld\n", tc, ans-d);

        }
    }


    return 0;
}
