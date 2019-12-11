/*
ID: Labib666
LANG: C++
Contest: COCI R#7
Task: KRIZA
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

LL p[100005], cs[100005], k, n, ans, tot;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    
    cin >> n >> k;
    for (LL i=1; i<=n; i++) {
		int x; cin >> x;
		p[x] = i;
	}
	
	if (n == 1) {
		cout << "0\n";
		return 0;
	}
	
	ans = (p[n]<p[1]) ? p[n]-1 : -(n+1-p[n]);
	cs[1] = (p[n]<p[1]) ? p[1]-p[n] : p[1]+n-p[n];
	
	tot = cs[1];
	for (int i=2; i<=n; i++) {
		tot += (p[i-1]<p[i]) ? p[i]-p[i-1] : p[i]+n-p[i-1];
		cs[i] = (p[i-1]<p[i]) ? p[i]-p[i-1] : p[i]+n-p[i-1];
		cs[i] += cs[i-1];
		//cout << i << " & " << tot << " & " << cs[i] << " " << p[i] <<  endl;
	}
	
	//cout << ans << " " << tot << endl;
	
	ans += (k/n) * tot;
	
	k %= n;
	ans += cs[k];
	
	cout << ans << endl;
	

    return 0;
}
