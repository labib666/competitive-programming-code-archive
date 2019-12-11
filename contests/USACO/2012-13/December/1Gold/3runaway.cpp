/*
ID: Labib Rashid
LANG: C++
TASK: 3runaway
CONTEST: USACO 2012-13 DEC
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
#define INF 1000000007ll
#define LINF 1000000000000000007
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)


int N, hv[200005], chn[200005], hd[200005], p[22][200005], cc, cp;
LL L, hvd[200005], d[200005];
VI v[200005]; VLL e[200005];
int bt[200005], rs[200005];

int tree (int pos) {
    hv[pos] = -1; int mc = 0, sz = 1;
    FOR(i,0,v[pos].SZ) {
        int j = v[pos][i];
        int k = tree(j);
        sz += k;
        if (mc < k) { hv[pos] = j, hvd[pos] = e[pos][i]; mc = k; }
    }
    return sz;
}

void sparse (int pos) {
    FOR (i,1,22) {
        if (p[i-1][pos] == 0) break;
        p[i][pos] = p[i-1][p[i-1][pos]];
    }
    return;
}

int findparent (int pp) {
    int ans = pp; LL rem = L;
    for (int i=21; i>=0; i--) {
        if (p[i][ans] != 0) {
            int nw = p[i][ans];
            if (d[ans]-d[nw] <= rem) {
                rem -= (d[ans]-d[nw]);
                ans = p[i][ans];
            }
        }
    }
    return ans;
}

int Qry (int pos) {
    int ans = 0;
    while (pos > 0) {
        ans += bt[pos];
        pos -= pos&-pos;
    }
    return ans;
}

void Upd (int pos, int vl) {
    while (pos <= N) {
        bt[pos] += vl;
        pos += pos&-pos;
    }
    return;
}

void goupdate (int up, int dwn) {
    while (1)
    {
        if (chn[up] != chn[dwn]) {
            int k = hd[chn[dwn]];
            Upd(k,1); Upd(dwn+1,-1);
            dwn = p[0][k];
            continue;
        }
        else {
            Upd(up,1); Upd(dwn+1, -1);
            break;
        }
    }
    return;
}

void build (int pos, int par, LL dst, int dpt) {
    int id = ++cp;

    if (dpt == 1) chn[id] = ++cc, hd[cc] = id ;
    else chn[id] = cc;

    p[0][id] = par; d[id] = dst;
    sparse(id);

    if (hv[pos] != -1) build(hv[pos], id, dst+hvd[pos], dpt+1);
    FOR(i,0,v[pos].SZ) {
        int j = v[pos][i];
        if (hv[pos] == j) continue;
        build(j, id, dst+e[pos][i], 1);
    }

    int kk = findparent(id);
    goupdate(kk,id);

    rs[pos] = Qry(id);

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen ("runaway.in","r",stdin);
    //freopen ("runaway.out","w",stdout);

    int pp; LL dd;

    cin >> N >> L;
    FOR(i,2,N+1) {
        cin >> pp >> dd;
        v[pp].PB (i);
        e[pp].PB (dd);
    }

    tree(1);
    cc = cp = 0;

    build(1,0,0,1);

    FOR(i,1,N+1) cout << rs[i] << endl;

    return 0;
}
