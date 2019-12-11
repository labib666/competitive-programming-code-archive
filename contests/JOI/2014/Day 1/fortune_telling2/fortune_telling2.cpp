/*
ID: Labib Rashid
LANG: C++
TASK: fortune_telling2
CONTEST: JOI
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

LL N, K, a[200005], b[200005], xx, ans;
VLL t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",sth din);
    //freopen (".out","w",stdout);

    cin >> N >> K;
    FOR(i,0,N) {
        cin >> a[i] >> b[i];
    }
    FOR(i,0,K) {
        cin >> xx;
        t.PB (xx);
    }

    ans = 0;

    FOR(i,0,N) {
        LL now = 0;
        FOR(j,0,K) {
            LL vl = (now%2==0) ? a[i] : b[i];
            if (vl <= t[j]) now++;
        }
        ans += (now%2 == 0) ? a[i] : b[i];
    }

    cout << ans << endl;



    return 0;
}
