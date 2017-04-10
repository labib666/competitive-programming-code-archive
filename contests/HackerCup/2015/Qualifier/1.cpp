/*
ID: Labib666
LANG: C++
Contest: Facebook Hacker Cup 2015
Task: 1 ( 15 pts )
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

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen ("cooking_the_books.txt","r",stdin);
    freopen ("fin.txt","w",stdout);

    int t, tc = 0, n, num, sz;
    string s;
    VI v;

    scanf ("%d", &t);
    while (tc<t) {

        tc++;

        scanf("%d", &n);
        v.clear();

        if (n == 0) {
            printf("Case #%d: 0 0\n", tc);
            continue;
        }

        stringstream ss1;
        ss1 << n;
        ss1 >> s;

        sz = s.SZ;

        for(int i=0; i<sz; i++) {
            if (s[i] == '0') continue;

            swap(s[0],s[i]);
            stringstream ss2;

            ss2 << s;
            ss2 >> num;

            v.PB (num);
            swap(s[0],s[i]);
        }

        sort ALL(v);
        printf("Case #%d: %d %d\n", tc, v[0], v[(int)v.SZ-1]);
    }


    return 0;
}
