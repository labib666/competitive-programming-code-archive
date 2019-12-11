/*
ID: Labib666
LANG: C++
Contest: COCI R#7
Task: TETA
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

int p[25], c[25], m[5], vis[25];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    
    int n, k, P, mx = 0;
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> p[i];
    
    cin >> P;
    cin >> m[0] >> m[1] >> m[2] >> m[3];
    for (int i=0; i<4; i++) {
		vis[m[i]] = 1;
		mx = max (mx, m[i]);
	}
    
    cin >> k;
    for (int i=0; i<k; i++) {
		int x; cin >> x;
		c[x]++;
	}
	
	int tot = 0;
	for (int i=1; i<=n; i++) {
		if (vis[i]) continue;
		tot += p[i]*c[i];
	}
	//cout << "tot = " << tot << endl;
	
	int add = INF;
	for (int i=0; i<=mx; i++) {
		int now = P*i;
		for (int j=0; j<4; j++) {
			now += p[m[j]] * ( max( 0, c[m[j]] - i ) );
		}
		add = min (add, now);
	}
	//cout << "tot = " << tot << " + " << add << endl;
	tot += add;
	
	cout << tot << endl;


    return 0;
}
