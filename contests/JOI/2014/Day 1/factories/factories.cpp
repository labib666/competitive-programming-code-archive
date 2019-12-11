/*
ID: Labib Rashid
LANG: C++
TASK: factories
CONTEST: JOI
*/

#include "factories.h"
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
#define LINF 1000000000000000007ll
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

LL dd[500005], uu[500005], nn;
LL now, d[500005], s[500005], a[1000002], b[1000002], f[4*1000002];
VLL v[500005], e[500005];

void dfs (LL pos, LL par, LL dst, LL dpt) {
    d[pos] = dst;
    s[pos] = now; b[now] = pos, a[now++] = dpt;
    FOR(i,0,v[pos].SZ) {
        LL j = v[pos][i];
        if (j == par) continue;
        dfs (j,pos, dst+e[pos][i], dpt+1);
        b[now] = pos, a[now++] = dpt;
    }
    return;
}

void tree (LL n, LL ss, LL ee) {
    if (ss == ee) { f[n] = ss; return; }
    LL m = (ss+ee)/2;
    tree(2*n,ss,m);
    tree(2*n+1,m+1,ee);
    f[n] = (a[f[2*n]]>a[f[2*n+1]]) ? f[2*n+1] : f[2*n];
    return;
}

int qry (int n, int ss, int ee, int r1, int r2) {
    if (ss > r2 || ee < r1) return INF;
    if (ss >= r1 && ee <= r2) { return f[n]; }
    int m = (ss+ee)/2;
    int v1 = qry(2*n,ss,m,r1,r2);
    int v2 = qry(2*n+1,m+1,ee,r1,r2);
    if (v1 == INF) v1 = v2;
    if (v2 == INF) v2 = v1;
    return (a[v1]>a[v2]) ? v2 : v1;
}

LL nqryd (int pos, int par) {
    FOR (i,0,v[pos].SZ) {
        LL j = v[pos][i];
        if (j == par) continue;
        dd[pos] = min(dd[pos], nqryd(j,pos)+e[pos][i]);
    }
    return dd[pos];
}

void nqryu (int pos, int par, LL pd) {
    if (par == -1) uu[pos] = dd[pos];
    else uu[pos] = min (uu[pos], pd+min(dd[par],uu[par]));
    FOR(i,0,v[pos].SZ) {
        LL j = v[pos][i];
        if (j == par) continue;
        nqryu(j,pos,e[pos][i]);
    }
    return;
}

void Init(int N, int A[], int B[], int D[]) {
    nn = N;
    FOR(i,0,N-1) {
        v[A[i]].PB (B[i]);
        v[B[i]].PB (A[i]);
        e[A[i]].PB (D[i]);
        e[B[i]].PB (D[i]);
    }
    now = 0;
    dfs(0,-1,0,0);
    tree(1,0,now-1);
    return;
}

long long Query(int S, int X[], int T, int Y[]) {
    if (S<=10 && T<=10) {
        LL ans = LINF, cur;
        FOR(i,0,S) {
            cur = LINF;
            FOR(j,0,T) {
                int p = qry(1,0,now-1,min(s[X[i]],s[Y[j]]), max(s[X[i]],s[Y[j]]));
                p = b[p];
                cur = min (cur, d[X[i]]+d[Y[j]]-2*d[p]);
            }
            ans = min (ans, cur);
        }
        return ans;
    }
    else {
        fill (dd,dd+nn,LINF);
        fill (uu,uu+nn,LINF);
        FOR (i,0,T) dd[Y[i]] = uu[Y[i]] = 0;
        nqryd(0,-1);
        nqryu(0,-1,0);
        LL ans = LINF;
        FOR(i,0,S) {
            ans = min (ans, min(dd[X[i]], uu[X[i]]));
        }
        return ans;
    }
    return 0;
}
