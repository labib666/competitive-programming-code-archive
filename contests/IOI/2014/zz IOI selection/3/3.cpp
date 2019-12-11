/*
ID: Labib666
LANG: C++
Contest: IOI TST 3
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
int bitcount (LL a) {return (a != 0ll) ? bitcount(a & (a-1ll)) + 1ll : 0ll;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (num%2ll) ans = (ans*num)%prime; return ans;
}



int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("3.txt","r",stdin);

    LL T, N, M, P;
    VLL V;
    VLL ::iterator it;

    scanf ("%lld", &T);

    while (T--) {
        V.clear();
        scanf("%lld", &N);

        for (LL i=60; i>=0; i--) {
            if (N&(1ll<<i)) {
                M = i;
                break;
            }
        }

        P = M;
        P += bitcount(N);

        LL i, j, k;
        for( i=P, j=1; j<=M; j++,i--)
            V.PB (i);

        for ( j=0, i=2, k=0; k <V.SZ;k++, j++, it++) {
            if ((N&(1ll<<j)) == 0) continue;
            V.insert (V.begin()+k, i);
            i++; k++;
        }

        reverse (V.begin(), V.end());
        V.PB (1ll);

        printf ("%lld\n", (LL)V.size());
        for (i = 0; i<V.size(); i++) printf ("%lld\n", V[i]);
    }

    return 0;
}
