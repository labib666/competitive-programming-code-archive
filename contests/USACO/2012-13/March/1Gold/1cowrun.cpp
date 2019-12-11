/*
ID: Labib Rashid
LANG: C++
TASK: cowrun
CONTEST: USACO MAR13 GOLD
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

LL N, d[1002], f[1002], b[1002], dp[1002][1002], pp;

LL solve (LL pos, LL next, LL left) {

    if (next == N+1) return b[pos];
    if (next == -1) return f[pos];

    LL &rt = dp[pos][next];
    if (rt != -1) return rt;

    rt = LINF;

    if (d[pos] > d[next]) {
        if (pos != N) rt = min ( rt, solve (pos+1, next, left-1) + left*(d[pos+1]-d[pos]) );
        rt = min ( rt, solve (next, pos+1, left-1) + left*(d[pos]-d[next]) );
    }
    else {
        if (pos != 0) rt = min ( rt, solve (pos-1, next, left-1) + left*(d[pos]-d[pos-1]) );
        rt = min ( rt, solve (next, pos-1, left-1) + left*(-d[pos]+d[next]) );
    }
    return rt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> N;

    FOR(i,1,N+1) cin >> d[i];
    d[0] = 0;

    sort (d,d+1+N);
    FOR(i,0,N+1) { if (d[i] == 0) { pp = i; break; } }
    b[0] = 0; FOR(i,1,pp+1) { b[i] = b[i-1] + (d[i]-d[i-1]) * i;  }
    f[N] = 0; for (LL i=N-1; i>=pp; i--) { f[i] = f[i+1] + (d[i+1]-d[i]) * (N-i); }

    MEM(dp, -1);

    cout << solve(pp, pp-1, N) << endl;

    return 0;
}
