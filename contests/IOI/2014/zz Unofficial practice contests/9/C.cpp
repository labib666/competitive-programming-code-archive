/*
ID: Labib Rashid
LANG: C++
TASK: C
CONTEST: practise contest 1
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

LL N, K, a[1000006], b[1000006];
LL lft[1000006], ryt[1000006], c[1000006];
bool need[1000006], f[4*1000002];
LL d[4*1000002];
vector <PLL> pp(1000006);

void btupd (LL pos) {
    while (pos <= N) {
        c[pos]++;
        pos += pos&-pos;
    }
    return;
}

LL btqry (LL pos) {
    LL ans = 0;
    while (pos > 0) {
        ans += c[pos];
        pos -= pos&-pos;
    }
    return ans;
}

void update (LL n, LL s, LL e, LL x1, LL x2, LL vl, LL bl) {

    if (s > x2 || e < x1) return;
    if (s >= x1 && e <= x2) {
        f[n] = 1; d[n] = vl; return;
    }

    LL m = (s+e)/2;

    if (f[n] != 0) {
        d[2*n] = d[2*n+1] = d[n];
        f[2*n] = f[2*n+1] = 1;
        f[n] = 0;
    }

    update (2*n, s, m, x1,x2,vl, bl);
    update (2*n+1, m+1, e, x1,x2,vl, bl);

    d[n] = (bl == 1) ? max(d[2*n],d[2*n+1]) : min(d[2*n],d[2*n+1]);
    return;

}

LL query (LL n, LL s, LL e, LL xx) {
    if (s == xx && e == xx) return d[n];
    if (f[n] != 0) return d[n];
    LL m = (s + e)/2;
    if (xx > m) return query (2*n+1, m+1, e, xx);
    else return query (2*n, s, m, xx);
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    scanf ("%I64d%I64d", &N, &K);
    FOR(i,1,N+1) scanf("%I64d", &a[i]);
    FOR(i,1,K+1) scanf("%I64d", &b[i]);

    for (LL i=1,j=1; i<=K; i++) {
        while (a[j] != b[i]) j++;
        need[j] = 1;
    }

    LL cnt=0;
    FOR(i,1,N+1) {
        if (need[i]) continue;
        pp[cnt++] = MP(a[i],i);
    }

    sort (pp.begin(), pp.begin()+cnt);

    update (1,1,N,1,N,0,1);
    FOR(i,1,N+1) {
        if (need[i]) { update (1,1,N,a[i]+1,N,i,1); continue; }
        else lft[i] = query (1,1,N,a[i]);
    }

    update (1,1,N,1,N,N+1,2);

    for(LL i=N; i>0; i--) {
        if (need[i]) { update (1,1,N,a[i]+1,N,i,2); continue; }
        else { ryt[i] = query (1,1,N,a[i]); ryt[i]--; }
    }

    LL ans = 0;
    FOR(i,0,N-K) {
        PLL jj = pp[i];
        if (need[jj.Y]) continue;

        ans += ryt[jj.Y]-lft[jj.Y]-(btqry(ryt[jj.Y])-btqry(lft[jj.Y]));
        btupd (jj.Y);
    }

    printf ("%I64d\n", ans);

    return 0;
}
