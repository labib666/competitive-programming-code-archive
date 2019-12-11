/*
ID: Labib Rashid
LANG: C++
TASK:
CONTEST: practise contest 1
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

LL N, K, a[100005], b[100005], c[100005];
LL d[100005], e[100005];
map < LL, LL > m;

void acompress () {
    FOR(i,0,N) b[i] = a[i];
    sort (b,b+N);
    FOR(i,0,N) { if (m.find (b[i]) == m.end()) m[b[i]] = i+1; }
    FOR(i,0,N) a[i] = m[a[i]];
    return;
}

void upd (LL dd[100005], LL pp, LL vl) {
    while (pp <= 100001) {
        dd[pp] += vl;
        pp += pp&-pp;
    }
    return;
}

LL qry (LL dd[100005], LL pp) {
    LL ans = 0;
    while (pp > 0) {
        ans += dd[pp];
        pp -= pp&-pp;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    LL sum, ans;

    cin >> N >> K;
    FOR(i,0,N) cin >> a[i];

    acompress();
    sum = ans = 0;

    FOR(i,0,N) {
        sum += i - qry (d,a[i]);
        upd (d,a[i],1);
    }

    for (LL i=N-1, j=N-1; i>0; i--) {

        sum += qry (e,a[i]-1);
        sum += j+1-qry (d,a[i]);
        upd (e,a[i],1);

        while (j>=i || sum >K) {
            if (j<0) break;
            upd (d,a[j],-1);
            LL now = qry(e,a[j]-1) + j-qry(d,a[j]);
            sum -= now; j--;
        }

        ans += j+1;
    }
    cout << ans << endl;

    return 0;
}
