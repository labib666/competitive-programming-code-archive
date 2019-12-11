/*
ID: Labib666
LANG: C++
Contest: IOI practice unofficial contest 2
Task: Rivers
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
#define INF 10000000000007
#define LINF 1000000000000000007ll
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

VLL V[102];
LL C[102], D[102], P[102], E[102][102], DP[102][102][52], N, K;

LL solve (LL pos, LL saw, LL last, LL it) {

    LL &ret = DP[pos][last][saw];
    if (ret != -1) return ret;

    if (saw == 0) {
        ret = E[pos][last] * C[pos];
        if (it != V[P[pos]].SZ-1) ret += solve(V[P[pos]][it+1], 0, last, it+1);
        if (V[pos].SZ != 0) ret += solve (V[pos][0], 0, last, 0);
        return ret;
    }

    if (it == (LL)V[P[pos]].SZ-1) {
        if (V[pos].SZ == 0) return ret = 0;
        ret = min (solve (V[pos][0], saw-1, pos, 0), solve (V[pos][0], saw, last, 0) + E[pos][last] * C[pos]);
        return ret;
    }

    if (V[pos].SZ == 0) {
        ret = min (solve (V[P[pos]][it+1], saw-1, last, it+1), solve(V[P[pos]][it+1], saw, last, it+1)+ E[pos][last] * C[pos]);
        return ret;
    }

    ret = solve(V[P[pos]][it+1], saw, last, it+1) + solve(V[pos][0], 0, last, 0) + C[pos] * E[pos][last];
    FOR(i,1,saw+1) {
        ret = min (ret, solve(V[P[pos]][it+1], saw-i, last, it+1) + solve(V[pos][0], i, last, 0) + C[pos] * E[pos][last]);
        ret = min (ret, solve(V[P[pos]][it+1], saw-i, last, it+1) + solve(V[pos][0], i-1, pos, 0));
    }

    return ret;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("2Rivers.txt","r",stdin);

    LL i, j, k;

    cin >> N >> K;

    for (i=0;i<=N; i++)
        for (j=0; j<=N; j++)
            E[i][j] = i==j ? 0 : INF;

    for (i=1;i<=N;i++) {
        cin >> C[i] >> P[i] >> D[i];
        E[P[i]][i] = D[i];
        E[i][P[i]] = D[i];
        V[P[i]].PB (i);
    }



    for (k=0; k<=N; k++) {
        for (i=0; i<=N; i++) {
            for (j=0; j<=N; j++) {
                E[i][j] = min (E[i][j], E[i][k]+E[k][j]);
            }
        }
    }

    MEM(DP,-1);

    cout << solve(V[0][0],K,0,0) << endl;


    return 0;
}
