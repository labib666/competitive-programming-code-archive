/*
ID: Labib Rashid
LANG: C++
TASK: 3POI
CONTEST: IOI 2009 (IOI14 practice)
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

struct data {
    LL pp, ss, id;
    bool operator < (const data &b) const {
        if (MP (pp, ss) == MP (b.pp, b.ss)) return id < b.id;
        return MP (pp, ss) > MP (b.pp, b.ss);
    }
};

LL N, T, P[2002], M;
bool S[2002][2002];
data D[2002];

int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> T >> M;

    fill (P+1, P+1+T, N);

    FOR (i,1,N+1) {
        D[i].ss = 0, D[i].pp = 0, D[i].id = i;
        FOR (j,1,T+1) {
            LL kk; cin >> kk;
            if ( kk ) {
                    S[i][j] = 1;
                    P[j]--;
            }
        }
    }

    FOR (i,1,N+1) {
        FOR (j,1,T+1) {
            if ( S[i][j] ) {
                    D[i].ss ++;
                    D[i].pp += P[j];
            }
        }
    }

    sort (D+1,D+1+N);

    LL ans;
    FOR(i,1,N+1) {
        if (D[i].id == M) { ans = i; break; }
    }

    cout << D[ans].pp << " " << ans << endl;

    return 0;
}
