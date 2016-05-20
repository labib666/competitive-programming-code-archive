/*
ID: Labib666
LANG: C++
Contest: COCI R#7
Task: ACM
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

int a[] = {1,2,3}, p[6][4];
int dp[6][4][200000], d[4][200000];

int solve (int per, int pos, int prob) {
	if (pos == 1) {
		return d[p[per][pos]][prob];
	}
	if (prob == 0) return INF;
	if (dp[per][pos][prob] != -1) return dp[per][pos][prob];
	
	dp[per][pos][prob] = min(solve(per,pos-1,prob-1)+d[p[per][pos-1]][prob]-d[p[per][pos-1]][prob-1], solve(per,pos,prob-1)+d[p[per][pos]][prob]-d[p[per][pos]][prob-1]);
	return dp[per][pos][prob];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    
    int iii = 0;
    do {
		for (int j=1; j<=3; j++) p[iii][j] = a[j-1];
		iii++;
	} while (next_permutation(a,a+3));
	
	int n;
	cin >> n;
	for (int i=1; i<=3; i++) {
		for (int j=1; j<=n; j++) {
			cin >> d[i][j];
			d[i][j] += d[i][j-1];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	
	int ans = INF*2;
	for (int i=0; i<6; i++) {
		//cout << i << " " << p[i][1] << " " << p[i][2] << " " << p[i][3] << " " << solve(i,3,n) << endl;
		ans = min (ans, solve(i,3,n-1)+d[p[i][3]][n]-d[p[i][3]][n-1]);
	}	
	
	cout << ans << endl;


    return 0;
}
