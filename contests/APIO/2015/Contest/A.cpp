/*
ID: Labib666
LANG: C++
Contest: APIO 2015
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
#define INF 1000000007ll
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

#define MAXN

LL n, a, b, v[2003], cv[2003], mv = INF;
LL ans;

bool seen[51][21][51][501];

void solve (int pos, LL sum, LL ov, LL cmp) {
    //cout << pos << " " << sum << " " << ov << " " << cmp << endl;
    if (pos > n) {
        if (cmp > 0) return;
        if (cmp == 0) ans = min (ov, ans);
        return;
    }
    if (cmp == 0) return;
    solve (pos+1, sum+v[pos], ov, cmp);
    sum += v[pos];
    ov |= sum;
    solve(pos+1, 0, ov, cmp-1);
    return;
}

void solve2 (int pos, LL lp, LL pl, LL ov) {
    if (pos > n) {
        if (pl > 0) return;
        if (pl == 0) ans = min (ov, ans);
        return;
    }
    if (pl == 0) return;
    if (seen[pos][lp][pl][ov]) return;

    seen[pos][lp][pl][ov] = 1;

    solve2 (pos+1, lp, pl, ov);

    ov |= cv[pos] - cv[lp];lp = pos, pl--;
    solve2 (pos+1, lp, pl, ov);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);

    cin >> n >> a >> b;
    for (LL i=1; i<=n; i++) { cin >> v[i]; cv[i] = v[i]+cv[i-1]; mv = min (mv, v[i]); }

    if (n<=20) {
        ans = LINF;
        for (int i=a; i<=b; i++)
            solve(1,0,0,i);
        cout << ans << endl;
        return 0;
    }
    if (n<=100 && b<=20) {
        ans = LINF;
        for (int i=a; i<=b; i++)
            solve2(1,0,i,0);
        cout << ans << endl;
        return 0;
    }

    return 0;
}
