/*
ID: Labib666
LANG: C++
Contest: COCI R#7
Task: PROSJEK (easy)
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

LL n, k, a[300005];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    
    cin >> n >> k;
    for (LL i=1; i<=n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	
	double ans = 0.0;
	for (LL i=1; i<=n; i++) {
		for (LL j=i+k-1; j<=n; j++) {
			double now = a[j]-a[i-1];
			now /= (double)(j-i+1);
			ans = max(ans,now);
		}
	}
	
	printf("%.6lf\n", ans);


    return 0;
}
