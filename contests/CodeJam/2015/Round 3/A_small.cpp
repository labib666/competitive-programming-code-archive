/*
ID: Labib666
LANG: C++
Contest: CodeJam Round 3
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

LL t, tc=0, N, D;
LL p[1000006], flag[1000006];
PLL s[1000006];
LL S0, As, Cs, Rs, M0, Am, Cm, Rm;
vector <LL> E[1000006];

LL dfs (LL pos) {
    if (flag[pos] == 1) return 0;
    LL res = 1;
    for (LL i=0; i<E[pos].SZ; i++) {
        res += dfs(E[pos][i]);
    }
    return res;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    //freopen ("A-small-attempt0.in","r",stdin);
    //freopen ("A-small-attempt0.out","w",stdout);

    scanf("%lld", &t);
    while (tc<t) {
        tc++;
        cin >> N >> D;

        for (int i=0; i<N; i++) E[i].clear();

        cin >> S0 >> As >> Cs >> Rs;
        cin >> M0 >> Am >> Cm >> Rm;

        s[0].X = S0, s[0].Y = 0, p[0] = M0;
        for (LL i=1; i<N; i++) {
            s[i].X = (s[i-1].X*As + Cs) % Rs; s[i].Y = i;
            p[i] = (p[i-1]*Am + Cm) % Rm;
            E[(p[i]%i)].PB (i);
        }

        //for (int i=1; i<N; i++) cout << i << " " << (p[i]%i) << " " << s[i].X << endl;

        sort(s,s+N);
        //for (int i=0; i<N; i++) cout << i << " is " << s[i].Y << " " << s[i].X << endl;

        LL bnd = lower_bound(s, s+N, MP(s[0].X+D+1,0ll)) - s;

        fill(flag, flag+N, 0);
        for (LL i=bnd; i<N; i++) {
            flag[s[i].Y] = 1;
        }

        LL ans = 0;
        for (LL i=0, j=bnd; i<N; i++) {

            while (j<N) {
                if (s[j].X <= s[i].X+D) {
                    flag[s[j].Y] = 0;
                    j++;
                }
                else break;
            }

            LL now = dfs(0);
            ans = max(ans, now);

            flag[s[i].Y] = 1;
        }

        printf("Case #%lld: %lld\n", tc, ans);
    }

    return 0;
}
