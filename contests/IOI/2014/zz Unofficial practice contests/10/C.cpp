/*
ID: Labib Rashid
LANG: C++
TASK: C
CONTEST: practise contest 2
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

LL T, N1, N2, D, d[100005], e[100005], x, y, ans;
VLL v[100005];
queue <LL> q[3];

LL process (LL pos) {
    if (q[pos].empty()) {
        if (q[pos%2 + 1].empty()) return 1;
        else return 1 + process(pos%2 + 1);
    }
    while (!q[pos].empty()) {
        x = q[pos].front();
        q[pos].pop();
        FOR(i,0,v[x].SZ) {
            y = v[x][i];
            e[y]--;
            if (e[y] == 0) {
                (y>N1) ? q[2].push(y) : q[1].push(y);
            }
        }
    }
    return 1+process(pos%2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    while (1) {
        scanf ("%lld %lld %lld" , &N1, &N2, &D);
        if (D+N1+N2 == 0) break;

        fill (d+1,d+N1+N2+1, 0);
        FOR(i,1,N1+N2+1) v[i].clear();

        FOR(i,0,D) {
            scanf ("%lld %lld", &x, &y);
            d[x]++;
            v[y].PB (x);
        }

        ans = LINF;

        FOR(i,1,3) {
            FOR(j,1,N1+N2+1) {
                e[j] = d[j];
                if (e[j] == 0) {
                    if (j > N1) q[2].push (j);
                    else q[1].push (j);
                }
            }
            ans = min (ans, process(i));
        }
        printf("%lld\n", ans);
    }

    return 0;
}
