/*
ID: Labib Rashid
LANG: C++
TASK: 1
CONTEST: TOKI 2014 Day 2
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

using namespace std;

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

LL D[2501][2501],N, M, P1, P2, MD1[2501], MD2[2501];
VLL V[2501], E[2501];
LL K[502*502][2], P[2501];
bool S[502*502];
priority_queue < pair<LL,PLL> > Q;

void M_dijk (LL start, LL A[2501]) {
    priority_queue < pair <LL, PLL> > Q;
    bool vis[2501];
    pair <LL, PLL> now, now2; PLL cur;

    fill (vis+1, vis+N+1, 0);

    Q.push(MP(0ll, MP(start, -1)));
    while (!Q.empty()) {
        now = Q.top();
        Q.pop();

        cur = now.Y;
        if (vis[cur.X]) continue;
        vis[cur.X] = 1; A[cur.X] = -now.X;
        if (cur.Y != -1) S[cur.Y] = 1;

        FOR(i,0,V[cur.X].SZ) {
            LL j = V[cur.X][i];
            if (vis[j]) continue;
            now2 = MP (now.X-D[cur.X][j], MP(j,E[cur.X][i]));
            Q.push(now2);
        }
    }

    return;
}

LL alt_path (LL pos, LL path) {
    bool vis2[2501];
    priority_queue <PLL> Q2;
    PLL now, now2;
    LL ans  = 0;

    fill (vis2+1, vis2+N+1, 0);

    Q2.push(MP (0, P2));
    while (!Q2.empty()) {
        now = Q2.top();
        Q2.pop();

        if (vis2[now.Y]) continue;
        vis2[now.Y] = 1;
        if (now.Y == pos) break;

        FOR(i,0,V[now.Y].SZ) {
            LL j = V[now.Y][i];
            if (vis2[j]) continue;
            if (E[now.Y][i] == path) continue;
            now2 = MP (now.X-D[now.Y][j], j);
            Q2.push(now2);
        }
    }

    ans -= now.X;

    //cout << pos << " " << path << endl;

    return ans;
}

int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    LL u, v, w;
    pair <LL, PLL> now, now2; PLL cur;

    cin >> N >> M >> P1 >> P2;

    FOR(i,1,M+1) {
        cin >> u >> v >> w;
        D[u][v] = w; D[v][u] = w;
        V[u].PB (v);
        V[v].PB (u);
        E[u].PB (i);
        E[v].PB (i);
        K[i][0] = K[i][1] = -1;
    }

    M_dijk(P2, MD2);
    MEM(P,-1);

    Q.push(MP (0, MP(P1,0)));
    while (!Q.empty()) {
        now = Q.top();
        Q.pop();
        cur = now.Y;

        if (P[cur.X] != -1 && cur.Y > P[cur.X]) continue;
        P[cur.X] = cur.Y;

        //cout << now.Y << " & " <<  -now.X << endl;
        if (cur.X == P2) break;

        FOR(i,0,V[cur.X].SZ) {
            LL j = V[cur.X][i];

            u = E[cur.X][i];
            //if (S[u]==0) v =  cur.Y+MD2[cur.X];
            //else {
                int pp = cur.X<j ? 0 : 1;
                if (K[u][pp]==-1) K[u][pp] = alt_path(cur.X, u);
                v = cur.Y+K[u][pp];
            //}
            now2 = MP (min(now.X,-v), MP(j,cur.Y+D[cur.X][j]));
            Q.push(now2);
        }
    }

    cout << -now.X << endl;

    return 0;
}
