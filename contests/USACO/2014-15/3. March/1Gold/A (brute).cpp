/*
ID: Labib666
LANG: C++
Contest: USACO FEB15
Task: hopscotch
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
#define INF 1000000007ll
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

LL dp[1002][1002], c[1002][1002];

LL solve (LL x, LL y) {
	//cout << x << " " << y << endl;
	
	if (x == 0ll) {
		if (y != 0ll) return 0ll;
		else return 1ll;
	}
	if (y == 0ll) {
		if (x != 0ll) return 0ll;
		else return 1ll;
	}
	if (x == 1ll || y == 1ll) {
		if (c[x][y] == c[0][0]) return 0ll;
		else return 1ll;
	}
	if (dp[x][y] != -1ll) return dp[x][y];
	
	dp[x][y] = 0ll;
	for (LL i=x-1ll; i>=0ll; i--) {
		for (LL j=y-1ll; j>=0ll; j--) {
			if (c[i][j] == c[x][y]) continue;
			dp[x][y] += solve(i,j);
			dp[x][y] %= INF;
		}
	}
	return dp[x][y];
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    //freopen ("test.txt","r",stdin);
    freopen ("hopscotch.in","r",stdin);
    freopen ("hopscotch.out","w",stdout);
    
    memset (dp, -1, sizeof(dp));
    
    LL n, m, k;
    
    cin >> n >> m >> k;
    
    for (LL i=0; i<n; i++) {
		for (LL j=0; j<m; j++) {
			cin >> c[i][j];
		}
		reverse (c[i], c[i]+m);
	}
	for (LL kk=0; kk<m; kk++) {
		for (LL i=0, j=n-1; i<j; i++, j--) {
			swap (c[i][kk], c[j][kk]);
		}
	}
	
	/*
	for (LL i=0; i<n; i++) {
		for (LL j=0; j<m; j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	cout << solve (n-1, m-1) << endl;
	
	/* 
	for (LL i=0; i<n; i++) {
		for (LL j=0; j<m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/


    return 0;
}
