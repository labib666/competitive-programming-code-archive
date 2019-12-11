/*
ID: Labib666
LANG: C++
Contest: IOI TST 2
Task: 3
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
#define INF 1000000007ll
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
    if (num%2ll) ans = (ans*num)%prime; return ans;
}

LL DP[1050][11], P[1050], V[1050], M[1050], N, T;

LL DFS (LL pos, LL level) {
    if (level == N) {
        LL k = pos - (1ll<<(N-1));
        V[pos] = max (M[2*k],M[2*k+1]);
        return V[pos]-1;
    }
    LL k1 = DFS(2*pos,level+1);
    LL k2 = DFS(2*pos+1,level+1);

    V[pos] = max (k1,k2);
    return V[pos]-1;
}

LL solve (LL pos, LL bot, LL level) {
    if (bot < V[pos]-1) return INF;
    if (level == N) return bot>=V[pos] ? 0ll : P[pos];

    LL &ret = DP[pos][bot];
    if (ret != -1) return ret;

    ret = solve(pos*2, bot, level+1) + solve(pos*2+1, bot, level+1);
    ret = min (ret, P[pos]+solve(pos*2, bot+1, level+1) + solve(pos*2+1, bot+1, level+1));

    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("3.txt","r",stdin);

    scanf ("%lld", &T);
    while (T--) {
        scanf ("%lld", &N);
        MEM(DP,-1);

        for (LL i=0ll; i<(1ll<<N); i++) {
            scanf ("%lld", &M[i]);
            M[i] = N - M[i];
        }

        for (LL j=N-1ll; j>=0ll; j--)
        {
            for (LL i=(1ll<<j); i<(1ll<<(j+1)); i++)
                scanf ("%lld", &P[i]);
        }

        DFS(1,1);
        printf ("%lld\n", solve (1,0,1));
    }


    return 0;
}
