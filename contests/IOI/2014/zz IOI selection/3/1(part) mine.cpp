/*
ID: Labib666
LANG: C++
Contest: IOI TST 3
Task: 1
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
    if (num%2ll) ans = (ans*num)%prime; return ans;
}

#define MAXN 100005
PLL B[MAXN];
LL  N;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("1.txt","r",stdin);

    LL T;

    scanf ("%lld", &T);
    while (T--) {
        scanf ("%lld", &N);

        FOR (i,1,N+1)
            scanf ("%lld%lld", &B[i].X,&B[i].Y);

        sort (B+1, B+N+1);

        LL ans = N;
        FOR(i,1,N+1) {
            PLL now = MP(B[i].X-B[i].Y,B[i].X+B[i].Y), fin = MP(B[i].X,B[i].X);
            LL l = i, r = i;
            while (now != fin) {
                fin = now;
                for (LL j=l-1; ; j--) {
                    if (j <= 0) {l = 1; break;}
                    if (B[j].X < fin.X) {l = j+1; break;}
                    now.X = min(now.X, B[j].X-B[j].Y);
                    now.Y = max(now.Y, B[j].X+B[j].Y);
                }
                for (LL j=r+1; ; j++) {
                    if (j > N) {r = N; break;}
                    if (B[j].X > fin.Y) {r = j-1; break;}
                    now.X = min(now.X, B[j].X-B[j].Y);
                    now.Y = max(now.Y, B[j].X+B[j].Y);
                }
                //cout << i << " " << l << " " << r << endl;
            }
            ans = min (ans, r-l+1);
        }
        printf ("%lld\n", ans);
    }


    return 0;
}
