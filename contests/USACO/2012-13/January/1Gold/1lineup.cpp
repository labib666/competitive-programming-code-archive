/*
ID: Labib Rashid
LANG: C++
TASK: lineup
CONTEST: USACO JAN13 GOLD
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
#define LINF 1000000000000000007
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
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

LL N, K, cnt;
LL a[100005], b[100005], c[100005], p[100005];
map <LL,LL> m;
queue <LL> q[100005];

void U (LL pos, LL vl) {
    if (pos == 0) { b[pos]--; return; }
    while (pos <= N) {
        b[pos] += vl;
        pos += pos&-pos;
    }
    return;
}

LL Q (LL pos) {
    LL ans = 0;
    while (pos > 0) {
        ans += b[pos];
        pos -= pos & -pos;
    }
    ans += b[0];
    return ans;
}

void cmprs () {
    FOR(i,1,N+1) c[i] = a[i];
    sort(c+1,c+N+1);
    FOR(i,1,N+1) {
        if (m.find(c[i]) == m.end()) {
            m[c[i]] = i; cnt++;
        }
    }
    FOR(i,1,N+1) a[i] = m[a[i]];
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> N >> K;
    cnt = 0;

    FOR(i,1,N+1) cin >> a[i];
    cmprs(); b[0] = cnt;


    LL ans = 1;
    FOR(i,1,N+1) {
        LL k = p[a[i]];
        p[a[i]] = i; q[a[i]].push(i);
        U(k,-1); U(i,1);
        while (1) {
            k = q[a[i]].front();
            LL vv = Q(k-1);
            if (cnt-vv > K+1) {
                q[a[i]].pop(); continue;
            }
            ans = max(ans, (LL)q[a[i]].SZ);
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
