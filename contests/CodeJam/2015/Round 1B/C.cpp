/*
ID: Labib666
LANG: C++
Contest: CodeJam R1B
Task: C
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

set <PLL> s;
set <PLL>::iterator it, it2;

double fin[100], speed[100];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("C-small-2-attempt0.in","r",stdin);
    freopen ("C-small-2-attempt0.out","w",stdout);

    LL t, tc = 0, d, h, f, n, l, ans;
    cin >> t;
    while (tc<t) {
        tc++;
        s.clear();

        cin >> n;
        while (n--) {
            cin >> d >> h >> f;
            for (LL i=0; i<h; i++) {
                s.insert(MP(d,f+i));
            }
        }

        l = s.size();

        LL i;
        for (it=s.begin(), i=0; it!=s.end(); it++, i++) {
            speed[i] = 360.0/(double)(*it).Y;
            fin[i] = (360.0-(double)(*it).X) / speed[i];
        }

        ans = INF;
        for (i=0; i<l; i++) {
            LL cnt = 0;
            double tim = fin[i];
            //cout << i << " --> " << tim << endl;

            for (LL j=0; j<l; j++) {
                if (fin[j] > tim) cnt++;
                else {
                    double rem = tim - fin[j];
                    double gr = rem*speed[j];
                    LL rev = (LL) (gr/360.0);
                    cnt += rev;
                }
            }

            ans = min (cnt, ans);
        }

        printf("Case #%lld: %lld\n", tc, ans);

    }


    return 0;
}
