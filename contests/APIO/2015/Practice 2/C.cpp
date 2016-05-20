/*
ID: Labib666
LANG: C++
Contest: COCI mock 2
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

LL n, k, par[128], c[128][2], u, v, t, root;
string s; set <string> ss;

void simulate (LL now, string pp) {
    if (now == 0) {
        ss.insert(pp);
        return;
    }
    pp += " ";
    for (LL i=1; i<=n; i++) {
        if ( now&(1ll<<i) ) {
            LL cur = (now ^ (1ll<<i));
            if (c[i][0] != -1) cur |= (1ll<<c[i][0]);
            if (c[i][1] != -1) cur |= (1ll<<c[i][1]);
            char ch = ('0'+i);
            string ns = pp+ch;
            simulate(cur,ns);
        }
    }
    return;
}

void sp1 (LL pos) {
    if (pos != root) cout << " ";
    cout << pos;
    if (c[pos][0] != -1) sp1(c[pos][0]);
    if (c[pos][1] != -1) sp1(c[pos][1]);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    memset(par, -1, sizeof(par));
    memset(c, -1, sizeof(c));

    cin >> s >> n >> k;
    for (LL i=0; i<n-1; i++) {
        cin >> u >> v >> t;
        par[v] = u;
        c[u][t] = v;
    }

    for (LL i=1; i<=n; i++) {
        if (par[i] == -1) { root = i; break; }
    }

    if (n <= 100 && k==1) {
        sp1(root);
        cout << endl;
    }

    else if (n <= 8) {
        LL now = 0;
        now |= (1ll<<root); char ch = ('0'+root);
        string str = "";
        simulate(now,str);

        now = 1;
        for (set<string>::iterator it=ss.begin(); it != ss.end(); it++) {
            if (now == k) { cout << (*it).substr(1) << endl; break; }
            now++;
        }
    }


    return 0;
}
