/*
ID: Labib666
LANG: C++
Contest: IOI unofficial practice contest 4
Task: Race
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

#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
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

#define MAXN 200002ll

LL N, K, Ans;
LL Map[5*MAXN], Last[5*MAXN], TreeSize[MAXN];
VLL Adj[MAXN], Len[MAXN]; vector <PLL> Due;
bool Path[MAXN];

LL gosize (LL pos, LL par) {

    TreeSize[pos] = 1;

    FOR(i,0,Adj[pos].SZ) {
        LL j = Adj[pos][i];
        if (j == par) continue;
        if (Path[j]) continue;
        TreeSize[pos] += gosize(j, pos);
    }

    return TreeSize[pos];

}

LL gocheck (LL pos, LL par, LL sz) {

    FOR(i,0,Adj[pos].SZ) {
        LL j = Adj[pos][i];
        if (j == par) continue;
        if (Path[j]) continue;
        if (TreeSize[j]*2 > sz) return gocheck(j,pos,sz);
    }

    return pos;

}

LL gocenter (LL pos) {
    LL sz = gosize(pos, -1);
    return gocheck(pos, -1, sz);
}

void workit (LL pos, LL par, LL dep, LL sum) {

    if (dep >= Ans) return;
    if (sum > K) return;

    Due.PB (MP(sum,dep));

    FOR(i,0,Adj[pos].SZ) {
        LL j = Adj[pos][i];
        if (j==par) continue;
        if (Path[j]) continue;
        workit (j, pos, dep+1, sum+Len[pos][i]);
    }

    return;
}

void chain(LL pos) {

    Path[pos] = 1;
    Map[0] = 0, Last[0] = pos;

    FOR(i,0,Adj[pos].SZ) {

        LL j = Adj[pos][i];
        if (Path[j]) continue;

        workit(j, pos, 1, Len[pos][i]);

        FOR(i,0,Due.SZ) {
                PLL u = Due[i];
                if (Last[K-u.X] != pos) continue;
                Ans = min(Ans, Map[K-u.X]+u.Y);
        }

        FOR(i,0,Due.SZ) {
            PLL u = Due[i];
            if (Last[u.X] != pos) Map[u.X] = u.Y, Last[u.X] = pos;
            else Map[u.X] = min (Map[u.X], u.Y);
        }

        Due.clear();

    }


    FOR(i,0,Adj[pos].SZ) {
        LL j = Adj[pos][i];
        if (Path[j]) continue;
        j = gocenter(j);
        chain(j);
    }

    return;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("2Race.txt","r",stdin);

    LL u, v, w;

    cin >> N >> K;

    FOR(i,0,N-1) {
        cin >> u >> v >> w;
        Adj[u].PB (v);
        Adj[v].PB (u);
        Len[u].PB (w);
        Len[v].PB (w);
    }

    Ans = N;
    fill (Last,Last+1000002,N);

    w = gocenter(0);
    chain(w);

    if (Ans == N) Ans = -1;

    cout << Ans << endl;

    return 0;
}
