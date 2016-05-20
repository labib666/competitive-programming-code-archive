/*
ID: Labib666
LANG: C++
Contest: CodeJam R1B
Task: B
*/

#include <bits/stdc++.h>

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

#define MAXN

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

int n, r, c;
int a[30][30], XX[] = {0,0,-1,1}, YY[]={1,-1,0,0};


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("B-small-attempt0.in","r",stdin);
    freopen ("B-small-attempt0.out","w",stdout);
    int t, tc=0;
    cin >> t;
    while (tc<t) {
        tc++;
        cin >> r >> c >> n;
        int ans = INF;

        for (int i=0; i<(1<<(r*c)); i++) {
            if (bitcount(i) != n) continue;

            memset(a, 0, sizeof(a));
            for (int j=0; j<r; j++) {
                for (int k=0; k<c; k++) {
                    int now = j*c + k;
                    if (i&(1<<now)) a[j][k] = 1;
                }
            }
            int cnt = 0;
            for (int j=0; j<r; j++) {
                for (int k=0; k<c; k++) {
                    if (a[j][k] == 0) continue;
                    for (int nn=0; nn<4; nn++) {
                        int nx = j+XX[nn], ny = k+YY[nn];
                        if (nx < 0 || nx >= r) continue;
                        if (ny < 0 || ny >= c) continue;
                        if (a[nx][ny] == 1) cnt++;
                    }
                }
            }

            ans = min (cnt/2, ans);
        }

        printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}
