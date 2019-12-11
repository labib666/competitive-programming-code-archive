/*
ID: Labib Rashid
LANG: C++
TASK: 1
CONTEST: CodeJam 2014 R2
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

int a[10002];

int main()
{
    //freopen ("input.txt","r",stdin);
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.txt","w",stdout);

    int t, tc=0, n, x, i, j, k, ans;

    cin >> t;
    while (tc<t) {
        tc++;
        cin >> n >> x;
        FOR(ii,0,n) cin >> a[ii];
        ans = 0;

        sort (a,a+n);
        for (i=0,j=n-1; i<j; i++) {
            for (; i<j; j--) {
                if (a[i]+a[j] <= x) break;
            }
            if (j > i) { ans++; j--; }
            else break;
        }
        //cout << ans << endl;
        ans += (n-2*ans);
        printf ("Case #%d: %d\n", tc, ans);
    }




    return 0;
}
