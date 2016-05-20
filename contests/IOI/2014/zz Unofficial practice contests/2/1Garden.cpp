/*
ID: Labib666
LANG: C++
Contest: IOI unofficial contest 2
Task: Garden
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

LL N, K, R, C, G[252][252], RS[252], RE[252], CS[252], CE[252];
priority_queue <PLL> Q1, Q2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("1Garden.txt","r",stdin);

    LL i, j, k, u, v, sum;

    cin >> C >> R;
    cin >> N >> K;


    for (i=0;i<N;i++) {
        cin >> j >> k;
        G[k][j] ++;
    }


    for (j=1; j<=C; j++) {
        for (i=1; i<=R; i++)
            G[i][j] += G[i-1][j];
    }


    for (i=1; i<=R; i++) RS[i] = RE[i] = INF;
    for (i=1; i<=C; i++) CS[i] = CE[i] = INF;

    for (i=1; i<=R; i++) {
        for (j=i; j<=R; j++) {
            u = 1, v = 1, sum = 0;
            for ( ; v <= C; v++) {
                sum += G[j][v]-G[i-1][v];
                while (sum > K || G[j][u]-G[i-1][u] == 0) {
                    sum -= G[j][u]-G[i-1][u];
                    u++;
                }
                if (sum == K) {
                    k = 2*(j-i+1) + 2*(v-u+1);
                    RS[i] = min(k,RS[i]);
                    RE[j] = min(k,RE[j]);
                    CS[u] = min(k,CS[u]);
                    CE[v] = min(k,CE[v]);
                }
            }
        }
    }


    LL ans = INF;
    PLL now;

    for (i=1; i<=R; i++) Q1.push (MP(-RS[i], i));
    for (i=1; i<=C; i++) Q2.push (MP(-CS[i], i));

    for (i=1, j=INF; i<R; i++) {
        j = min (RE[i], j);
        while (Q1.top().Y <= i) Q1.pop();
        ans = min (ans, j-Q1.top().X);
    }

    for (i=1, j=INF; i<C; i++) {
        j = min (CE[i], j);
        while (Q2.top().Y <= i) Q2.pop();
        ans = min (ans, j-Q2.top().X);
    }

    if (ans == INF) cout << "NO\n";
    else cout << ans << endl;

    return 0;
}
