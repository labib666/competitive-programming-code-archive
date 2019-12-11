/*
ID: Labib666
LANG: C++
Contest: CodeJam R1B
Task: A
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

LL n, t, tc=0, ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt1.out","w",stdout);


    cin >> t;
    while (tc<t) {
        tc++;
        cin >> n;

        ans = 0;

        LL kk = n % 10; if (kk == 0) kk = 10;
        ans += kk - 1; n -= ans;

        stringstream ss1, ss2; char s[20];
        ss1 << n; ss1 >> s;
        reverse(s,s+strlen(s));
        ss2 << s; ss2 >> n;

        while (n != 1) {
            LL tmp;
            for (LL pp = 1; ; pp*=10ll) {
                if (n/pp == 1) {
                    tmp = n % pp; tmp += 9ll;
                    n -= tmp; ans += tmp;
                    break;
                }
            }

            stringstream ss11, ss22; char ss[20];
            ss11 << n; ss11 >> ss;
            reverse(ss,ss+strlen(ss));
            ss22 << ss; ss22 >> n;
        }

        printf("Case #%lld: %lld\n", tc, ans);
    }


    return 0;
}
