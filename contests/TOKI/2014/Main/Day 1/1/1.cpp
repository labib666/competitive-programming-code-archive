/*
ID: Labib Rashid
LANG: C++
TASK: 1
CONTEST: TOKI 2014
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
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

LL C[10004], L[10004], P[10004], LP[10004], N;
PLL S[100005];

LL Q(LL B[10004], LL pos) {
    LL ans = 0;
    while (pos != 0) {
        ans += B[pos];
        pos -= pos&-pos;
    }
    return ans;
}

void U(LL B[10004], LL pos, LL val) {
    while (pos < 10004) {
        B[pos] += val;
        pos += pos&-pos;
    }
    return;
}

int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> N;
    FOR(i,1,N+1)
        cin >> S[i].X >> S[i].Y;
    sort (S+1, S+N+1);

    LL ans = 0;
    FOR(i,1,N+1) {
        ans += (2*Q(C, S[i].Y)-Q(C, 10000)) * S[i].X * S[i].Y;
        ans -= (2*Q(P, S[i].Y)-Q(P, 10000)) * S[i].X;
        ans -= (2*Q(L, S[i].Y)-Q(L, 10000)) * S[i].Y;
        ans += (2*Q(LP, S[i].Y)-Q(LP, 10000));

        cout << ans << endl;

        U (C, S[i].Y, 1);
        U (P, S[i].Y, S[i].Y);
        U (L, S[i].Y, S[i].X);
        U (LP, S[i].Y, S[i].X * S[i].Y);
    }

    cout << ans << endl;


    return 0;
}
