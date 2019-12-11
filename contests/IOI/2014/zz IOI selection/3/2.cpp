/*
ID: Labib666
LANG: C++
Contest: IOI TST 3
Task: 2
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

LL N, D, A[32], Ans;
LL DP[32][32][128][128];

LL solve (LL pos, LL dif, LL ox, LL ex) {

    if (dif < 0ll || dif > 30ll) return 0ll;
    if (pos == N) return ((dif == 15ll || dif == 16ll)&&abs(ox-ex)<=D) ? 1ll : 0ll;

    LL &ret = DP[pos][dif][ox][ex];
    if (ret != -1ll) return ret;

    ret = solve(pos+1, dif, ox, ex);
    ret = (ret + solve(pos+1ll, dif+1ll, ox^A[pos], ex)) % INF;
    ret = (ret + solve(pos+1ll, dif-1ll, ox, ex^A[pos])) % INF;

    return ret;

}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("2.txt","r",stdin);

    scanf ("%lld%lld", &N,&D);

    REP(i,N)
        scanf ("%lld", &A[i]);

    MEM(DP,-1ll);
    Ans = solve(0ll,15ll,0ll,0ll);
    if (Ans == 0ll) Ans = INF;

    printf ("%lld\n", Ans-1);

    return 0;
}
