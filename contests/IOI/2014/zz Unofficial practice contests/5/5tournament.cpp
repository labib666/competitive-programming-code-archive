/*
ID: Labib Rashid
LANG: C++
TASK: Jousting Tournament
CONTEST: IOI unofficial contest 5
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

#define MAXN 100005

int seg[4*MAXN]; bool flag[4*MAXN];
int mq[4*MAXN];

int R[MAXN], E[MAXN], P[MAXN], V[MAXN], N, C, RR;
PII S[MAXN];
priority_queue < pair <int,PII> > Q;


void tree2(int n, int s, int e) {
    if (s == e) { mq[n]=R[s]; return; }
    int m = (s+e)/2;
    tree2(2*n,s,m); tree2(2*n+1,m+1,e);
    mq[n] = max(mq[2*n], mq[2*n+1]);
    return;
}

int MQ (int n, int s, int e, int p1, int p2) {
    if (p1 > e || p2 < s) return -1;
    if (s >= p1 && e <= p2) return mq[n];
    int m = (s+e)/2;
    return max (MQ (2*n,s,m,p1,p2), MQ(2*n+1,m+1,e,p1,p2));
}

void tree (int n, int s, int e) {
    if (s == e) { seg[n] = 1; return; }
    int m = (s+e)/2;
    tree(2*n,s,m); tree(2*n+1,m+1,e);
    seg[n] = seg[2*n]+seg[2*n+1];
    return;
}

int query (int n, int s, int e, int val) {
    if (s == e) return s;
    int m = (s+e)/2;
    if (val <= seg[2*n]) return query(2*n, s, m, val);
    else return query(2*n+1, m+1, e, val-seg[2*n]);
}

void update (int n, int s, int e, int p1, int p2) {
    if (p1 > e || p2 < s) return;
    else if ( s >= p1 && e <= p2 ) {
        flag[n] = 1; seg[n] = 0;
        return;
    }
    else if (flag[n]) return;
    int m = (s+e)/2;
    update(2*n,s,m,p1,p2);
    update(2*n+1,m+1,e,p1,p2);
    seg[n] = seg[2*n]+seg[2*n+1];
    return;
}


int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    pair <int,PII> cur; PII now;
    int lft, rgt, pos, mval;

    cin >> N >> C >> RR;


    FOR(i,0,N-1) {
        cin >> R[i];
        E[i] = i; P[i] = i;
    }
    E[N-1] = P[N-1] = N-1;
    if (N == 1) { cout << "0\n"; return 0; }

    tree(1,0,N);
    tree2(1,0,N-2);

    FOR(i,0,C) {
        cin >> lft >> rgt;
        S[i].X = query(1,0,N,lft+1);
        S[i].Y = query(1,0,N,rgt+2)-1;
        update(1,0,N,S[i].X+1,S[i].Y);
    }

    FOR(i,0,C) {
        lft = S[i].X, rgt = S[i].Y;
        pos = lft; mval = 0;
        FOR(j,lft,rgt+1) {
            if (V[j] > mval) {
                mval = V[j]; pos = P[j];
            }
            j = E[j];
        }
        E[lft] = rgt; V[lft] = 1+mval; P[lft] = pos;
        Q.push(MP(V[lft],MP(P[lft], MQ(1,0,N-2,lft,rgt-1))));
    }

    mval = -1, pos;
    while (!Q.empty()) {
        cur = Q.top(); Q.pop();
        now = cur.Y;

        if (now.Y > RR) continue;
        if (mval != -1 && pos > cur.X) break;
        mval = (mval == -1) ? now.X : min(now.X, mval);
        pos = cur.X ;
    }

    mval = (mval == -1) ? 0 : mval;

    cout << mval << endl;


    return 0;
}

