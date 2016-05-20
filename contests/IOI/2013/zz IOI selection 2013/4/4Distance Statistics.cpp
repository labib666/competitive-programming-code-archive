/*
Distance statistics
http://cerberus.delos.com:790/trainprobs2?p=0275&a=U7hm3fua8rP
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
#define LINF 1000000000000000007
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

#define MAXN 60002

LL N, M, K, mark[MAXN];
VI v[MAXN], e[MAXN];
LL sz[MAXN], a[MAXN], b[MAXN], c[MAXN], tot, cur, ans = 0;

LL gosize(LL pos, LL par) {
    sz[pos] = 1;
    FOR(i,0,v[pos].SZ) {
        LL j = v[pos][i];
        if (mark[j]) continue;
        if (par == j) continue;
        sz[pos] += gosize(j, pos);
    }
    return sz[pos];
}

LL gobalance (LL pos, LL par, LL ss) {
    FOR(i,0,v[pos].SZ) {
        LL j = v[pos][i];
        if (mark[j]) continue;
        if (par == j) continue;
        if (sz[j] > ss/2) return gobalance(j, pos, ss);
    }
    return pos;
}

LL gocentre (LL pos) {
    LL j = gosize(pos, -1);
    return gobalance(pos, -1, j);
}

void work (LL pos, LL par, LL sum) {
    b[cur++] = sum;
    FOR(i,0,v[pos].SZ) {
        LL j = v[pos][i];
        if (j==par) continue;
        if (mark[j]) continue;
        work (j, pos, sum+e[pos][i]);
    }
    return;
}

void gomerge () {
    LL now = 0, aj = 0, bj = 0;
    while (now < tot+cur) {
        if (aj == tot) { c[now] = b[bj]; now++; bj++; continue; }
        else if (bj == cur) { c[now] = a[aj]; now++; aj++; continue; }
        c[now] = (a[aj] <= b[bj]) ? a[aj] : b[bj]; now++;
        (a[aj] <= b[bj]) ? aj++ : bj++;
    }
    FOR(i,0,tot+cur)
        a[i] = c[i];
    return;
}

void chain (LL pos) {

    mark[pos] = 1;
    cur = 0, tot = 1;
    a[cur++] = 0;

    FOR (i, 0, v[pos].SZ) {

        LL j = v[pos][i];
        if ( mark [j] ) continue;

        cur = 0;
        work (j, pos, e[pos][i]);
        sort (b, b+cur);

        FOR(k,0,cur) {
            j = upper_bound(a, a+tot, K-b[k]) - a;
            ans += j;
        }

        gomerge();
        tot += cur;
    }

    FOR(i,0,v[pos].SZ) {
        LL j = v[pos][i];
        if (mark[j]) continue;
        j = gocentre(j);
        chain(j);
    }
    return;
}

int main()
{
    LL uu, vv, ww;
    string s;

    //freopen ("input.txt","r",stdin);

    cin >> N >> M;

    while (M--) {
        cin >> uu >> vv >> ww >> s;
        v[uu].PB (vv); e[uu].PB (ww);
        v[vv].PB (uu); e[vv].PB (ww);
    }
    cin >> K;

    ans = 0;
    ww = gocentre(1);
    chain(ww);

    cout << ans << endl;

    return 0;
}
