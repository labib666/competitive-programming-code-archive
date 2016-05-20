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

int mov[1000006];
int n, t, tc=0;
queue <PII> q;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt0.out","w",stdout);

    memset(mov, -1, sizeof(mov));
    q.push(MP(1,1));

    while(!q.empty()) {
        PII now = q.front();
        q.pop();

        if (now.X > 1000000 || now.X == 0) continue;
        if (mov[now.X] != -1) continue;
        mov[now.X] = now.Y;

        q.push(MP(now.X+1, now.Y+1));
        stringstream ss;
        ss << now.X;
        char s[10]; ss >> s;
        reverse(s,s+strlen(s));
        stringstream ss2; ss2 << s;
        int cur; ss2 >> cur;
        q.push(MP(cur, now.Y+1));
    }

    //for (int i=101; i<=1000; i++) cout << i << " " << mov[i] << endl;

    cin >> t;
    while (tc<t) {
        tc++;
        cin >> n;
        printf("Case #%d: %d\n", tc, mov[n]);
    }


    return 0;
}
