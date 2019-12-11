/*
ID: Labib666
LANG: C++
Contest: APIO practice 2015
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

LL gcd (LL a, LL b){return (b > a) ? gcd (b,a) : (b == 0ll) ? a : gcd (b, a%b);}

int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}

LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}
//--------------------------------------------------------------------------------------------------------

LL table[2048], a[2048], n, m, x, y, q;
vector <LL> dv[2048];
LL g[2004][2004];

void getdvs () {
    for (LL i=1; i<=2000; i++) {
        for (LL j=0; j<=2000; j++) {
            if (j%i) continue;
            dv[j].push_back(i);
        }
    } return;
}

void changeval (LL pos, LL val) {
    LL change = val - a[pos];
    a[pos] = val;
    //cout << pos << " div " << dv[pos].size() << endl;
    for (LL i=0; i<dv[pos].size(); i++) {
        LL j = dv[pos][i];
        table[j] += change;
        //if (pos != 0)cout << change << " added to " << j << "\n";
    } return;
}

void changen(LL &oldn, LL &nwn) {
    if (nwn < oldn) {
        for (LL i=nwn; i<oldn; i++) {
            for (LL j=0; j<dv[i].size(); j++) {
                LL k = dv[i][j];
                table[k] -= a[i];
            }
        }
    }
    else {
        for (LL i=oldn; i<nwn; i++) {
            for (LL j=0; j<dv[i].size(); j++) {
                LL k = dv[i][j];
                table[k] += a[i];
            }
        }
    }
    oldn = nwn; return;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);

    getdvs();
    string s1 = "JUMP", s2 = "RESIZE", s;

    for (int i=1; i<=2000; i++) {
        for (int j=1; j<=i; j++) {
            g[i][j] = gcd(i,j);
        }
    }

    cin >> n >> q;

    for (LL i = 0; i < n; i++) {
        cin >> x;
        changeval(i,x);
    }

    while (q--) {
        cin >> s;
        if (s == s1) {
            LL ans = a[0];
            for (LL i=2; i<n-1; i++) {
                LL gg = g[i][n];
                ans = max(ans, table[gg]);
                //cout << g << ".." <<table[g] << " " ;
            }
            cout << ans << endl;
        }
        else if (s == s2) {
            cin >> m;
            changen(n,m);
        }
        else {
            cin >> x >> y;
            changeval(x-1, y);
        }
    }

    return 0;
}
